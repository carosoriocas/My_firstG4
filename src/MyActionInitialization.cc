/*
 * Nicolas Guarin
 * Sevicio Geologico Colombiano
*/


#include "MyActionInitialization.hh"
#include "MyPrimaryGeneratorAction.hh"

/*
#include "MyRunAction.hh"
#include "MyEventAction.hh"
#include "MyStackingAction.hh"
#include "MyTrackingAction.hh"
#include "MySteppingAction.hh"
*/

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyActionInitialization::MyActionInitialization()
 : G4VUserActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::BuildForMaster() const
{}

void MyActionInitialization::Build() const
{
  MyPrimaryGeneratorAction* primary = new MyPrimaryGeneratorAction();
  SetUserAction(primary);

  /*

  MyRunAction* runAction = new MyRunAction();
  SetUserAction(runAction);
  
  MyEventAction* eventAction = new MyEventAction();
  SetUserAction(eventAction);

  MyStackingAction* stackingAction = new MyStackingAction();
  SetUserAction(stackingAction);

  MyTrackingAction* trackingAction = new MyTrackingAction();
  SetUserAction(trackingAction);

  MySteppingAction* steppingAction = new MySteppingAction();
  SetUserAction(steppingAction);
  
  */

}

