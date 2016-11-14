#include "Coordenada.h"

Coordenada::Coordenada(Nat n, Nat m){
	lat = n;
	lon = m;
}

const Nat& Coordenada::latitud() const {
	return lat;
}

const Nat& Coordenada::longitud() const {
	return lon;
}

Nat Coordenada::distEuclidea(const Coordenada& c) const {
	Nat x;
	Nat y;
	if(this->lat < c.latitud()){
		x = (c.latitud() - this->lat) * (c.latitud() - this->lat);
	}
	else{
		x = (this->lat - c.latitud()) * (this->lat - c.latitud());
	}

	if(this->lon < c.longitud()){
		y = (c.longitud() - this->lon) * (c.longitud() - this->lon);
	}
	else{
		y = (this->lon - c.longitud()) * (this->lon - c.longitud());
	}
	return x+y;
}

Coordenada Coordenada::CoordenadaArriba() const {
	return Coordenada(lat+1, lon);
}

Coordenada Coordenada::CoordenadaAbajo() const {
	return Coordenada(lat-1, lon);
}

Coordenada Coordenada::CoordenadaALaDerecha() const {
	return Coordenada(lat, lon+1);
}

Coordenada Coordenada::CoordenadaALaIzquierda() const{
	return Coordenada(lat, lon-1);	
}


/*NO OLVIDAR SACAR EL MAIN AL FINALIZAR DE TESTEAR LA CLASE*/
/*
int main(){

	Coordenada c1 = Coordenada(5,6);
	Coordenada c2 = Coordenada(3,8);
	Coordenada c3 = Coordenada(7,1);
	Coordenada c4 = Coordenada(9,0);
	Coordenada c5 = Coordenada(0,0);


	//tests latitud() y longitud():
	cout << "c1 = " << "(" << c1.latitud() << ", " << c1.longitud() << ")" << endl;
	cout << "c2 = " << "(" << c2.latitud() << ", " << c2.longitud() << ")" << endl;
	cout << "c3 = " << "(" << c3.latitud() << ", " << c3.longitud() << ")" << endl;
	cout << "c4 = " << "(" << c4.latitud() << ", " << c4.longitud() << ")" << endl;
	cout << "c5 = " << "(" << c5.latitud() << ", " << c5.longitud() << ")" << endl;

	//tests distEuclidea():
	cout << "distancia euclidea entre c1 y c2: " << c1.distEuclidea(c2) << endl;
	cout << "distancia euclidea entre c2 y c1: " << c2.distEuclidea(c1) << endl;
	cout << "distancia euclidea entre c3 y c5: " << c3.distEuclidea(c5) << endl;
	cout << "distancia euclidea entre c4 y c3: " << c4.distEuclidea(c3) << endl;

	//tests coordenadaArriba():
	cout << "coordenada arriba de c1: " << "(" << c1.CoordenadaArriba().latitud() << 
	", " << c1.CoordenadaArriba().longitud() << ")" << endl;

	cout << "coordenada abajo de c1: " << "(" << c1.CoordenadaAbajo().latitud() << 
	", " << c1.CoordenadaAbajo().longitud() << ")" << endl;

	cout << "coordenada a la derecha de c1: " << "(" << c1.CoordenadaALaDerecha().latitud() << 
	", " << c1.CoordenadaALaDerecha().longitud() << ")" << endl;

	cout << "coordenada a la izquierda de c1: " << "(" << c1.CoordenadaALaIzquierda().latitud() << 
	", " << c1.CoordenadaALaIzquierda().longitud() << ")" << endl;

	return 0;
}

*/
