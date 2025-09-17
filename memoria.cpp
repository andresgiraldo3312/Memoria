
#include "Carta.h"
#include "Tablero.h"
#include "Jugador.h"

int main(){
    
/*
    srand(time(NULL));
    
    
    Tablero baraja;
    baraja.barajar();
    
    char Buffer[sizeof(baraja)];
    
    
    
    baraja.voltear(13);
    baraja.voltear(14);
    
    //baraja.mostrar();
    
    memcpy(&Buffer, &baraja, sizeof(baraja));
    
    ofstream archivoUno("Tablero.txt", ios::binary);    
    
    archivoUno.write(Buffer, sizeof(Buffer));
    
    archivoUno.close();
    
    cout << "Tablero uno" << endl;
    baraja.mostrar();
    
  
    //---------------------------------------------
    
    
  
    Tablero barajaDos;
    //char Buffer[sizeof(Tablero)];
        
    //ifstream archivoEntrada("Tablero.txt");
    ifstream archivoDos("Tablero.txt", ios::binary);
    
    
    
    archivoDos.read(Buffer, sizeof(Buffer));
    
    memcpy(&barajaDos, &Buffer, sizeof(barajaDos));
    
    archivoDos.close();
    
    cout << "Tablero Dos" << endl;
    barajaDos.mostrar();
    
    
    //---------------------------------------------
    
    
    
    /*
    srand(time(NULL));
    
    
    Tablero baraja;
    baraja.barajar();
    
    char Buffer[sizeof(baraja)];
    
    memcpy(&Buffer, &baraja, sizeof(baraja));
    
    
    baraja.voltear(8);
    baraja.voltear(7);
    baraja.voltear(10);
    
    baraja.mostrar();
    
    ofstream archivoSalida("Tablero.txt");
    
    for(int i=0; i<sizeof(baraja); i++){
        
       archivoSalida << Buffer[i]; 
    }
    
    archivoSalida.close();
    
    */

  
    
    /*
    Tablero barajaDos;
    
    memcpy(&barajaDos, &Buffer, sizeof(baraja));
    
    barajaDos.mostrar();
    
    barajaDos.voltear(6);
    barajaDos.mostrar();
    
    */
    

    
    
    srand(time(NULL));
    
    
    Tablero baraja;
    
    baraja.barajar();
    
    baraja.mostrar();
    
    vector<Jugador> Jugadores;
    
    for(int i = 0; i<3; i++){
        
        Jugador temp(i+1, &baraja);
        Jugadores.push_back(temp);
        
    }
    
    cout << endl;
    
    while( baraja.cartasRetiradas < 24 ){
        for(int i = 0; i<3; i++){
            
        Jugadores[i].turno();    
            
        }
        //Uno.turno();
        //Dos.turno();
    }
    
    //cout << "Puntajes de jugador 1: " << Uno.puntos << endl;
    //cout << "Puntajes de jugador 2: " << Dos.puntos << endl;
    
    return 0;
}
