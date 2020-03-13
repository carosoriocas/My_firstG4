/*
 * Nicolas Guarin
 * Sevicio Geologico Colombiano
*/

#include "MyPhysicsList.hh"

//Models
#include "G4EmPenelopePhysics.hh"
//#include "G4EmStandardPhysics.hh"
//#include "G4EmLivermorePhysics.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyPhysicsList::MyPhysicsList()
  : G4VModularPhysicsList()
{
  G4int verb = 1;
  SetVerboseLevel(verb);

  // EM Physics
  RegisterPhysics( new G4EmPenelopePhysics(verb) );
  // RegisterPhysics( new G4EmStandardPhysics(ver) );
  // RegisterPhysics( new G4EmLivermorePhysics(verb) );
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyPhysicsList::~MyPhysicsList()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


