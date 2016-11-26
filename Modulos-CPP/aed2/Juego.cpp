#include "Juego.h"



using namespace aed2;




Juego::Juego()
	: mundo_(), vectJug_(), pokemones_(), matrizJugadores_(), matrizPokemon_(), posdePokemon_(), pokemonsXjug_(), cantPokemon_(0)
	{}

Juego::Juego(Mapa m)
	: mundo_(m), vectJug_(), pokemones_(), matrizJugadores_(), matrizPokemon_(), posdePokemon_(), pokemonsXjug_(), cantPokemon_(0)
	{}	



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


	typename Juego::Iterador Juego::Jugadores(){
		Juego::Iterador nuevo = CrearIt();
		return nuevo;
	}

	bool Juego::estaConectado(Nat e){				
		return vectJug_[e].conexion;
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


//VER WARNINGS DE DICCSTRING

	  DiccString< Nat>::Iterador Juego::Pokemons(Nat e){//Aca deberia??? ser DiccString(Nat)::Iterador
	  	//Dicc<pair<string, Nat> >::Iterador nuevo; 
	  	//return nuevo;
	  	DiccString< Nat >::Iterador it = vectJug_[e].pokemonescapturados.Siguiente().CrearIt();
	  	return it;

	  }


	  Conj<Nat> Juego::Expulsados(){
	  	Conj<Nat> nuevo;
	  	Nat i = 0;
	  	while(i < vectJug_.Longitud()){
	  		if( vectJug_[i].sanciones == 5){
	  		nuevo.AgregarRapido(i);
	  		}
	  	i++;	

	  	}
	  	return nuevo;

	  }



	  Conj<Coordenada>::Iterador Juego::posConPokemons(){
	  	//Conj<Coordenada>::Iterador nuevo;
	  	//return nuevo;
	  	Conj<Coordenada>::Iterador nuevo = Claves(posdePokemon_).CrearIt();
	  	return nuevo;

	  }

	    String Juego::pokemonEnPos(Coordenada c){
	    //return "falla";
	    	return posdePokemon_.Significado(c);

	   }

	     Nat Juego::CantMovimientosParaCaptura(Coordenada c){
	    	//return 9;
	    	return matrizPokemon_[c.latitud()][c.longitud()].contador_;
	    	//string p = posdePokemon_.Significado(c);
	    	//return pokemones_.Obtener(p).Significado(c); 

	    }

	     Nat Juego::ProxID(){
	     	//return 0;
	     	return vectJug_.Longitud();
	     }


	     Conj<Nat> Juego::JugadoresConectados(){    ///lio?
	     	Conj<Nat> nuevo;
	     	Nat i = 0;
	     	while( i < vectJug_.Longitud()){
	     		if((vectJug_[i].sanciones == 5) and (vectJug_[i].conexion)){
	     			nuevo.AgregarRapido(i);
	     		}
	     		i++;
	     	}
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
	     	return nuevo;
	     }



//FUNCIONES PRIVADAS


		Conj< Coordenada > Juego::Claves(Dicc<Coordenada, string> dicc){
			Conj<Coordenada> nuevo;

			typename Dicc<Coordenada, string>::Iterador it = dicc.CrearIt();
			while(it.HaySiguiente()){
				nuevo.AgregarRapido(it.SiguienteClave());
				it.Avanzar();
			}
			return nuevo;
		} 
		Conj< Nat > Juego::Claves(Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador > dicc){
			Conj<Nat> nuevo;
			typename Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador >::Iterador it = dicc.CrearIt();
			while(it.HaySiguiente()){
				nuevo.AgregarRapido(it.SiguienteClave());
				it.Avanzar();
			}
			return nuevo;
		} 


	    Vector<Vector<Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID >::Iterador> > > Juego::crearMatrizJug(Nat n, Nat m){
	    	Vector<Vector<Dicc<Nat, Coladeprioridad<Juego::capturadosyID >::Iterador> > > nuevo;
	    	return nuevo; 

	    }

		Vector<Vector<typename Juego::infoHeap> > Juego::crearMatrizPok(Nat n, Nat m){
			Vector<Vector<infoHeap> > nuevo;
			return nuevo;
		}


	Conj< typename Juego::capturadosyID> Juego::cercanos(Coordenada c){
		Conj<capturadosyID> nuevo;
		return nuevo;

	}

	bool Juego::HayUnJugadorCercano(Coordenada c){
		return false;

	}

	bool Juego::estaParaCaptura(Coordenada posDelJug){
		return false;

	}

	Coordenada Juego::BuscarHeap(Vector<Vector<infoHeap> >){
		Coordenada nueva;
		return nueva;

	}

	void Juego::AuxCapturarPokemon(Dicc<Coordenada, string>::Iterador it){

	}

	//Conj<T> Claves(Dicc<J,S>::Iterador); //Deberia estar en diccLineal.













//ITERADOR Y STRUCTS


Juego::Iterador::Iterador(const typename Juego::Iterador& otro)
  : elementos_(otro.elementos_), posicion_(otro.posicion_)
{}

typename Juego::Iterador& Juego::Iterador::operator= (const typename Juego::Iterador& otro)
{
  elementos_ = otro.elementos_;
  posicion_ = otro.posicion_;
  return *this;
}


bool Juego::Iterador::HaySiguiente(){
	Nat i = posicion_;
	bool hayAlguno = false;
	while(i < ((*elementos_).Longitud()) && (hayAlguno == false)){
		typename Juego::dataJugador  jugActual = (*elementos_)[i];
		if(jugActual.sanciones < 5){
			hayAlguno = true;
		}
		i++;
	}
	return hayAlguno;
}// const;
     
Nat Juego::Iterador::Siguiente(){
	Nat i = posicion_;
	Nat resAux;
	if(i != 0){
		resAux = i;
	}else{
		if((*elementos_)[i].sanciones < 5){
			resAux = i;
		}else{
		Avanzar();
		resAux = posicion_;
		}		
	}
	return resAux;
}

void Juego::Iterador::Avanzar(){
	Nat i = posicion_ + 1;
	bool tengoQueParar = false;
	while(i < ((*elementos_).Longitud()) && (tengoQueParar == false)){
		if((*elementos_)[i].sanciones < 5){
			tengoQueParar = true;
		}
	  i++;	
	}
	posicion_ = i-1;	
}





//Una tupla es menor a otra si tiene menos pokemons capturados. En caso de ser los mismo, es menor el de ID mas alto
bool Juego::capturadosyID::operator < (const capturadosyID& otra)
{
	if( numero < otra.numero ){
		return true;
	}
	if(numero > otra.numero){
		return false;
	}
	if( numero == otra.numero){
		return (ID > otra.ID);
	} 
  

  }








