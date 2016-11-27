#include "Juego.h"



using namespace aed2;




Juego::Juego()
	: mundo_(), vectJug_(), pokemones_(), matrizJugadores_(), matrizPokemon_(), posdePokemon_(), pokemonsXjug_(), cantPokemon_(0){}
	

Juego::Juego(Mapa m)	
	: mundo_(m), vectJug_(), pokemones_(), posdePokemon_(), pokemonsXjug_(), cantPokemon_(0)
	{
		matrizPokemon_ = crearMatrizPok(m.longitudMaxima(), m.longitudMaxima());
		matrizJugadores_ = crearMatrizJug(m.longitudMaxima(), m.latitudMaxima());
	}	



	Nat Juego::AgregarJugador(){
		dataJugador nuevo;
		vectJug_.AgregarAtras(nuevo);
		return (vectJug_.Longitud() - 1);		
	}

	void Juego::AgregarPokemon(string p, Coordenada c){
		Dicc<Coordenada, String>::Iterador ju = (posdePokemon_).DefinirRapido(c,p);
		Conj<capturadosyID> entrenadores = cercanos(c);// jajajajaja, podemos romper todo.		
		if(!pokemones_.Definido(p)) {
			pokemones_.Definir(p, dataPokemon(1,0));			
		}else{			
			pokemones_.Obtener(p).PS++;			 
		}
		//agregamos pokemon a pokemones
		typename Juego::infoHeap heap;
		matrizPokemon_[c.longitud()][c.latitud()] = heap;
		Coladeprioridad<typename Juego::capturadosyID>* rompe = &(matrizPokemon_[c.longitud()][c.latitud()].heap_);
		Conj<typename Juego::capturadosyID>::Iterador it = entrenadores.CrearIt();

		while(it.HaySiguiente()){
		//	vectJug_[it.Siguiente().ID].posenColaDeCaptura = matrizJugadores_[vectJug_[it.Siguiente().ID].posicion.longitud()][vectJug_[it.Siguiente().ID].posicion.latitud()].DefinirRapido(it.Siguiente().ID, (*rompe).Encolar(it.Siguiente));
			it.Avanzar();
		}
		cantPokemon_ ++;
	}

	void Juego::conectarse(Nat e, Coordenada c){
		vectJug_[e].conexion = true;	
		Coladeprioridad<typename Juego::capturadosyID> nueva;
		Coladeprioridad<typename Juego::capturadosyID>::Iterador dummy = nueva.CrearIt();	
		if(estaParaCaptura(c)){
			Coordenada ACapturar = BuscarHeap(c);
			typename Juego::capturadosyID espera(vectJug_[e].pokTotalAtrapados, e);
			typename Coladeprioridad<typename Juego::capturadosyID>::Iterador iteradoralheap = (matrizPokemon_[ACapturar.longitud()][ACapturar.latitud()].heap_).Encolar(espera);
			vectJug_[e].posenColaDeCaptura = matrizJugadores_[c.longitud()][c.latitud()].DefinirRapido(e, iteradoralheap );
		}else{
		matrizJugadores_[c.longitud()][c.latitud()].DefinirRapido(e, dummy);
		}	
		if(HayPokemonCercano(c)){
			Coordenada PosdePokemon = BuscarHeap(c);
			matrizPokemon_[PosdePokemon.longitud()][PosdePokemon.latitud()].contador_ = 0;
		}
		vectJug_[e].posicion = c;
	}

	void Juego::desconectarse(Nat e){
		vectJug_[e].conexion = false;
		Coordenada c = vectJug_[e].posicion;
		if(estaParaCaptura(c)){			
			vectJug_[e].posenColaDeCaptura.SiguienteSignificado().borrarSiguiente();//elimino de la cola la pos			
		}
		vectJug_[e].posenColaDeCaptura.EliminarSiguiente(); //elimino de la matriz Jugador

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
	  	DiccString< Nat >::Iterador it;
	  	if(vectJug_[e].pokemonescapturados.HaySiguiente()){
	  	 it = vectJug_[e].pokemonescapturados.Siguiente().CrearIt();
	  	}
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
	     	bool res;
			Nat i;
			if (c.longitud() < 2){
				i = 0;
			}else{
				i = c.longitud() -2;			
			}
			Nat j;		
			while( (i <= c.longitud() + 2) and (res == false)){
				if (c.latitud() < 2){
					j = 0;
				}else{
					j = c.latitud() -2;
				}
				while( (j <= c.latitud() + 2)and (res == false)){
					Coordenada ver(j,i);
					bool a = mundo_.posEnMapa(ver);
					bool b = (c.distEuclidea(ver) <= 4);
					bool d = (!(matrizPokemon_[ver.longitud()][ver.latitud()].HayBasura_));
					bool e = mundo_.hayCamino(c, ver);
					if( a and b and d and e){
						res = true;
					}
					j++;
				}
				i++;
			}
	     	return res;
	     }

	     Coordenada Juego::PosDePokemonCercano(Coordenada c){	     	
	     	Coordenada nueva;
	     	bool aux = false;
	     	Nat i = 0;
	     	if (c.longitud() < 2){
				i = 0;
			}else{
				i = c.longitud() -2;			
			}
			Nat j;		
			while( (i <= c.longitud() + 2) and (aux == false)){
				if (c.latitud() < 2){
					j = 0;
				}else{
					j = c.latitud() -2;
				}
				while( (j <= c.latitud() + 2)and (aux == false)){
					Coordenada ver(j,i);
					bool a = mundo_.posEnMapa(c);
					bool b = (c.distEuclidea(ver) <= 4);
					bool d = (!(matrizPokemon_[ver.longitud()][ver.latitud()].HayBasura_));
					bool e = mundo_.hayCamino(c, ver);
					if(a and b and d and e){
						aux = true;
						nueva = ver;
					}
					j++;
				}
				i++;
			}
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


	    Vector<Vector<Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID >::Iterador> > > Juego::crearMatrizJug(Nat lon, Nat lat){
	    	Nat i = 0;
	    	Vector<Vector<Dicc<Nat, Coladeprioridad<Juego::capturadosyID >::Iterador> > > nuevo;
	    	while(i < lon){
	    		Vector<Dicc<Nat, Coladeprioridad<Juego::capturadosyID >::Iterador> > posiciones;
	    		Nat j = 0;
	    		while(j < lat){
	    			Dicc<Nat, Coladeprioridad<Juego::capturadosyID >::Iterador> dicc;
	    			posiciones.AgregarAtras(dicc);
	    			j++;
	    		}
	    		nuevo.AgregarAtras(posiciones);
	    		i++;
	    	}
	    	return nuevo;
	    	 

	    }

		Vector<Vector<typename Juego::infoHeap> > Juego::crearMatrizPok(Nat lon, Nat lat){
			Nat i = 0;			
			Vector<Vector<infoHeap> > nuevo;
			while(i < lon){
				Vector<infoHeap> posiciones;
				Nat j= 0;
				while(j < lat){
					typename Juego::infoHeap dummy;
					posiciones.AgregarAtras(dummy);
					j++;
				}
				i++;
			}
			return nuevo;
		}


	Conj< typename Juego::capturadosyID> Juego::cercanos(Coordenada c){
		Conj<typename Juego::capturadosyID> nuevo;
		Nat i;
		if (c.longitud() < 2){
			i = 0;
		}else{
			i = c.longitud() -2;			
		}
		Nat j;		
		while( i <= c.longitud() + 2){
			if (c.latitud() < 2){
				j = 0;
			}else{
				j = c.latitud() -2;
			}
			while(j <= c.latitud() + 2){
				Coordenada ver(j,i);
				bool a = (mundo_.posEnMapa(ver)); //puede fallar				
				bool b = (c.distEuclidea(ver) <= 4);				
				bool d = (!(Claves(matrizJugadores_[ver.longitud()][ver.latitud()]).EsVacio()));
				bool e = mundo_.hayCamino(ver, c);
				if(a and b and d and e){
					Conj<Nat>::Iterador it = (Claves((matrizJugadores_[ver.longitud()][ver.latitud()]))).CrearIt();
					while (it.HaySiguiente()){
						typename Juego::capturadosyID hola(vectJug_[it.Siguiente()].pokTotalAtrapados ,it.Siguiente() );
						nuevo.AgregarRapido(hola);
						it.Avanzar();
					}					
				}
				j++;
			}
			i++;
		}

		return nuevo;

	}

	bool Juego::HayUnJugadorCercano(Coordenada c){
		Conj<typename Juego::capturadosyID> nuevo;
		Nat i;
		if(c.longitud() < 2){
			 i = 0;
		}else{
			i = c.longitud()-2;
		}
		Nat j = 0;	
		bool aux = false;
		while(i < c.longitud() + 2){
			if(c.latitud() < 2){
				j = 0; 
			}else{
				j = c.latitud() -2;
			}
			while(j < c.latitud() + 2 ){
				Coordenada ver(j,i);
				bool a = (mundo_.posEnMapa(ver)); //puede fallar
				bool b = (c.distEuclidea(ver) <= 4);
				bool d = ((matrizJugadores_[ver.longitud()][ver.latitud()]).CantClaves() > 0);
				bool e = mundo_.hayCamino(ver, c);
				if(a and b and d and e){
					aux = true;
				}
				j++;
			}
			i++;
		}
		return aux;

	}

	bool Juego::estaParaCaptura(Coordenada posDelJug){
		//pareciera que faltara revisar el contador.
		bool res = false;
		if(HayPokemonCercano(posDelJug)){
			Coordenada posDelPoke = BuscarHeap(posDelJug);
			res = mundo_.hayCamino(posDelJug, posDelPoke);			
		}		
		return res;

	}

	Coordenada Juego::BuscarHeap(Coordenada c){
		Coordenada nueva;
		Nat i;
		bool AunNoLoEncontre = false;
		if(c.longitud() < 2){
			 i = 0;
		}else{
			i = c.longitud()-2;
		}
		Nat j = 0;	
		while((i<= c.longitud() +2) and (!AunNoLoEncontre)){
			if(c.latitud() < 2){
				j = 0; 
			}else{
				j = c.latitud() -2;
			}
			while((j<= c.latitud() +2) and (!AunNoLoEncontre)){
				Coordenada ver(j,i);
				if(mundo_.posEnMapa(ver) and c.distEuclidea(ver) <= 4){
					if(!(matrizPokemon_[c.longitud()][c.latitud()].HayBasura_)){
						Coordenada esEsta(j,i);
						nueva =  esEsta;
						AunNoLoEncontre = true;
					}
				}
				j++;
			}
			i++;
		}
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
bool Juego::capturadosyID::operator < (const typename Juego::capturadosyID& otra) const
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

bool Juego::capturadosyID::operator == (const typename Juego::capturadosyID& otra) const
{
	return (numero == otra.numero) and  (ID == otra.ID);
  

  }






bool Juego::capturadosyID::operator > (const typename Juego::capturadosyID& otra) const
{
	return ((((*this) < otra) == false ) and (((*this) == otra) == false));

  }





