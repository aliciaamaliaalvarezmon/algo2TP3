#include "Juego.h"



using namespace aed2;




Juego::Juego()
	: mundo_(), vectJug_(), pokemones_(), matrizJugadores_(), matrizPokemon_(), posdePokemon_(), pokemonsXjug_(), cantPokemon_(0){}
	
	
	Juego::Juego(Mapa m)	
		: mundo_(m), vectJug_(), pokemones_(), posdePokemon_(), pokemonsXjug_(), cantPokemon_(0)
	{
		matrizPokemon_ = crearMatrizPok(m.longitudMaxima(), m.latitudMaxima());
		matrizJugadores_ = crearMatrizJug(m.longitudMaxima(), m.latitudMaxima());
	}	
	
	
	
	Nat Juego::AgregarJugador(){
		dataJugador nuevo;
		DiccString<Nat> vacio;
		Lista<DiccString<Nat> >::Iterador iter = pokemonsXjug_.AgregarAtras(vacio);
		nuevo.pokemonescapturados = iter;
		vectJug_.AgregarAtras(nuevo);		
		return (vectJug_.Longitud() - 1);		
	}
	
	void Juego::AgregarPokemon(string p, Coordenada c){
		//Dicc<Coordenada, String>::Iterador ju = (posdePokemon_).DefinirRapido(c,p);
	(posdePokemon_).DefinirRapido(c,p);		
	Conj<typename Juego::capturadosyID> entrenadores = cercanos(c);// jajajajaja, podemos romper todo.			
	cout << entrenadores.Cardinal() << "cantidad de entrenadores para captura" <<endl;
	if(!pokemones_.Definido(p)) {
		pokemones_.Definir(p, dataPokemon(1,0));			
	}else{			
		pokemones_.Obtener(p).PS++;			 
	}
	//agregamos pokemon a pokemones
	typename Juego::infoHeap heap;		
	matrizPokemon_[c.longitud()][c.latitud()] = heap;		
	Coladeprioridad<typename Juego::capturadosyID>* rompe = &(matrizPokemon_[c.longitud()][c.latitud()].heap_);
	matrizPokemon_[c.longitud()][c.latitud()].HayBasura_ = false;
	//typename Juego::capturadosyID datacero(0,0);
	//typename Juego::capturadosyID datauno(0,1);
	//typename Juego::capturadosyID datados(0,2);
	//cout<< "Luis tiene razon"<< entrenadores.Pertenece(datacero) << " uno  " <<   entrenadores.Pertenece(datauno)  << "dos" << entrenadores.Pertenece(datados) << endl;	
	Conj<typename Juego::capturadosyID>::Iterador it = entrenadores.CrearIt();
	while(it.HaySiguiente()){
		Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador>* hola = (&(matrizJugadores_[vectJug_[it.Siguiente().ID].posicion.longitud()][vectJug_[it.Siguiente().ID].posicion.latitud()]));			
		//cout << "posiciones bien" << vectJug_[it.Siguiente().ID].posicion.latitud() <<", "<< vectJug_[it.Siguiente().ID].posicion.longitud() << endl;
		Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador>::Iterador poscola = (*hola).DefinirRapido(it.Siguiente().ID, (*rompe).Encolar(it.Siguiente()));
		//cout <<"iterador"<< it.Siguiente().ID << endl;
		//cout <<"Luis"<< matrizPokemon_[c.longitud()][c.latitud()].heap_.tope().ID << endl;			
		//vectJug_[it.Siguiente().ID].posenColaDeCaptura = matrizJugadores_[vectJug_[it.Siguiente().ID].posicion.longitud()][vectJug_[it.Siguiente().ID].posicion.latitud()].DefinirRapido(it.Siguiente().ID, (*rompe).Encolar(it.Siguiente));
		vectJug_[it.Siguiente().ID].posenColaDeCaptura = poscola;
		it.Avanzar();			
	}
	//cout <<"Luisfinal"<< matrizPokemon_[c.longitud()][c.latitud()].heap_.tope().ID << endl;
	//cout <<"Luisfinal"<< (*(*(matrizPokemon_[c.longitud()][c.latitud()].heap_.HEAP())).IZQUIERDA()).Dato().ID << endl;
	//cout <<"Luisfinal"<< (*(*(matrizPokemon_[c.longitud()][c.latitud()].heap_.HEAP())).DERECHA()).Dato().ID << endl;
	
	//cout << "sera, sera"<< HayUnJugadorCercano(c) << endl; 
	cantPokemon_ ++;		
	}
	
	void Juego::conectarse(Nat e, Coordenada c){
		vectJug_[e].conexion = true;	
		Coladeprioridad<typename Juego::capturadosyID> nueva;
		Coladeprioridad<typename Juego::capturadosyID>::Iterador dummy = nueva.CrearIt();			
		if(estaParaCaptura(c)){			
			Coordenada ACapturar = BuscarHeap(c);
			cout << "llega" << ACapturar.latitud() <<", "<< ACapturar.longitud() << endl;
			typename Juego::capturadosyID espera(vectJug_[e].pokTotalAtrapados, e);						
			typename Coladeprioridad<typename Juego::capturadosyID>::Iterador iteradoralheap = (matrizPokemon_[ACapturar.longitud()][ACapturar.latitud()].heap_).Encolar(espera);		
			//cout << "iteradoralheap  " << iteradoralheap.Siguiente().numero << ", "<< iteradoralheap.Siguiente().ID << endl;
			vectJug_[e].posenColaDeCaptura = matrizJugadores_[c.longitud()][c.latitud()].DefinirRapido(e, iteradoralheap );
			cout <<"funciono" << vectJug_[e].posenColaDeCaptura.SiguienteClave() << endl;
			cout <<"funciono" << vectJug_[e].posenColaDeCaptura.SiguienteSignificado().Siguiente().ID << endl;
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
		if(vectJug_[e].posenColaDeCaptura.HaySiguiente()){
			vectJug_[e].posenColaDeCaptura.EliminarSiguiente(); //elimino de la matriz Jugador
		}
		
	}
	
	void Juego::moverse(Nat e, Coordenada c){
		Coordenada antiguaPos =  vectJug_[e].posicion; 
		if (not( antiguaPos.distEuclidea(c) > 100 or not mundo_.hayCamino(antiguaPos,c))){	
			vectJug_[e].posicion = c ;
			if(estaParaCaptura(antiguaPos)){
				Coordenada AntiguoHeap = BuscarHeap(antiguaPos); 
				Coladeprioridad<typename Juego::capturadosyID> heap = matrizPokemon_[AntiguoHeap.latitud()][AntiguoHeap.longitud()].heap_;
				(vectJug_[e].posenColaDeCaptura.SiguienteSignificado()).borrarSiguiente();
			} 
			if(estaParaCaptura(c)){
				Coordenada VoyACapturarEste = BuscarHeap(c);
				Coladeprioridad<typename Juego::capturadosyID> heap =  ((matrizPokemon_[VoyACapturarEste.latitud()][VoyACapturarEste.longitud()]).heap_); 
				typename Juego:: capturadosyID captura;
				captura.numero = vectJug_[e].pokTotalAtrapados;
				captura.ID = e;
				Coladeprioridad<typename Juego::capturadosyID>::Iterador iteradorAlHeap = heap.Encolar(captura); 
				Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador>::Iterador  posencola = matrizJugadores_[c.latitud()][c.longitud()].Definir(e,iteradorAlHeap);        
				vectJug_[e].posenColaDeCaptura = posencola;   
			}
			if(HayPokemonCercano(c) && HayPokemonCercano(antiguaPos)){
				if (not(BuscarHeap(c) == BuscarHeap(antiguaPos))){
					Coordenada PosDePokemon = BuscarHeap(c);
					(matrizPokemon_[PosDePokemon.latitud()][PosDePokemon.longitud()]).contador_  = 0; 
				}
			}
			else
			{
				if(HayPokemonCercano(c)){
					Coordenada PosDePokemon = BuscarHeap(c); 
					(matrizPokemon_[PosDePokemon.latitud()][PosDePokemon.longitud()]).contador_  = 0;
				}
			}
			/*Coordenada PosDePokemon = BuscarHeap(c);*/ 
			Dicc<Coordenada,String>::Iterador it = posdePokemon_.CrearIt(); 
			while(it.HaySiguiente()){ 
				if(HayPokemonCercano(c) && not(PosDePokemonCercano(c) == it.SiguienteClave())){
					Coordenada posPokemon   = it.SiguienteClave();
					infoHeap& posActual = matrizPokemon_[posPokemon.latitud()][posPokemon.longitud()];
					if(HayUnJugadorCercano(it.SiguienteClave())){
						(posActual).contador_ += 1;
//						cout << ((posActual).contador_) <<endl;
					}
					if((posActual).contador_ ==10){
						AuxCapturarPokemon(it) ;
						it.EliminarSiguiente();
					}
				}
				else
				{ 
					Coordenada posPokemon  = it.SiguienteClave();
					infoHeap& posActual = matrizPokemon_[posPokemon.latitud()][posPokemon.longitud()];
					if (not HayPokemonCercano(c)){ 
						if(HayUnJugadorCercano(it.SiguienteClave())){
//							cout << (posActual).contador_ <<endl;
							(posActual).contador_ += 1;
						}
					}
					if((posActual).contador_ ==10){ 
						AuxCapturarPokemon(it);
						
					}
					
				}
				it.Avanzar();
			}
		}
		if( antiguaPos.distEuclidea(c) > 100 or not mundo_.hayCamino(antiguaPos,c)){
			vectJug_[e].sanciones = vectJug_[e].sanciones+1;
			if(vectJug_[e].sanciones==5){
				if(HayPokemonCercano(c)){
					Coordenada VoyACapturarEste = BuscarHeap(c);
					if(mundo_.hayCamino(VoyACapturarEste,c)){ 
						Coladeprioridad<typename Juego::capturadosyID>	heap = matrizPokemon_[VoyACapturarEste.latitud()][VoyACapturarEste.longitud()].heap_;
						//(heap, vectJug_[e].posenColaDeCaptura.SiguienteSignificado()).borrarSiguiente();
						(vectJug_[e].posenColaDeCaptura.SiguienteSignificado()).borrarSiguiente();
					}
				}
				cantPokemon_ = cantPokemon_ - vectJug_[e].pokTotalAtrapados; 
				vectJug_[e].conexion = false; 
				vectJug_[e].posicion = Coordenada(0,0);
				DiccString<Nat>::Iterador itapokecap = (vectJug_[e].pokemonescapturados.Siguiente()).CrearIt();
				while(itapokecap.HaySiguiente()){ 
					dataPokemon& pok = pokemones_.Obtener(itapokecap.SiguienteClave());
					pok.PC = pok.PC - itapokecap.SiguienteSignificado(); 
					if(pok.PS ==0 and pok.PC==0){ 
						pokemones_.Borrar(itapokecap.SiguienteClave());
					}
					itapokecap.Avanzar();
				}
				
			}
		}
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
	
	
	
	Conj<Coordenada>::Iterador Juego::posConPokemons(Conj<Coordenada>& dummy){
		
		//return nuevo;	  		
		//cout << "antes dummy" << dummy.Cardinal()<< endl;  	
		Claves(posdePokemon_, dummy);	 
		//cout << "desues dummy" << dummy.Cardinal()<< endl;  	 
		Conj<Coordenada>::Iterador nuevo = dummy.CrearIt();	  	
		cout << "iterador"<<nuevo.Siguiente().latitud() << nuevo.Siguiente().longitud() << endl;
		return nuevo;
		
	}
	
	String Juego::pokemonEnPos(Coordenada c){
		//return "falla";
		return posdePokemon_.Significado(c);
		
	}
	
	Nat Juego::CantMovimientosParaCaptura(Coordenada c){
		//return 9;
		return 10-matrizPokemon_[c.longitud()][c.latitud()].contador_;
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
			if((vectJug_[i].sanciones < 5) and (vectJug_[i].conexion)){
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
		return 100 - ((100 * cant)/cantPokemon_);
	}
	
	
	Nat Juego::CantPokemonTotales(){
		return cantPokemon_;
	}
	
	bool Juego::HayPokemonCercano(Coordenada c){	     	
		bool res = false;
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
			while( (j <= c.latitud() + 2) and (res == false)){	
				Coordenada ver(j,i);										
				if(ver.longitud() < mundo_.longitudMaxima() and ver.latitud() < mundo_.latitudMaxima()){
					bool a = mundo_.posEnMapa(ver);					
					bool b = (c.distEuclidea(ver) <= 4);						
					bool d = (!(matrizPokemon_[ver.longitud()][ver.latitud()].HayBasura_));
					bool e = mundo_.hayCamino(c, ver);
					//cout << "ver: "<< ver.latitud() <<", " << ver.longitud() << endl;
					//cout << "posEnMapa  " << a <<"distancia " << b << "Basura " << d << "camino "<< e << endl;						
					if( a and b and d and e){
						res = true;
					}
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
				if(ver.longitud() < mundo_.longitudMaxima() and ver.latitud() < mundo_.latitudMaxima()){
					bool a = mundo_.posEnMapa(c);
					bool b = (c.distEuclidea(ver) <= 4);
					bool d = (!(matrizPokemon_[ver.longitud()][ver.latitud()].HayBasura_));
					Coordenada prue(1,1);
					//cout << "ver" << ver.latitud() <<"," <<ver.longitud() <<"," << matrizPokemon_[ver.longitud()][ver.latitud()].HayBasura_ << endl;
					//cout<< "hay camino: " << mundo_.hayCamino(c, ver) << endl;
					bool e = mundo_.hayCamino(c, ver);
					if(a and b and d and e){
						aux = true;
						nueva = ver;
					}
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
	
	
	void Juego::Claves(Dicc<Coordenada, string> dicc, Conj<Coordenada>& vacio){
		//Conj<Coordenada> nuevo;			
		typename Dicc<Coordenada, string>::Iterador it = dicc.CrearIt();			
		while(it.HaySiguiente()){
			//cout << "Cantidad de claves" << posdePokemon_.CantClaves() << endl;
			//cout << "claves " << it.SiguienteClave().latitud() << ", " << it.SiguienteClave().longitud() <<endl;
			vacio.AgregarRapido(it.SiguienteClave());				
			it.Avanzar();				
		}			
	} 
	/*
	Conj< Coordenada > Juego::Claves(Dicc<Coordenada, string> dicc){
	//Conj<Coordenada> nuevo;
	
	typename Dicc<Coordenada, string>::Iterador it = dicc.CrearIt();			
	while(it.HaySiguiente()){
	//cout << "Cantidad de claves" << posdePokemon_.CantClaves() << endl;
	//cout << "claves " << it.SiguienteClave().latitud() << ", " << it.SiguienteClave().longitud() <<endl;
	nuevo.AgregarRapido(it.SiguienteClave());				
	it.Avanzar();
	//cout << "candinal" << nuevo.Cardinal() << endl;
	}
	while(cantidaddeclaves > 0){				
	cout << "claves " << it.SiguienteClave().latitud() << ", " << it.SiguienteClave().longitud() <<endl;
	nuevo.AgregarRapido(it.SiguienteClave());
	it.Avanzar();
	cantidaddeclaves--;
	}	
	
	//return nuevo;
	} */
	
	
	void Juego::Claves(Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador > dicc, Conj<Nat>& vacio){			
		typename Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador >::Iterador it = dicc.CrearIt();
		while(it.HaySiguiente()){
			vacio.AgregarRapido(it.SiguienteClave());//AgregarRapido
			it.Avanzar();
		}			
	} 
	
	/*
	Conj< Nat > Juego::Claves(Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador > dicc){
	Conj<Nat> nuevo;
	typename Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador >::Iterador it = dicc.CrearIt();
	while(it.HaySiguiente()){
	nuevo.Agregar(it.SiguienteClave());//AgregarRapido
	it.Avanzar();
	}
	return nuevo;
	} 
	*/
	
	
	
	
	
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
			nuevo.AgregarAtras(posiciones);
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
				if(ver.longitud() < mundo_.longitudMaxima() and ver.latitud() < mundo_.latitudMaxima()){
					bool a = (mundo_.posEnMapa(ver)); //puede fallar				
					bool b = (c.distEuclidea(ver) <= 4);
					Conj<Nat> dummy;
					Claves(matrizJugadores_[ver.longitud()][ver.latitud()], dummy);				
					bool d = (!(dummy.EsVacio()));
					bool e = mundo_.hayCamino(ver, c);
					if(a and b and d and e){
						//Conj<Nat>::Iterador it = (Claves((matrizJugadores_[ver.longitud()][ver.latitud()]))).CrearIt();
						Conj<Nat>::Iterador it = dummy.CrearIt();
						while (it.HaySiguiente()){
							typename Juego::capturadosyID hola(vectJug_[it.Siguiente()].pokTotalAtrapados ,it.Siguiente() );
							nuevo.AgregarRapido(hola);
							it.Avanzar();
						}					
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
				if(ver.longitud() < mundo_.longitudMaxima() and ver.latitud() < mundo_.latitudMaxima()){
					bool a = (mundo_.posEnMapa(ver)); //puede fallar
					bool b = (c.distEuclidea(ver) <= 4);
					bool d = ((matrizJugadores_[ver.longitud()][ver.latitud()]).CantClaves() > 0);
					bool e = mundo_.hayCamino(ver, c);
					//cout << "ver" << ver.latitud() <<"," <<ver.longitud() <<",posenMapa? " << a << "esta" << d << endl;
					//cout<< "hay camino: " << mundo_.hayCamino(c, ver) << endl;
					if(a and b and d and e){
						aux = true;
					}
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
		while((i<= c.longitud() +2) and (AunNoLoEncontre == false)){
			if(c.latitud() < 2){
				j = 0; 
			}else{
				j = c.latitud() -2;
			}
			while((j<= c.latitud() +2) and (AunNoLoEncontre == false)){
				Coordenada ver(j,i);				
				if(ver.longitud() < mundo_.longitudMaxima() and ver.latitud() < mundo_.latitudMaxima()){				
					if(mundo_.posEnMapa(ver) and c.distEuclidea(ver) <= 4){								
						if((matrizPokemon_[i][j].HayBasura_) == false){										
							nueva =  ver;						
							AunNoLoEncontre = true;
						}
					}
				}
				j++;
			}
			i++;
		}				
		return nueva;
		
	}
	
	
	
	void Juego::AuxCapturarPokemon(Dicc<Coordenada, string>::Iterador it){
		cout << "finalyolo2" <<endl;
		infoHeap& dameLaData = matrizPokemon_[it.SiguienteClave().latitud()][it.SiguienteClave().longitud()];
		cout << "finalyolo3" <<endl;
//		cout << (((dameLaData).heap_).EsVacia()) <<endl;
		dataJugador& jugador = vectJug_[(((dameLaData).heap_).tope()).ID];
		cout << "finalyolo4" <<endl;
		if(not ((jugador.pokemonescapturados).Siguiente()).Definido(it.SiguienteSignificado())){ 
			
			(jugador.pokemonescapturados.Siguiente()).Definir(it.SiguienteSignificado(),1);
		}
		else
		{
			
			(jugador.pokemonescapturados.Siguiente()).Definir(it.SiguienteSignificado(),(jugador.pokemonescapturados.Siguiente()).Obtener(it.SiguienteSignificado())+1);
			cout << "finalyolo1" <<endl;
		}	
		dataPokemon& BuscarEnElTrie = pokemones_.Obtener(it.SiguienteSignificado()); 
		BuscarEnElTrie.PS = (BuscarEnElTrie.PS)-1; 
		BuscarEnElTrie.PC = (BuscarEnElTrie.PC)+1;
		Coladeprioridad<typename Juego::capturadosyID> dummy;
		Dicc<Coordenada,string> pokpos;
		Dicc<Coordenada,string>::Iterador itpos = pokpos.CrearIt();
		matrizPokemon_[it.SiguienteClave().longitud()][it.SiguienteClave().latitud()].heap_ = dummy;
		matrizPokemon_[it.SiguienteClave().longitud()][it.SiguienteClave().latitud()].HayBasura_= true;
		matrizPokemon_[it.SiguienteClave().longitud()][it.SiguienteClave().latitud()].contador_ = 0;
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
	
	/*
	bool Juego::EstaParaCaptura(Coordenada c){
	if(HayPokemonCercano(c)){
	Coordenada poke = BuscarHeap(c);
	return this->mundo_.hayCamino(c,poke);
	}else{
	return false;
	}
	}
	*/
	
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
	
	
	
	//TESTING
	
	
	
	Nat Juego::matrizJUGADORESLongitud(){
		return matrizJugadores_.Longitud();
	}//(pokcapturados, ID)
	
	
	
	Nat Juego::matrizPOKEMONLongtitud(){
		return matrizPokemon_.Longitud();
	}
	
	Nat Juego::matrizJUGADORESLatitud(){
		return matrizJugadores_[0].Longitud();
	}//(pokcapturados, ID)
	
	
	
	Nat Juego::matrizPOKEMONLatitud(){
		return matrizPokemon_[0].Longitud();
	}
	
	
