/*
 * Nicolas Guarin
 * Sevicio Geologico Colombiano
*/


#include "MyPrimaryGeneratorAction.hh"

#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

//#include "G4Event.hh"
//#include "G4ParticleGun.hh"
//#include "G4ParticleDefinition.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyPrimaryGeneratorAction::MyPrimaryGeneratorAction()
  :G4VUserPrimaryGeneratorAction(),fParticleGun(0)
{
   
  G4int n_Particles = 1;
  fParticleGun = new G4ParticleGun(n_Particles);

  // Define Particle
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  const G4String particleName = "gamma";
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName);
  fParticleGun->SetParticleDefinition(particle);
  
  // default particle kinematic
  G4double energy = 6*MeV;
  G4ThreeVector position = G4ThreeVector(-250*cm,0.,0.);
  G4ThreeVector momentumDirection = G4ThreeVector(1.,0.,0.);
  fParticleGun->SetParticlePosition(position);
  fParticleGun->SetParticleMomentumDirection(momentumDirection);
  fParticleGun->SetParticleEnergy(energy);
}

MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction()
{
  delete fParticleGun;
}

void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  fParticleGun->GeneratePrimaryVertex(anEvent);
}

