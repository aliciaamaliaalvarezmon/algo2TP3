#include <iostream>
#include "mini_test.h"

#include "Juego.h"
#include "Conj.h"

using namespace aed2;

/*void compila(){
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
	ASSERT(m.hayCamino(primera, primera));
	ASSERT(m.hayCamino(segunda, segunda));
	ASSERT(m.hayCamino(tercera, tercera));
	ASSERT(m.hayCamino(cuarta, cuarta));
	ASSERT(m.hayCamino(quinta, quinta));
	ASSERT(m.hayCamino(primera, cuarta));
	ASSERT(!m.hayCamino(segunda, quinta));
	//hasta aca el mapa	
	Juego hola(m);
	ASSERT(hola.matrizJUGADORESLongitud() == 5);
	ASSERT(hola.matrizJUGADORESLatitud() == 6);
	ASSERT(hola.matrizPOKEMONLongtitud() == 5);
	ASSERT(hola.matrizPOKEMONLatitud() == 6);
	hola.AgregarPokemon("torchit", primera);		
	ASSERT(hola.CantMovimientosParaCaptura(primera) == 0);
	ASSERT(hola.CantPokemonTotales() == 1);
	ASSERT(hola.indiceDeRareza("torchit") == 0);
	//ASSERT(hola.pokemonEnPos(primera) == "torchit");
	//cout << "llega"<<endl;
	Conj<Coordenada> vacio;
	//cout << hola.posConPokemons(vacio).Siguiente().latitud() << ", " << hola.posConPokemons(vacio).Siguiente().longitud() <<endl;
	//ASSERT(hola.posConPokemons(vacio).Siguiente() == primera);	
	//ASSERT(hola.HayPokemonCercano(primera));
	//agregamos otros pokemons
	hola.AgregarPokemon("jericho", quinta);		
	ASSERT(hola.CantMovimientosParaCaptura(quinta) == 0);
	cout << "llega"<<endl;	
	ASSERT(hola.CantPokemonTotales() == 2);
	cout << hola.indiceDeRareza("jericho") << endl;
	ASSERT(hola.indiceDeRareza("jericho") == 50);
	//ASSERT(hola.indiceDeRareza("torchit") == 50);
	ASSERT(hola.pokemonEnPos(quinta) == "jericho");
	ASSERT(hola.HayPokemonCercano(quinta));
	Conj<Coordenada>::Iterador iter = hola.posConPokemons(vacio);
	ASSERT(iter.Siguiente() == primera);
	iter.Avanzar();
	ASSERT(iter.Siguiente() == quinta);
	//cout << hola.PosDePokemonCercano(quinta).latitud() <<"," << hola.PosDePokemonCercano(quinta).longitud() << endl;



}


 

void Conecto_cerca_de_pokemon(){
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
	Nat cero = hola.AgregarJugador();
	Nat uno = hola.AgregarJugador();	
	hola.AgregarPokemon("torchit", primera);
	hola.conectarse(cero, cuarta);
	hola.conectarse(uno, primera);
	hola.desconectarse(uno);



}


void Agrego_pok_cerca_de_jugador(){
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
	Nat cero = hola.AgregarJugador();
	Nat uno = hola.AgregarJugador();
	hola.conectarse(cero, cuarta);
	hola.conectarse(uno, primera);
	hola.AgregarPokemon("torchit", primera);
}


void Agrego_Juegador_cerca(){
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
	Nat cero = hola.AgregarJugador();	
	hola.conectarse(cero, primera);	
	hola.AgregarPokemon("torchit", primera);
	ASSERT(hola.HayUnJugadorCercano(primera));
}

void Agrego_cercanos(){
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
	Nat cero = hola.AgregarJugador();
	Nat uno = hola.AgregarJugador();
	Nat dos = hola.AgregarJugador();	
	hola.conectarse(cero, primera);
	hola.conectarse(uno, cuarta);	
	hola.conectarse(dos, primera);
	hola.AgregarPokemon("torchit", primera);
	ASSERT(hola.HayUnJugadorCercano(cuarta));
}


void Moverse(){
	Mapa m;
	Coordenada primera(1,1);
	Coordenada segunda(2,3);
	Coordenada tercera(3, 4);
	Coordenada cuarta(1, 2);
	Coordenada quinta(5, 2);
	Coordenada sexta(5,1);
	m.agregarCoord(primera);
	m.agregarCoord(segunda);//aca
	m.agregarCoord(tercera);
	m.agregarCoord(cuarta);
	m.agregarCoord(quinta);
	m.agregarCoord(sexta);
	cout << "distEuclidea"<< tercera.distEuclidea(primera)<< endl;
	Juego hola(m);
	Nat cero = hola.AgregarJugador();
	Nat uno = hola.AgregarJugador();
	Nat dos = hola.AgregarJugador();
	hola.conectarse(cero, primera);
	hola.conectarse(uno, quinta);
	//hola.conectarse(dos, primera);	
	hola.AgregarPokemon("torchit", primera);	
	hola.moverse(1, sexta);	
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);
	hola.moverse(1, sexta);	
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);	
	hola.AgregarPokemon("jerachi", primera);
	hola.desconectarse(cero);
	hola.moverse(1, sexta);	
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);
	hola.moverse(1, sexta);	
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);	
	//typename DiccString< Nat >::Iterador funca = hola.Pokemons(cero);
	//typename DiccString< Nat >::Iterador funcando = hola.Pokemons(dos);
	//while(funca.HaySiguiente()){
	//	cout << funcando.SiguienteClave() << ", " << funcando.SiguienteSignificado() << endl;
	//	cout << funca.SiguienteClave() << ", " << funca.SiguienteSignificado() << endl;		
//		if(funca.HaySiguiente()){
		
		//funcando.Avanzar();
		//cout << funcando.SiguienteClave() << ", " << funcando.SiguienteSignificado() << endl;
		//funca.Avanzar();
//	}
//	}


	//hola.conectarse(dos, primera);


}


void GenerarCaptura(Juego j, Nat e, Coordenada c ){
	Nat i = 0;
	while(i < 10){
		j.moverse(e,c);
		i++;
	}
}


void se_desconecta(){
	Mapa m;
	Coordenada primera(1,1);
	Coordenada segunda(2,3);
	Coordenada tercera(3, 4);
	Coordenada cuarta(1, 2);
	Coordenada quinta(5, 2);
	Coordenada sexta(5,1);
	m.agregarCoord(primera);
	m.agregarCoord(segunda);//aca
	m.agregarCoord(tercera);
	m.agregarCoord(cuarta);
	m.agregarCoord(quinta);
	m.agregarCoord(sexta);
	Juego hola(m);
	Nat cero = hola.AgregarJugador();
	Nat uno = hola.AgregarJugador();
	Nat dos = hola.AgregarJugador();
	hola.conectarse(cero, primera);
	hola.conectarse(uno, quinta);
	hola.conectarse(dos, primera);
	hola.AgregarPokemon("torchit", primera);
	//hola.desconectarse(dos);	
	cout << "distEuclidea"<< tercera.distEuclidea(primera)<< endl;
	hola.moverse(1, sexta);	
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);
	hola.moverse(1, sexta);	
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);	
	hola.AgregarPokemon("jerachi", primera);
	hola.desconectarse(cero);
	hola.moverse(1, sexta);	
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);
	hola.moverse(1, sexta);	
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,sexta);	
	//typename DiccString< Nat >::Iterador funca = hola.Pokemons(cero);
	//typename DiccString< Nat >::Iterador funcando = hola.Pokemons(dos);
	//while(funca.HaySiguiente()){
	//	cout << funcando.SiguienteClave() << ", " << funcando.SiguienteSignificado() << endl;
	//	cout << funca.SiguienteClave() << ", " << funca.SiguienteSignificado() << endl;		
//		if(funca.HaySiguiente()){
		
		//funcando.Avanzar();
		//cout << funcando.SiguienteClave() << ", " << funcando.SiguienteSignificado() << endl;
		//funca.Avanzar();
//	}
//	}


	//hola.conectarse(dos, primera);


}





void dos_capturas(){
	Mapa m;
	Coordenada primera(1,1);
	Coordenada segunda(1,2);
	Coordenada tercera(11, 20);
	Coordenada cuarta(10, 20);
	Coordenada quinta(30, 25);
	m.agregarCoord(primera);
	m.agregarCoord(segunda);//aca
	m.agregarCoord(tercera);
	m.agregarCoord(cuarta);
	m.agregarCoord(quinta);
	Juego hola(m);
	Nat cero = hola.AgregarJugador();
	Nat uno = hola.AgregarJugador();
	Nat dos = hola.AgregarJugador();	
	hola.conectarse(cero, primera);
	hola.conectarse(uno, tercera);	
	hola.conectarse(dos, quinta);
	hola.AgregarPokemon("torchit", primera);
	hola.AgregarPokemon("gabumon", tercera);
	GenerarCaptura(hola, dos, quinta);
	//ASSERT(hola.HayUnJugadorCercano(cuarta));*/
