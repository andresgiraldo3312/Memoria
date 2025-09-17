#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>

#define  BG_BLACK    "\x1B[40m"
#define  BG_RED      "\x1B[41m"
#define  BG_GREEN    "\x1B[42m"
#define  BG_AMARILLO "\x1B[43m"
#define  BG_BLUE     "\x1B[44m"
#define  BG_MAGENTA  "\x1B[45m"
#define  BG_CYAN     "\x1B[46m"
#define  BG_BLANCO   "\x1B[47m"
#define  BG_NARANJA  "\x1B[48;2;255;128;0m"
#define  BG_LBLUE    "\x1B[48;2;53;149;240m"
#define  BG_LGREEN   "\x1B[48;2;17;245;120m"
#define  BG_GRAY     "\x1B[48;2;176;174;174m"
#define  BG_ROSE     "\x1B[48;2;255;151;203m"
#define  WHITE       "\x1B[37m"
#define  RESET       "\x1b[0m"

using namespace std;

class Carta{
    
    public:
        static const char* paleta[12];
        int color;
        int id;
        int estado; // 0: carta boca abajo, 1: carta boca arriba, 2: emparejado
        Carta();
        Carta(int color);
        void mostrar();
        void voltear();
        void retirar();
        bool comparar(Carta acomparar);
        bool operator==(const Carta& otro);
};

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
 

class Jugador{
    
    public:
        int puntos;
        int id;
        Tablero* mesa;
        
        Jugador(int id_, Tablero* mesa_);
        bool emparejar();
        void turno();
    
};

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

//char Buffer[sizeof(Tablero)];


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
