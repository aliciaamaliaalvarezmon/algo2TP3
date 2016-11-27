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






int main() {
	RUN_TEST(compila);
	RUN_TEST(AgregaJugador);
	return 0;
}
