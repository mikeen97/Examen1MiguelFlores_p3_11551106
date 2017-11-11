#include "Pieza.h"

Pieza::Pieza(string TIpo){
	this->TIpo=TIpo;
}
Pieza::Pieza(){

}void Pieza::setTIpo(string TIpo){
   this-> TIpo=TIpo;
}
string Pieza::getTIpo(){
   return TIpo;
}
