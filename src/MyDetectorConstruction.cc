/*
 * Nicolas Guarin
 * Sevicio Geologico Colombiano
*/


#include "G4Box.hh"
#include "globals.hh"          //G4int, G4double, G4bool, etc...
#include "G4SystemOfUnits.hh"  //meters, ...
#include "G4ThreeVector.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4PVReplica.hh"
#include "G4PVPlacement.hh"
#include "G4LogicalVolume.hh"
#include "MyDetectorConstruction.hh"


MyDetectorConstruction::MyDetectorConstruction()
  :G4VUserDetectorConstruction()
{
  DefineMaterials();
}

MyDetectorConstruction::~MyDetectorConstruction()
{}



void MyDetectorConstruction::DefineMaterials()
{
  // Material del NIST
  G4NistManager* nist = G4NistManager::Instance();
  mWater = nist->FindOrBuildMaterial("G4_WATER");
  mAir = nist->FindOrBuildMaterial("G4_AIR");
}

G4VPhysicalVolume* MyDetectorConstruction::Construct()
{

  /* ***************
     **** WORLD ****
     ***************
     */
  
  // 1. Choose a Solid
  // Geometrical Volume =====================================================================
  // World

  G4double world_x = 500*cm;
  G4double world_y = 100*cm;
  G4double world_z = 100*cm;

  G4Box* const solidWorld =
    new G4Box("World",  world_x/2., world_y/2., world_z/2.);   //(name, half_size)
  /* This creates a box named “World” with 
     Xsize: 500 cm           Ysize: 100 cm          Zsize: 100 cm */

  
  // 2. Create a Logical Volume: aquí se escoge el material
  // Logical Volume =========================================================================
  // World
  G4LogicalVolume* const logicWorld =
    new G4LogicalVolume(solidWorld, mAir, solidWorld->GetName());
  //solidWorld->GetName() de la variable solidWorld, traiga el nombre 
  

  // 3. Place a Volume -> Create a Physical Volume
  // Logical Volume =========================================================================
  // World
  G4VPhysicalVolume* const physicalWorld =
    new G4PVPlacement(0,                          // MUST be unrotated
		      G4ThreeVector(),            // MUST be at origin: Este es el vector (0,0,0)
		      logicWorld,                 // the logical volume
		      logicWorld->GetName(),      // the name
		      NULL,                       // NO mother volume: El mundo es la madre
		      false,                      // no boolean operations
		      0);                         // copy number

  /* So the location of the world is
  X:( -250 , 250) cm     Y:( -50 , 50) cm     Z:( -50 , 50) cm */
  
  // General Attributes
  //logicWorld -> SetVisAttributes(G4VisAttributes::Invisible);






  /* ***************
     **** LAYER ****
     ***************
     */

  
  // Geometrical Volume =====================================================================
  // Layer
  G4int nReplicas = 50; 
  G4double layer_dx = world_x/nReplicas;   // 500/50 = 10 cm
  G4double layer_y= world_y, layer_z=world_z;
  
  G4Box* layer_geo =
    new G4Box( "layer_geo" , layer_dx/2. , layer_y/2., layer_z/2.);
  /* This creates a box named “Layer” with 
     Xsize: 10 cm        Ysize: 100 cm        Zsize: 100 cm */

  // Logical Volume ==========================================================================
  // Layer
  G4LogicalVolume* layer_log =
    new G4LogicalVolume(layer_geo, mWater, "layer_log");

  // Replica Volume  =========================================================================
  // Layer
  
  // Para poner UNA sola capa en el centro
  /*new G4PVPlacement(0,                  		 //no rotation
		    G4ThreeVector(),		         //at (0,0,0)
		    layer_log,			         //its logical volume
		    "layer_phys",			 //its name
		    logicWorld,         	         //its mother  volume
		    false,			         //no boolean operation
		    0,			    	         //copy number
		    true);			         //overlaps checking*/
  
  
  new G4PVReplica( "X_Slices",                        // pName
		   layer_log,                         // pCurrentLogical
		   logicWorld,                        // pMotherLogical
		   kXAxis,                            // pAxis
		   nReplicas,                         // nReplicas
		   layer_dx,                          // width
		   0);                                // offset

  /* The coordinate system of the replicas is at the centre of each replica for the Cartesian axis
     n = 0 , X = -245 cm; n = 1 , X = -235 cm)
     En general (-width*(nReplicas-1)*0.5 + n*width, 0, 0) */


  
  //always return the physical World
  //
  return physicalWorld;
}
