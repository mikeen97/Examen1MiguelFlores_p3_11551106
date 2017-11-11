#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef PIEZA_H
#define PIEZA_H
class Pieza{
	protected:
		string TIpo;
	public:
		Pieza(string);
		Pieza();
		string getTIpo();
		void setTIpo(string);

};
#endif