//}
/*

void Me_Voy(){
	Mapa m;
	Coordenada primera(1,1);
	Coordenada segunda(1,2);
	Coordenada tercera(11, 20);
	Coordenada cuarta(10, 20);
	Coordenada quinta(30, 25);
	Coordenada sexta(1,3);
	Coordenada septima(1,4);
	Coordenada octava(1,5);
	m.agregarCoord(primera);
	m.agregarCoord(segunda);//aca
	m.agregarCoord(tercera);
	m.agregarCoord(cuarta);
	m.agregarCoord(quinta);
	m.agregarCoord(sexta);
	m.agregarCoord(septima);
	m.agregarCoord(octava);
	Juego hola(m);
	Nat cero = hola.AgregarJugador();
	Nat uno = hola.AgregarJugador();
	Nat dos = hola.AgregarJugador();	
	hola.conectarse(cero, primera);
	hola.conectarse(uno, quinta);	
	hola.conectarse(dos, primera);
	hola.AgregarPokemon("torchit", primera);
	hola.moverse(1, quinta);	
	hola.moverse(1,quinta);
	hola.moverse(1, quinta);
	hola.moverse(1, quinta);	
	hola.moverse(1,quinta);
	hola.moverse(1, quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.moverse(1,quinta);
	hola.AgregarPokemon("jerachi", primera);
	hola.moverse(dos, octava);
	cout << hola.MostrarTope( 1, 1)<< endl;
	//GenerarCaptura(hola, dos, quinta);
	//ASSERT(hola.HayUnJugadorCercano(cuarta));*/
