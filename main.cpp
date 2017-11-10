#include <iostream>
#include <vector>
using namespace std;


//funciones 

Pieza*** crearTablero();
void eliminarTablero(Pieza***);

int main(){

	
	return 0;
}

Pieza*** crearTablero(){
	Pieza*** tablero = new tablero[8];
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

void eliminarTablero(Pieza*** tablero){
	for (int i = 0; i < 8; ++i){	
		delete[] tablero[i];
	}
	delete[] tablero;
}
