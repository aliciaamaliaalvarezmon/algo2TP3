/* =============================================================
 * Implementación del módulo Coordenada.
 * 
 * 
 * =============================================================
 */

#include <string>
#include <ostream>
#include <iostream>
#include Conj.h
using namespace std;
typedef unsigned int Nat;

class Coordenada{
	public: 
		// Crea una Coordenada con los valores n y m.
		Coordenada(Nat n, Nat m);
		/*CONSULTA: en el tp este metodo se llama crearCoord. podemos cambiar el nombre?*/

		// Devuelve la latitud de la coordenada c.
		const Nat& latitud() const;

		// Devuelve la longitud de la coordenada c.
		const Nat& longitud() const;

		// Devuelve la distancia entre this y c1
		Nat distEuclidea(const Coordenada& c1) const;

		// Devuelve una coordenada idéntica a la pasada por parámetro pero corrida una arriba.
		Coordenada CoordenadaArriba() const;
		/*CONSULTA: CoordenadaArriba() debería devolver una refernecia?*/

		//Devuelve una coordenada idéntica a la pasada por parámetro pero corrida una abajo.
		Coordenada CoordenadaAbajo() const;

		// Devuelve una coordenada idéntica a la pasada por parámetro pero corrida una a la derecha.
		Coordenada CoordenadaALaDerecha() const;

		// Devuelve una coordenada idéntica a la pasada por parámetro pero corrida una a la izquierda.
		Coordenada CoordenadaALaIzquierda() const;
		bool operator ==(const Coordenada& otro)const;
	
		Conj<Coordenada>  Lindantes() const;
	
	private:
		Nat lat;
		Nat lon;

};





