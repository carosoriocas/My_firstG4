/*
 * Nicolas Guarin
 * Sevicio Geologico Colombiano
*/

#ifndef MyPrimaryGeneratorAction_h
#define MyPrimaryGeneratorAction_h 1

// Geant4 Headers
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;

class MyPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
	MyPrimaryGeneratorAction();
	virtual ~MyPrimaryGeneratorAction();

	// method from the base class
	virtual void GeneratePrimaries(G4Event*);

private:
	G4ParticleGun*  fParticleGun; // pointer a to G4 gun class

};


#endif 
