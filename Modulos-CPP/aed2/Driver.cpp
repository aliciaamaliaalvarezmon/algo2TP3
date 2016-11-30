#include "Driver.h"
#include "Juego.h"
// Instanciar un mapa y un juego 

Driver::Driver(const Conj< Coordenada > & cs)
{
	Conj< Coordenada >::const_Iterador it = cs.CrearIt();
	Mapa m;
	while(it.HaySiguiente()){
		m.agregarCoord(it.Siguiente());
		it.Avanzar();
	}
	Juego game(m);
}

Driver::~Driver()
{
  
}

void Driver::agregarPokemon(const Pokemon & p, const Coordenada & c)
{
  game.AgregarPokemon(p,c);
}

void Driver::conectarse(const Jugador & j, const Coordenada & c){
	game.conectarse(j,c);
}

void Driver::desconectarse(const Jugador & j){
	game.desconectarse(j);
}

void Driver::moverse(const Jugador & j, const Coordenada & c){
	game.moverse(j,c);
}

Conj< Coordenada > Driver::mapa() const{
	return (game.VerMapa()).coordenadasMapa();
}

bool Driver::hayCamino(const Coordenada & c1, const Coordenada & c2) const{
	return (game.VerMapa()).hayCamino(c1,c2);
}

bool Driver::posExistente(const Coordenada & c) const{
	return (game.VerMapa()).posEnMapa(c);
}
Conj< Jugador > Driver::jugadores() const{
	Juego::const_Iterador it = game.CrearIt();
	Conj< Jugador > res;
	while(it.HaySiguiente()){
		res.AgregarRapido(it.Siguiente());
		it.Avanzar();
	}
	return res;
}
bool Driver::estaConectado(const Jugador & j) const{
	return (game.estaConectado(j));
}
Nat Driver::sanciones(const Jugador & j) const{
	return (game.sanciones(j));
}
Coordenada Driver::posicion(const Jugador & j) const{
	return (game.posicion(j));
}

Dicc< Pokemon , Nat > Driver::pokemons(const Jugador & j) const{
	DiccString< Nat >::Iterador it(game.Pokemons(j));
	Dicc< Pokemon , Nat > res;
	while(it.HaySiguiente()){
		res.DefinirRapido(it.SiguienteClave(),it.SiguienteSignificado());
		it.Avanzar();
	}
	return res;
}
Conj< Jugador > Driver::expulsados() const{
	return game.Expulsados();
}

Conj< Coordenada > Driver::posConPokemons() const{
	return game.posConPokemons();
}

Pokemon Driver::pokemonEnPos(const Coordenada & c) const{
	return game.pokemonEnPos(c);
}
Nat Driver::cantMovimientosParaCaptura(const Coordenada & c) const{
	return game.cantMovimientosParaCaptura(c);
}
bool Driver::puedoAgregarPokemon(const Coordenada & c) const{
	
}
bool Driver::hayPokemonCercano(const Coordenada & c) const{
	return game.HayPokemonCercano(c);
}
Coordenada Driver::posPokemonCercano(const Coordenada & c) const{
	return game.BuscarHeap(c);
}
Conj<Jugador> Driver::entrenadoresPosibles(const Coordenada & c) const{
	return game.cercanos();
}
Nat Driver::indiceRareza(const Pokemon & p) const{
	return game.indiceDeRareza(p);
}
Nat Driver::cantPokemonsTotales() const{
	return game.CantPokemonTotales();
}
Nat Driver::cantMismaEspecie(const Pokemon & p) const{
//	return game.
}
// TODO: Completar con el resto de las implementaciones
