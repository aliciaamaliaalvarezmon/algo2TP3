#include "Juego.h"



namespace aed2{

	Juego::Juego(){
		Mapa mundi;
		mundo_= mundi;		
		Vector<typename Juego::dataJugador> jug;
		vectJug_ = jug;
		//DiccString<typename Juego::datapokemon> pokes;
		//pokemones_ = pokes;
		Vector<Vector<Dicc<Nat, Coladeprioridad<pair<Nat, Nat> >::Iterador> > > VmatrizJug;	
		matrizJugadores_ = VmatrizJug;
		Vector<Vector<infoHeap> > VmatrizP;
		matrizPokemon_ = VmatrizP;
		Dicc<Coordenada,String> pospok;
		posdePokemon_= pospok;
		Lista<DiccString<Nat> > pokXjug;
		pokemonsXjug_= pokXjug;
		cantPokemon_ = 0;



	}

	Juego::Juego(Mapa m){
		mundo_= m;
		Vector<typename Juego::dataJugador> jug;
		vectJug_ = jug;
		//DiccString<typename Juego::datapokemon> pokes;//	datapokemon es privado........
		//pokemones_ = pokes;
		Dicc<Coordenada,String> pospok;
		posdePokemon_= pospok;
		Lista<DiccString<Nat> > pokXjug;
		pokemonsXjug_= pokXjug;
		cantPokemon_ = 0;
		matrizJugadores_ = crearMatrizJug(m.longitudMaxima(), m.latitudMaxima());
		matrizPokemon_ = crearMatrizPok(m.longitudMaxima(), m.latitudMaxima());
	}


	Nat Juego::AgregarJugador(){
		return 0;
	}

	void Juego::AgregarPokemon(string p, Coordenada c){

	}

	void Juego::conectarse(Nat e, Coordenada c){

	}

	void Juego::desconectarse(Nat e){

	}

	void Juego::moverse(Nat e, Coordenada c){

	}

	Mapa Juego::VerMapa(){
		return mundo_;
	}


	Juego::Iterador Juego::Jugadores(){
		Juego::Iterador nuevo = CrearIt();
		return nuevo;
	}

	bool Juego::estaConectado(Nat e){		
		return false;									//PROBLEMA
		//return vectJug_[e].conexion;
	}

	Nat Juego::sanciones(Nat e){								//PROBLEMA							
		//return 0;
			return vectJug_[e].sanciones;
	}


	 Coordenada Juego::posicion(Nat e){
	    //Coordenada nuevo;
	 	//return nuevo;
	 	return vectJug_[e].posicion;
	  }

	  DiccString< Nat>::Iterador Juego::Pokemons(Nat e){//Aca deberia??? ser DiccString(Nat)::Iterador
	  	//Dicc<pair<string, Nat> >::Iterador nuevo; 
	  	//return nuevo;
	  	DiccString< Nat >::Iterador it = vectJug_[e].pokemonescapturados.Siguiente().CrearIt();
	  	return it;

	  }


	  Conj<Nat> Juego::Expulsados(){  ////lio????
	  	Conj<Nat> nuevo;
	  	return nuevo;

	  }



	  Conj<Coordenada>::Iterador Juego::posConPokemons(){
	  	//Conj<Coordenada>::Iterador nuevo;
	  	//return nuevo;
	  	Conj<Coordenada>::Iterador nuevo = posdePokemon_.claves().CrearIt();
	  	return nuevo;

	  }

	    String Juego::pokemonEnPos(Coordenada c){
	    //return "falla";
	    	return posdePokemon_.Significado(c);

	    }

	    Nat Juego::CantMovimientosParaCaptura(Coordenada c){
	    	//return 9;
	    	string p = posdePokemon_.Significado(c);
	    	return pokemones_.Obtener(p).Significado(c); 

	    }

	     Nat Juego::ProxID(){
	     	//return 0;
	     	return vectJug_.Longitud();
	     }


	     Conj<Nat> JugadoresConectados(){    ///lio?
	     	Conj<Nat> nuevo;
	     	return nuevo;
	     }



	    Nat Juego::indiceDeRareza(string p){ //PROBLEMA en la rep(con friend se resolveria????)
	    	//return 0;
	    	Nat capturados = (pokemones_.Obtener(p)).PC;
	    	Nat salvajes = (pokemones_.Obtener(p)).PS;
	    	Nat cant = capturados + salvajes;
	    	return 100 - (100 * (cant/cantPokemon_));
	    }


	    Nat Juego::CantPokemonTotales(){
	    	return cantPokemon_;
	    }

	     bool Juego::HayPokemonCercano(Coordenada c){
	     	return false;
	     }

	     Coordenada Juego::PosDePokemonCercano(){
	     	Coordenada nueva;
	     	return nueva;
	     }


	     typename Juego::Iterador Juego::CrearIt(){
	     	Vector<dataJugador>* jug = &(this->vectJug_);
	     	typename Juego::Iterador nuevo(jug);
	     }



	    Vector<Vector<Dicc<Nat, Coladeprioridad<pair<Nat, Nat> >::Iterador> > > Juego::crearMatrizJug(Nat n, Nat m){
	    	Vector<Vector<Dicc<Nat, Coladeprioridad<pair<Nat, Nat> >::Iterador> > > nuevo;
	    	return nuevo; 

	    }

		Vector<Vector<typename Juego::infoHeap> > Juego::crearMatrizPok(Nat n, Nat m){
			Vector<Vector<infoHeap> > nuevo;
			return nuevo;
		}

/*
	Mapa mundo_;
		vector<dataJugador> vectJug_;
		DiccString<datapokemon> pokemones_;
		vector<vector<Dicc<Nat, Coladeprioridad<pair<Nat, Nat>>::Iterador>>> matrizJugadores;//(pokcapturados, ID)
		vector<vector<infoHeap>> matrizPokemon;
		Dicc<Coordenada, String> posdePokemon;//(coordenada,pokemon)
		Lista<diccString<nat>> pokemonsXjug;
		Nat cantJugador;




*/




}


