/*
 * Nicolas Guarin
 * Sevicio Geologico Colombiano
 */

#include "G4Types.hh"

// Mandatory
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif
// Other Geant4 headers
#include "G4UImanager.hh"    
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

// these lines specify the detector geometry, physics processes and primary particle, respectively
#include "MyDetectorConstruction.hh"
//#include "QBBC.hh"
#include "MyPhysicsList.hh"
#include "MyActionInitialization.hh"

// ***** MAIN ***** //
// main(Cantidad de argumentos, arreglo string de argumentos)
int main(int argc,char** argv) {



  
  //detect interactive mode (if no arguments) and define UI session
  //
  G4UIExecutive* ui = nullptr;
  if (argc == 1) ui = new G4UIExecutive(argc,argv);




  // Construct an instance of the G4RunManager class.
  // It controls the flow of the program and manages the event loop(s) within a run.
#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
  runManager->SetNumberOfThreads(G4Threading::G4GetNumberOfCores());
#else
  G4RunManager* runManager = new G4RunManager;
#endif



  
  // set mandatory initialization classes and pass their pointers to the run manager
  //
  // Detector construction  
  runManager->SetUserInitialization(new MyDetectorConstruction);
  // Physics list
  runManager->SetUserInitialization(new MyPhysicsList);
  //runManager->SetUserInitialization(new QBBC());
  // User action initialization
  runManager->SetUserInitialization(new MyActionInitialization);

/* Otra forma
DetectorConstruction* det = new DetectorConstruction;
 runManager->SetUserInitialization(det);
PhysicsList* phys = new PhysicsList;  
 runManager->SetUserInitialization(phys);
runManager->SetUserInitialization(new ActionInitialization(det)); */

  //initialize visualization, not sure if needed?
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  //get the pointer to the User Interface manager // Mandatory
  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  

  
/* initialize G4 kernel: performs the detector construction, creates the physics processes,
   calculates cross sections and otherwise sets up the run. 
   runManager->Initialize(); */

  // interactive mode : define UI session and/or visualization
  //
  if ( ui ) {
    // interactive mode
    UImanager->ApplyCommand("/control/execute mac/vis.mac");
    ui->SessionStart();
    delete ui;
  }
  else {
    // batch mode 
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  
  // job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not be deleted
  // in the main() program !
  
  delete visManager;
  delete runManager;
  return 0;
}
