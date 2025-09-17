#include "Tablero.h"


Tablero::Tablero(){
    
    int indice = 0;
    n = 24;
    cartasRetiradas = 0;
    
    for(int i = 0; i < 12; i++){

        Cartas[2*i].color = i;
        Cartas[(2*i)+1].color = i;

    }
    
    
}

void Tablero::mostrar(){
    
    system("clear");
    
    for(int i = 0; i < 4; i++){
        
        for(int j = 0; j < 6; j++){

            Cartas[(i*6)+j].mostrar();
            
        }
        
        cout << endl << endl;
        
    }
    
}

void Tablero::barajar(){
    
    Carta temp;
    int indUno;
    int indDos;
    
    for(int i = 0; i < 50; i++){
        
        indUno = rand()%24;
        indDos = rand()%24;
        
        temp = Cartas[indUno];
        Cartas[indUno] = Cartas[indDos];
        Cartas[indDos] = temp;
        
    }
    
    for(int i = 0; i < 24; i++){

        Cartas[i].id = i+1;
        
    }
}


void Tablero::voltear(int id){
    
    Cartas[id-1].voltear();
    
}

void Tablero::retirar(int id){
    
    if(Cartas[id-1].estado != 2){
        Cartas[id-1].retirar();
        cartasRetiradas++;
    }
    
}
 
