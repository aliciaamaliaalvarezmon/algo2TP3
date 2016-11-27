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

      DiccString< Nat >::Iterador  Pokemons(Nat e);

       Conj<Nat> Expulsados();

      Conj<Coordenada>::Iterador posConPokemons(); 

       String pokemonEnPos(Coordenada c);

      Nat CantMovimientosParaCaptura(Coordenada c);

       Nat ProxID();

       Conj<Nat> JugadoresConectados();

       Nat indiceDeRareza(string p);

       Nat CantPokemonTotales();

       bool HayPokemonCercano(Coordenada c);

       Coordenada PosDePokemonCercano(Coordenada c);            

       Iterador CrearIt(); 

       	Nat matrizJUGADORESLongitud();//(pokcapturados, ID)
		Nat matrizPOKEMONLongtitud();
		Nat matrizJUGADORESLatitud();//(pokcapturados, ID)
		Nat matrizPOKEMONLatitud();

 
	private:	

		struct capturadosyID
		{
			Nat numero;
			Nat ID;

			capturadosyID(): numero(0), ID(0){}; 
			capturadosyID(Nat num, Nat i ): numero(num), ID(i){};			

			bool operator < (const typename Juego::capturadosyID& otra) const;
			bool operator == (const typename Juego::capturadosyID& otra) const;
			bool operator > (const typename Juego::capturadosyID& otra) const;
			//podria ser const al final


		};



		struct dataJugador
		{
			bool conexion;
			Nat sanciones;
			Coordenada posicion;
			Nat pokTotalAtrapados;
			Lista<DiccString<Nat> >::Iterador pokemonescapturados;
			Dicc<Nat, Coladeprioridad < typename Juego::capturadosyID >::Iterador>::Iterador posenColaDeCaptura;
			

			dataJugador()
			: conexion(0), sanciones(0), posicion(), pokTotalAtrapados(0), pokemonescapturados(), posenColaDeCaptura()
			{}
		

		};


		
		struct dataPokemon
		{
			Nat PS;
			Nat PC;	

			dataPokemon(): PS(0), PC(0){}; 
			dataPokemon(Nat s, Nat c): PS(s), PC(c){};
			
		};

		struct infoHeap
		{
			Coladeprioridad<typename Juego::capturadosyID> heap_;
			bool HayBasura_;
			Nat contador_;

			infoHeap(): heap_(), HayBasura_(true), contador_(0) {};//el haybasura, al poner el pokemon, pasa a ser false
		};

		Mapa mundo_;
		Vector<typename Juego::dataJugador> vectJug_;
		DiccString<typename Juego::dataPokemon> pokemones_;
		Vector<Vector<Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador> > > matrizJugadores_;//(pokcapturados, ID)
		Vector<Vector<typename Juego::infoHeap> > matrizPokemon_;
		Dicc<Coordenada, String> posdePokemon_;//(coordenada,pokemon)
		Lista<DiccString<Nat> > pokemonsXjug_;//puede estar dentro de data jugador
		Nat cantPokemon_;


		
		Vector<Vector<Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador> > > crearMatrizJug(Nat n, Nat m);

		Vector<Vector< typename Juego::infoHeap> > crearMatrizPok(Nat n, Nat m);
		
		Conj<typename Juego::capturadosyID> cercanos(Coordenada c);

		bool HayUnJugadorCercano(Coordenada c);

		bool estaParaCaptura(Coordenada posDelJug);

		Coordenada BuscarHeap(Coordenada c);

		void AuxCapturarPokemon(Dicc<Coordenada, string>::Iterador it);

		Conj<Coordenada> Claves(Dicc<Coordenada, string> dicc); //Deberia estar en diccLineal.
		Conj<Nat> Claves(Dicc<Nat, Coladeprioridad<typename Juego::capturadosyID>::Iterador > dicc); //Deberia estar en diccLineal.

		

	public:
   class Iterador
  		{
    	    public:     

      	Iterador(const typename Juego::Iterador& otro);

     	Iterador& operator = (const typename Juego::Iterador& otro);

      	bool HaySiguiente();// const;
     
      	Nat Siguiente();

     	void Avanzar();

      	//Iterador borrarSiguiente();//toma un iterador, lo inicializa con la cola que lo llamo, y agrega.

       	//void Agregar(const T& elem);
   


  	private:

    
    	//typename Juego::dataJugador
      	Vector<dataJugador>* elementos_;
      	Nat posicion_;


      	Iterador(){
        elementos_= NULL;
        posicion_ = 0;        
      }

      	Iterador(Vector<dataJugador>* jug){
      	elementos_ = jug;
      	posicion_ =  0;		
      	}
      

      friend typename Juego::Iterador Juego::CrearIt(); 
       
  };









		










	};
}



























#endif // AED2_JUEGO_H_INCLUDED