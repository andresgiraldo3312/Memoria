#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include "Carta.h"

const char* Carta::paleta[12] = {
    BG_BLACK, BG_RED, BG_GREEN, BG_AMARILLO, BG_BLUE, BG_MAGENTA,
    BG_CYAN, BG_NARANJA, BG_LBLUE, BG_LGREEN, BG_GRAY, BG_ROSE
};


bool Carta::operator==(const Carta& otro){
    
    return(this->color==otro.color);
    
}


Carta::Carta(){
    
    this->color = 0;
    this->id = 0;
    this->estado = 0;
    
}

Carta::Carta(int color){
    
    this->color = color;
    this->id = 0;
    this->estado = 0;
    
}

void Carta::voltear(){
    
    if(estado == 0){
        
        estado = 1;
        
    }else{
        
        if(estado == 1){
            estado = 0;
        }
    }
    
}

void Carta::retirar(){
    
    estado = 2;
    
}

void Carta::mostrar(){
    
    if(estado == 0){
        
        if(id > 9){
            cout  <<  id <<  RESET << " ";    
        }else{
            cout  <<  " " << id <<  RESET << " ";    
        }
        
    }
    
    if(estado == 1){
        cout << paleta[color] << "  " <<  RESET << " ";
    }
    
    if(estado == 2){
        cout << "   ";
    }
    
}

bool Carta::comparar(Carta acomparar){
    
    return (color==acomparar.color);
    
}
