#include <iostream>
#include <string>
#include "Pieza.h"
#include <cstdlib>
#include <sstream>


using namespace std;


//funciones para el tablero
Pieza*** crearTablero(Pieza***);
void eliminarTablero(Pieza***);
void llenarPiezasBlancas(Pieza***);
void llenarPiezasNegras(Pieza***);
void llenarPiezasVacias(Pieza***);
void imprimirTablero(Pieza***);
//funciones para los movimientos
//tablero,posx,posy,newx,newy
void movimientoMarine(Pieza***,int,int,int,int);
//tablero,posx,posy,newx,newy
bool salirTablero(Pieza***,int,int,int,int);


//main
int main(){
	Pieza*** tablero = new Pieza**[8];//mi tablero
    string player1,player2;
	int opcion=0;
	int turno=0;
	while(opcion!=2){
		cout<<"------MENU-------"<<endl;
   		cout<<"1) Jugar"<<endl;
		cout<<"2) SALIR"<<endl;
		cout<<"Ingrese su opcion"<<endl;
		cin>>opcion;
		if (opcion==1){
			cout<<"Igrese el nombre del jugador 1";
			cin>>player1;
			cout<<"ingrese el nombre del jugador 2";
			cin>>player2;
			bool continuarGame=true;
			int turno=1;
			crearTablero(tablero);
			llenarPiezasVacias(tablero);
			llenarPiezasBlancas(tablero);
			llenarPiezasNegras(tablero);
			cout<<endl;
			string posicion;
			string primerX;
			string primerY;
			int posx,posy,newx,newy;
			while(continuarGame==true){
				if (turno==1){
					cout<<"turno de "<<player1<<endl;
					imprimirTablero(tablero);
					cout<<endl;
					do{
						cout<<"iNGRESO POSICION INCORRECTA, ingrese posicion: "<<endl;
						cin>>posicion;
						primerX = posicion.substr(0,2);
						primerY= posicion.substr(3,4);
						posx= primerX[0]-65;
						posy= primerX[1]-49;
						newx= primerY[0]-65;
						newy= primerY[1]-49;
					}while(salirTablero(tablero,posx,posy,newx,newy)==true);
						movimientoMarine==false;
					
					turno=2;//cambio de turno
				}
				if (turno==2){
					cout<<"turno de "<<player2<<endl;
					imprimirTablero(tablero);
					cout<<endl;
					cout<<"ingrese posicion: "<<endl;
					cin>>posicion;
					primerX = posicion.substr(0,2);
					primerY= posicion.substr(3,4);
					posx= primerX[0]-65;
					posy= primerX[1]-49;
					newx= primerY[0]-65;
					newy= primerY[1]-49;
					do{
						cout<<"iNGRESO POSICION INCORRECTA, ingrese posicion: "<<endl;
						cin>>posicion;
						primerX = posicion.substr(0,2);
						primerY= posicion.substr(3,4);
						posx= primerX[0]-65;
						posy= primerX[1]-49;
						newx= primerY[0]-65;
						newy= primerY[1]-49;
					}while(salirTablero(tablero,posx,posy,newx,newy)==true);
				
					turno=1;//cambio de turno
				}

			}	
		}
		eliminarTablero(tablero);
	}
     return 0;
}

bool salirTablero(Pieza*** tablero,int posx ,int posy ,int newx ,int newy){
	if (posx=0 && posx <8 && newx>0 && newy<9 ){
		cout<<"Se salio del tablero";
		return true;
		
	}
	if (tablero[posx][posy]->getTIpo()=="  "){
			cout<<"Selecciono posicon INCORRECTA";
		return true;		
	}

}

//funcion para imprimir la matriz
void imprimirTablero(Pieza*** tablero){
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			cout<<"["<<tablero[i][j]->getTIpo()<<"]";
		}
		cout<<""<<endl;
	}
}

//metodo para llenar el tablero de espacios vacios 
void llenarPiezasVacias(Pieza*** tablero){
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			tablero[i][j]=new Pieza("  ");
		}
	}
}

//metodo para llenar el tablero de piezas en blancas
void llenarPiezasBlancas(Pieza*** tablero){
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
				tablero[7][0]= new Pieza("m1");//linea 1
				tablero[7][2]= new Pieza("m1");
				tablero[7][4]= new Pieza("m1");
				tablero[7][6]= new Pieza("m1");
				tablero[6][1]= new Pieza("m1");//linea 2
				tablero[6][3]= new Pieza("m1");
				tablero[6][5]= new Pieza("m1");
				tablero[6][7]= new Pieza("m1");
				tablero[5][0]= new Pieza("m1");//linea3
				tablero[5][2]= new Pieza("m1");
				tablero[5][4]= new Pieza("m1");
				tablero[5][6]= new Pieza("m1");
		}
	}
}
//metodo para llenar el tablero de piezas en negras
void llenarPiezasNegras(Pieza*** tablero){
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
				tablero[0][1]= new Pieza(" m");//linea 1
				tablero[0][3]= new Pieza(" m");
				tablero[0][5]= new Pieza(" m");
				tablero[0][7]= new Pieza(" m");
				tablero[1][0]= new Pieza(" m");//linea 2
				tablero[1][2]= new Pieza(" m");
				tablero[1][4]= new Pieza(" m");
				tablero[1][6]= new Pieza(" m");
				tablero[2][1]= new Pieza(" m");//linea 3 
				tablero[2][3]= new Pieza(" m");
				tablero[2][5]= new Pieza(" m");
				tablero[2][7]= new Pieza(" m");
		}
	}
}


//metodo para crear el tablero dinamico
Pieza*** crearTablero(Pieza*** tablero){
	for (int i = 0; i < 8; ++i){	
		tablero[i]= new Pieza*[8];
	}
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			tablero[i][j]=NULL;
		}
	}
	return tablero;
}


//metodo para eliminar de memoria el tablero
void eliminarTablero(Pieza*** tablero){
	for (int i = 0; i < 8; ++i){	
		delete[] tablero[i];
	}
	delete[] tablero;
}
///
////MOVIMIENTOS

//MARINES
//tablero,posx,posy,newx,newy
void movimientoMarine(Pieza*** tablero, int posx, int posy ,int newX, int newY){
	tablero[posx][posy] = new Pieza(" ");
	tablero[newX][newY] = new Pieza(" m");
}

