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
	hola.conectarse(cero, primera);
	ASSERT(hola.estaConectado(cero) == true);
	ASSERT(hola.sanciones(cero) == 0);
	ASSERT(hola.posicion(cero) == primera);
	ASSERT(hola.Pokemons(cero).HaySiguiente() == false);
	ASSERT(hola.Expulsados().EsVacio());
	ASSERT(hola.ProxID() == 1);
	ASSERT(!hola.JugadoresConectados().EsVacio());
	ASSERT(hola.JugadoresConectados().Pertenece(cero));
	ASSERT(hola.CantPokemonTotales() == 0);
	ASSERT(hola.HayPokemonCercano(primera)== false);
	ASSERT(hola.CrearIt().Siguiente() == cero);	
}


void desconectar(){
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
	//hasta aca el mapa
	Juego hola(m);
	ASSERT(hola.matrizJUGADORESLongitud() == 5);
	ASSERT(hola.matrizJUGADORESLatitud() == 6);
	ASSERT(hola.matrizPOKEMONLongtitud() == 5);
	ASSERT(hola.matrizPOKEMONLatitud() == 6);
	Nat cero = hola.AgregarJugador();

	hola.conectarse(cero, primera);
	ASSERT(hola.estaConectado(cero) == true);
	ASSERT(hola.sanciones(cero) == 0);
	ASSERT(hola.posicion(cero) == primera);
	ASSERT(hola.Pokemons(cero).HaySiguiente() == false);
	ASSERT(hola.Expulsados().EsVacio());
	ASSERT(hola.ProxID() == 1);
	ASSERT(!hola.JugadoresConectados().EsVacio());
	ASSERT(hola.JugadoresConectados().Pertenece(cero));
	ASSERT(hola.CantPokemonTotales() == 0);
	ASSERT(hola.HayPokemonCercano(primera)== false);
	ASSERT(hola.CrearIt().Siguiente() == cero);	
	hola.desconectarse(0);
	ASSERT(hola.estaConectado(cero) == false);
	ASSERT(hola.sanciones(cero) == 0);
	ASSERT(hola.Pokemons(cero).HaySiguiente() == false);
	ASSERT(hola.Expulsados().EsVacio());
	ASSERT(hola.ProxID() == 1);
	ASSERT(hola.JugadoresConectados().EsVacio());
	ASSERT(!hola.JugadoresConectados().Pertenece(cero));
	ASSERT(hola.CantPokemonTotales() == 0);
	ASSERT(hola.HayPokemonCercano(primera)== false);
	ASSERT(hola.CrearIt().Siguiente() == cero);	

}



void AgregoPokemon(){
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
	//hasta aca el mapa
	Juego hola(m);
	hola.AgregarPokemon("torchit", primera);		
	ASSERT(hola.CantMovimientosParaCaptura(primera) == 0);
	ASSERT(hola.CantPokemonTotales() == 1);
	ASSERT(hola.indiceDeRareza("torchit") == 0);
	ASSERT(hola.pokemonEnPos(primera) == "torchit");
	//cout << "llega"<<endl;
	Conj<Coordenada> vacio;
	cout << hola.posConPokemons(vacio).Siguiente().latitud() << ", " << hola.posConPokemons(vacio).Siguiente().longitud() <<endl;
	ASSERT(hola.posConPokemons(vacio).Siguiente() == primera);
	cout << "llega"<<endl;	
	ASSERT(hola.HayPokemonCercano(primera));
	cout << hola.PosDePokemonCercano(primera).latitud() <<"," << hola.PosDePokemonCercano(primera).longitud() << endl;


}










int main() {
	//RUN_TEST(compila);
	//RUN_TEST(AgregaJugador);
	//RUN_TEST(conectar);
	//RUN_TEST(desconectar);
	RUN_TEST(AgregoPokemon);
	return 0;
}
