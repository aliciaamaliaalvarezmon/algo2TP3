/* ========================================================================================
 * Implementación del módulo Mapa - Notas:
 * ---------------------------------------
 * 
 * 13/11/2016: Los tipos 'Coordenada&' 'Conj<Coordenada>&' no son de tipo const. 
 *			   Habría que considerar el ponerlos. De momento los saco xq tira 
 *			   errores de compilación.
 *
 *			   La función 'hayCaminoQ' equivale a 'hayCamino?' del módulo Mapa.
 *
 * ========================================================================================
 */


#include <string>
#include <ostream>
#include <iostream>
#include "Coordenada.h"
#include "Conj.h" //"Modulos-CPP/aed2/Conj.h"
#include "Vector.h" //"Modulos-CPP/aed2/Vector.h"

using namespace std;
using namespace aed2;

class Mapa{
	public:
		// Genera un mapa vacío.
		Mapa();

		// Agrega la coordenada al mapa.
		void agregarCoord(Coordenada& c);

		// Devuelve ancho de mapa.
		const Nat& longitudMaxima() const;

		// Devuelve altura de mapa.
		const Nat& latitudMaxima() const;

		// Devuelve las coordenadas del mapa.
		const Conj<Coordenada>& coordenadasMapa() const;

		// Dice si la coordenada pertenece al conjunto de coordenadas del mapa.
		bool posExiste(Coordenada& c) const;

		// Devuelve true si los dos caminos estan conectados.
		bool hayCamino(Coordenada& c, Coordenada& c2) const; 

		// Devuelve true si existe un camino que conecte a las coordenadas.
		bool hayCaminoQ(Coordenada& c, Nat i, Nat j, Conj<Coordenada>& cs) const;

		// Devuelve true si existe un camino que conecte a las coordenadas por arriba.
		bool existeCaminoPorArriba(Coordenada& c, Conj<Coordenada>& cs) const;

		// Devuelve true si existe un camino que conecte a las coordenadas por abajo.
		bool existeCaminoPorAbajo(Coordenada& c, Conj<Coordenada>& cs) const;

		// Devuelve true si existe un camino que conecte a las coordenadas por derecha.
		bool existeCaminoPorDerecha(Coordenada& c, Conj<Coordenada>& cs) const;

		// Devuelve true si existe un camino que conecte a las coordenadas por izquierda.
		bool existeCaminoPorIzquierda(Coordenada& c, Conj<Coordenada>& cs) const;

		// Crea una matriz con las coordenadas del mapa.
		Vector<Vector<bool> > crearMatrizMapa(Coordenada& c) const;

	private:
		Vector<Vector<Vector<Vector<bool> >*> > matriz;
		Nat longitudmaxima;
		Nat latitudmaxima;
		Conj<Coordenada> coordenadas;

};

