#ifndef JUGADOR_H 
#define JUGADOR_H

#include "Tablero.h"

class Jugador{
    
    public:
        int puntos;
        int id;
        Tablero* mesa;
        
        Jugador(int id_, Tablero* mesa_);
        bool emparejar();
        void turno();
    
};


#endif