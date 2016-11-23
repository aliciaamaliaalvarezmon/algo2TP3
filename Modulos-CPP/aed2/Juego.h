#ifndef AED2_JUEGO_H_
#define AED2_JUEGO_H_

#include <ostream>
#include "TiposBasicos.h"

#include <ostream>
#include "TiposBasicos.h"
#include <string>
#include "DiccString.h"
#include "ColadeprioridadH.h"
#include "Mapa.h"
#include "Conj.h"
#include "Dicc.h"
#include "Vector.h"


using namespace std;
namespace aed2
{
	class Juego{
	public:
		class Iterador;
		Juego();
		Juego(Mapa m);
		//Juego(const Juego& otra); 
        //~Juego();

       Nat AgregarJugador();

       void AgregarPokemon(string p, Coordenada c);

       void conectarse(Nat e, Coordenada c);

       void desconectarse(Nat e);

       void moverse(Nat e, Coordenada c);

       Mapa VerMapa();

       Juego::Iterador Jugadores();

       bool estaConectado(Nat e);

       Nat sanciones(Nat e);

       Coordenada posicion(Nat e);

       DiccString< Nat >::Iterador  Pokemons(Nat e);//Conj<pokemon, nat>  /Aca deberia??? ser DiccString(Nat)::Iterador

       Conj<Nat> Expulsados();

       Conj<Coordenada>::Iterador posConPokemons();

       String pokemonEnPos(Coordenada c);

       Nat CantMovimientosParaCaptura(Coordenada c);

       Nat ProxID();

       Conj<Nat> JugadoresConectados();

        Nat indiceDeRareza(string p);

        Nat CantPokemonTotales();

       bool HayPokemonCercano(Coordenada c);

       Coordenada PosDePokemonCercano();     

       

       Iterador CrearIt(); 


    class Iterador
  		{
    	    public:     

      	//Iterador(const typename Coladeprioridad<T>::Iterador& otro);

     	 //Iterador& operator = (const typename Coladeprioridad<T>::iteradordor& otro);

      	bool HaySiguiente();// const;
     
      	T& Siguiente();

      	void Avanzar();

      	//Iterador borrarSiguiente();//toma un iterador, lo inicializa con la cola que lo llamo, y agrega.

       	//void Agregar(const T& elem);
   


  	private:

    
    	//typename Juego::dataJugador
      	Vector<typename Juego::dataJugador>* elementos_;
      	Nat posicion_;


      	Iterador(){
        elementos_= NULL;
        posicion_ = 0;        
      }

      	Iterador(Vector<typename Juego::dataJugador>* jug){
      	elementos_ = jug;
      	posicion_ =  0;		
      	}
      

      friend typename Juego::Iterador Juego::CrearIt(); 
       
  };

	private:	


		struct dataJugador
		{
			bool conexion;
			Nat sanciones;
			Coordenada posicion;
			Nat pokTotalAtrapados;
			Lista<DiccString<Nat> >::Iterador pokemonescapturados;
			Dicc<Nat, Coladeprioridad<pair<Nat, Nat> >::Iterador>::Iterador posenColaDeCaptura;

			dataJugador(){
				conexion = 0;
				sanciones = 0;
				Coordenada nueva;
				posicion = nueva;
				pokTotalAtrapados = 0;				
				Lista<DiccString<Nat> >::Iterador itsecu; //problema
				pokemonescapturados = itsecu;
				Dicc<Nat, Coladeprioridad<pair<Nat, Nat> >::Iterador>::Iterador itdicc;// (pokcap,ID)
				posenColaDeCaptura = itdicc;
			} 
		};

		struct dataPokemon
		{
			Nat PS;
			Nat PC;	

			dataPokemon(): PS(0), PC(0){}; 
			
		};

		struct infoHeap
		{
			Coladeprioridad<pair<Nat, Nat> > heap_;
			bool HayBasura_;
			Nat contador_;
		};

		Mapa mundo_;
		Vector<dataJugador> vectJug_;
		DiccString<typename Juego::dataPokemon> pokemones_;
		Vector<Vector<Dicc<Nat, Coladeprioridad<pair<Nat, Nat> >::Iterador> > > matrizJugadores_;//(pokcapturados, ID)
		Vector<Vector<infoHeap> > matrizPokemon_;
		Dicc<Coordenada, String> posdePokemon_;//(coordenada,pokemon)
		Lista<DiccString<Nat> > pokemonsXjug_;//puede estar dentro de data jugador
		Nat cantPokemon_;



		Vector<Vector<Dicc<Nat, Coladeprioridad<pair<Nat, Nat> >::Iterador> > > crearMatrizJug(Nat n, Nat m);

		Vector<Vector<infoHeap> > crearMatrizPok(Nat n, Nat m);
		/*
		Conj<pair<nat, ID>> cercanos(Coordenada c);

		bool HayUnJugadorCercano(Coordenada c);

		bool estaParaCaptura(Coordenada posDelJug);

		Coordenada BuscarHeap(vector<vector<infoHeap>>);

		void AuxCapturarPokemon(Dicc<Coor, pokemon>::Iterador it);

		Conj<T> Claves(Dicc<J,S>::Iterador); //Deberia estar en diccLineal.

		*/





		










	};
}



























#endif // AED2_JUEGO_H_INCLUDED