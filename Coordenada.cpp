#include "Coordenada.h"

Coordenada::Coordenada():lat(0),lon(0){}
Coordenada::Coordenada(Nat n, Nat m){
	lat = n;
	lon = m;
}
bool Coordenada::operator == (const Coordenada &otro)const{
	return this->latitud() == otro.lat and this->longitud() ==otro.lon;
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
	return Coordenada(lat-1, lon);
}

Coordenada Coordenada::CoordenadaAbajo() const {
	return Coordenada(lat+1, lon);
}

Coordenada Coordenada::CoordenadaALaDerecha() const {
	return Coordenada(lat, lon+1);
}

Coordenada Coordenada::CoordenadaALaIzquierda() const{
	return Coordenada(lat, lon-1);	
}

Conj<Coordenada> Coordenada::Lindantes() const{
	Conj<Coordenada> res;
	Coordenada c(latitud(),longitud());
	Coordenada abajo(c.CoordenadaAbajo().latitud(),c.CoordenadaAbajo().longitud());
	Coordenada arriba(c.CoordenadaArriba().latitud(),c.CoordenadaArriba().longitud());
	Coordenada derecha(c.CoordenadaALaDerecha().latitud(),c.CoordenadaALaDerecha().longitud());
	Coordenada izquierda(c.CoordenadaALaIzquierda().latitud(),c.CoordenadaALaIzquierda().longitud());
	res.Agregar(abajo);
	res.Agregar(arriba);
	res.Agregar(izquierda);
	res.Agregar(derecha);
	return res;
}
