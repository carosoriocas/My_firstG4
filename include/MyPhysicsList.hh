/*
 * Nicolas Guarin
 * Sevicio Geologico Colombiano
*/



#ifndef MyPhysicsList_h
#define MyPhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"


/// Physics list with geantino and charged geantino only

class MyPhysicsList: public G4VModularPhysicsList
{
  public:
    MyPhysicsList();
    ~MyPhysicsList();

};

#endif