//}
/*

void Entro(){
	Mapa m;
	Coordenada primera(1,1);
	Coordenada segunda(1,2);
	Coordenada tercera(11, 20);
	Coordenada cuarta(10, 20);
	Coordenada quinta(30, 25);
	Coordenada sexta(1,3);
	Coordenada septima(1,4);
	Coordenada octava(1,5);
	m.agregarCoord(primera);
	m.agregarCoord(segunda);//aca
	m.agregarCoord(tercera);
	m.agregarCoord(cuarta);
	m.agregarCoord(quinta);
	m.agregarCoord(sexta);
	m.agregarCoord(septima);
	m.agregarCoord(octava);
	Juego hola(m);
	Nat cero = hola.AgregarJugador();
	Nat uno = hola.AgregarJugador();
	Nat dos = hola.AgregarJugador();	
	hola.conectarse(cero, primera);
	hola.conectarse(uno, quinta);	
	hola.conectarse(dos, octava);
	hola.AgregarPokemon("torchit", primera);
	hola.moverse(1, quinta);	
	hola.moverse(1,quinta);
	hola.moverse(1, quinta);
	//hola.moverse(1, quinta);	
	//hola.moverse(1,quinta);
	//hola.moverse(1, quinta);
	//hola.moverse(1,quinta);
	//hola.moverse(1,quinta);
	//hola.moverse(1,quinta);
	//hola.moverse(1,quinta);
	//hola.AgregarPokemon("jerachi", primera);
	hola.moverse(dos, primera);
	//cout << hola.MostrarTope( 1, 1)<< endl;
	//GenerarCaptura(hola, dos, quinta);
	//ASSERT(hola.HayUnJugadorCercano(cuarta));*/
//}//






void Expulsion_del_Eden(){
	Mapa m;
	Coordenada primera(1,1);
	Coordenada segunda(1,2);
	Coordenada tercera(11, 20);
	Coordenada cuarta(10, 20);
	Coordenada quinta(30, 25);
	Coordenada sexta(1,3);
	Coordenada septima(1,4);
	Coordenada octava(1,5);
	m.agregarCoord(primera);
	m.agregarCoord(segunda);//aca
	m.agregarCoord(tercera);
	m.agregarCoord(cuarta);
	m.agregarCoord(quinta);
	m.agregarCoord(sexta);
	m.agregarCoord(septima);
	m.agregarCoord(octava);
	Juego hola(m);
	Nat cero = hola.AgregarJugador();
	Nat uno = hola.AgregarJugador();
	Nat dos = hola.AgregarJugador();	
	hola.conectarse(cero, primera);
	hola.conectarse(uno, primera);	
	hola.conectarse(dos, tercera);
	hola.AgregarPokemon("torchit", primera);
	//hola.moverse(2, tercera);	
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);	
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.AgregarPokemon("torchit", primera);
	//hola.moverse(2, tercera);	
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);	
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);
	//hola.moverse(2, tercera);	
	hola.moverse(uno, quinta);	
	hola.moverse(uno, quinta);	
	hola.moverse(uno, quinta);	
	hola.moverse(uno, quinta);	
	hola.moverse(uno, quinta);
	//hola.desconectarse(dos);
	ASSERT(hola.sanciones(uno) == 5);
	//cout << hola.MostrarTope(1, 1) << endl;
	hola.moverse(uno, quinta);
	Conj<Nat> hol;
	hola.Expulsados(hol);
	ASSERT(hol.Pertenece(1));//hola.moverse(1, quinta);
	typename Juego::Iterador adieu = hola.Jugadores();
	Nat i = 10;
	while(adieu.HaySiguiente()){
		cout << adieu.Siguiente() << endl;
		adieu.Avanzar();	
	}



}















int main() {
	//RUN_TEST(compila);
	//RUN_TEST(AgregaJugador);
	//RUN_TEST(conectar);
	//RUN_TEST(desconectar);
	//RUN_TEST(AgregoPokemon);
	//RUN_TEST(Conecto_cerca_de_pokemon);
	//RUN_TEST(Agrego_pok_cerca_de_jugador);
	//RUN_TEST(Agrego_Juegador_cerca);
	//RUN_TEST(Agrego_cercanos);
	//RUN_TEST(Moverse);
	//RUN_TEST(dos_capturas);
	//RUN_TEST(se_desconecta);
	//RUN_TEST(Me_Voy);
	//RUN_TEST(Entro);
	RUN_TEST(Expulsion_del_Eden);
	return 0;
}
