#include "Jugador.h"


Jugador::Jugador(int id_, Tablero* mesa_){
    
    id = id_;
    mesa = mesa_;
    puntos = 0;
    
}

bool Jugador::emparejar( ){
    
    int IdUno;
    
    cout << "-- " << mesa->cartasRetiradas << " --" << endl;
    cout << "====== Jugador " << id << " ======" << endl;
    cout << "Ingrese el ID de la primera carta a emparejar: ";
    cin >> IdUno;
    
    mesa->voltear(IdUno);
    mesa->mostrar();
    
    int IdDos;
    
    cout << "-- " << mesa->cartasRetiradas << " --" << endl;
    cout << "====== Jugador " << id << " ======" << endl;
    cout << "Ingrese el ID de la segunda carta a emparejar: ";
    cin >> IdDos;
    
    mesa->voltear(IdDos);
    mesa->mostrar();
    
    
    bool parejas = (mesa->Cartas[IdUno-1] == mesa->Cartas[IdDos-1]);
    
    if(parejas){
        
        mesa->retirar(IdUno);
        mesa->retirar(IdDos);
        puntos++;
        
    }else{
        
        mesa->voltear(IdUno);
        mesa->voltear(IdDos);    
        
    }
    
    return parejas;
    
}

void Jugador::turno( ){
    
    
    bool pareja = true;
        
    while(pareja and (mesa->cartasRetiradas < 24)){
        
        pareja = emparejar();
        
    }
    
}