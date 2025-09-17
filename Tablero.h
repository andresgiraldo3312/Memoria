#ifndef TABLERO_H 
#define TABLERO_H

#include "Carta.h"

class Tablero{
    
    public:
        int n;
        int cartasRetiradas;
        Carta Cartas[24];
        
        Tablero();
        void barajar();
        void voltear(int id);
        void retirar(int id);
        void mostrar();
    
};


#endif
