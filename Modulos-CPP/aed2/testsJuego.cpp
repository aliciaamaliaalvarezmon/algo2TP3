#include <iostream>
#include "mini_test.h"

#include "Juego.h"
#include "Conj.h"

using namespace aed2;

void compila(){
	Mapa m;
	Coordenada primera(1,1);	
	m.agregarCoord(primera);
	Juego nuevo(m);
	ASSERT(nuevo.VerMapa().longitudMaxima() == 2);
	ASSERT(nuevo.VerMapa().latitudMaxima() == 2);
	ASSERT(nuevo.VerMapa().coordenadasMapa().Pertenece(primera));

	}

void AgregaJugador(){
	Mapa m;
	Coordenada primera(1,1);
	m.agregarCoord(primera);
	Juego nuevo(m);
	Nat cero = nuevo.AgregarJugador();
	ASSERT(nuevo.estaConectado(cero) == false);
	ASSERT(nuevo.sanciones(cero) == 0);
	//typename DiccString< Nat>::Iterador pok nuevo.Pokemons(cero);
	ASSERT(nuevo.Pokemons(cero).HaySiguiente() == false);
	ASSERT(nuevo.Expulsados().EsVacio());
	ASSERT(nuevo.ProxID() == 1);
	ASSERT(nuevo.JugadoresConectados().EsVacio());
	ASSERT(nuevo.CantPokemonTotales() == 0);
	ASSERT(nuevo.HayPokemonCercano(primera)== false);
	ASSERT(nuevo.CrearIt().Siguiente() == cero);
	
}


void conectar(){
	Mapa m;
	Coordenada primera(1,1);
	Coordenada segunda(2,3);
	Coordenada tercera(3, 4);
	Coordenada cuarta(1, 2);
	Coordenada quinta(5, 2);
	m.agregarCoord(primera);
	m.agregarCoord(segunda);//aca
	m.agregarCoord(tercera);
	m.agregarCoord(cuarta);
	m.agregarCoord(quinta);
	Juego hola(m);
	ASSERT(hola.matrizJUGADORESLongitud() == 5);
	ASSERT(hola.matrizJUGADORESLatitud() == 6);
	ASSERT(hola.matrizPOKEMONLongtitud() == 5);
	ASSERT(hola.matrizPOKEMONLatitud() == 6);
	Nat cero = hola.AgregarJugador();
	//hola.conectarse(cero, primera);
	//ASSERT(hola.estaConectado(cero) == true);
	//ASSERT(hola.sanciones(cero) == 0);
	//ASSERT(hola.posicion(cero) == primera);
	//ASSERT(hola.Pokemons(cero).HaySiguiente() == false);
	//ASSERT(hola.Expulsados().EsVacio());
	//ASSERT(hola.ProxID() == 1);
	//ASSERT(!hola.JugadoresConectados().EsVacio());
	//ASSERT(hola.JugadoresConectados().Pertenece(cero));
	//ASSERT(hola.CantPokemonTotales() == 0);
	//ASSERT(hola.HayPokemonCercano(primera)== false);
	//ASSERT(hola.CrearIt().Siguiente() == cero);	
}
















int main() {
	//RUN_TEST(compila);
	//RUN_TEST(AgregaJugador);
	RUN_TEST(conectar);
	return 0;
}
