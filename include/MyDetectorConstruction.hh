/*
 * Nicolas Guarin
 * Sevicio Geologico Colombiano
*/


#ifndef MyDetectorConstruction_h
#define MyDetectorConstruction_h 1

// Geant4 Headers
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4Material.hh"


/// Detector construction class to define materials and geometry.

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
    MyDetectorConstruction();
    virtual ~MyDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

    

  private:

    // *** Materials ***
    //
    G4Material* mAir;
    G4Material* mWater;
  
    void DefineMaterials();
  
};

#endif 
