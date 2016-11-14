#include "Mapa.h"

Mapa::Mapa() : longitudmaxima(0), latitudmaxima(0) {}
/*CONSULTA: esta bien inicializarlo así?*/

void Mapa::agregarCoord(Coordenada& c){
	coordenadas.AgregarRapido(c);

	if (c.longitud() >= this->longitudmaxima){
		while(this->longitudmaxima <= c.longitud()){
			Vector<Vector<Vector<bool> >*>* nuevo;
			Nat i = 0; 
			while (i < this->latitudmaxima){
				Vector<Vector<bool> >* posVacia = NULL;
				nuevo->AgregarAtras(posVacia);
				i++;
			}
		this->matriz.AgregarAtras((*nuevo));
		this->longitudmaxima++;
		}
	}

	if (c.latitud() >= this->latitudmaxima){
		while (this->latitudmaxima <= c.latitud()){
			Nat j = 0; 
			while (j < this->longitudmaxima){
				Vector<Vector<bool> >* nuevaPos = NULL;
				this->matriz[j].AgregarAtras(nuevaPos);
				j++;
			}
			this->latitudmaxima++;
		}
	}
	(*this->matriz[c.longitud()][c.latitud()]) = this->crearMatrizMapa(c);
}

const Nat& Mapa::longitudMaxima() const {
	return longitudmaxima;
}

const Nat& Mapa::latitudMaxima() const {
	return latitudmaxima;
}

const Conj<Coordenada>& Mapa::coordenadasMapa() const {
	return coordenadas;
}

bool Mapa::posExiste(Coordenada& c) const {
	bool b; 
	if ((c.longitud() >= this->longitudmaxima) && (c.latitud() >= this->latitudmaxima)){
		b = false;
	}
	else{
		b = this->matriz[c.longitud()][c.latitud()] != NULL;
	}
}

bool Mapa::hayCamino(Coordenada& c, Coordenada& c2) const {
	Vector<Vector<bool> > matrizBooleana = (*this->matriz[c.longitud()][c.latitud()]);
	return matrizBooleana[c2.longitud()][c2.latitud()];
}

bool Mapa::hayCaminoQ( Coordenada& c, Nat i, Nat j, Conj<Coordenada>& cs) const {
	bool b; 
	if ((i >= this->longitudmaxima) && (j >= this->latitudmaxima)){
		b = false;
	}
	else{
		if( ((c.longitud() + 1 == i) || (c.longitud() - 1 == i)) && 
			((c.latitud() + 1 == j) || (c.latitud() - 1 == j)) ){
			b = true;
		}
		else{
			if(cs.EsVacio()){
				b = false;
			}
			else{
				/* NOTA: no puedo pasar 'cs.Eliminar(c)' por parámetro ya que devuelve void*/
				cs.Eliminar(c);
				bool arriba = this->existeCaminoPorArriba(c, cs);
				bool izquierda = this->existeCaminoPorIzquierda(c, cs);
				bool derecha = this->existeCaminoPorDerecha(c, cs);
				bool abajo = this->existeCaminoPorAbajo(c, cs);
				b = arriba && izquierda && derecha && abajo;
			}
		}
	}
	return b; 
}

bool Mapa::existeCaminoPorArriba(Coordenada& c, Conj<Coordenada>& cs) const{
	Coordenada adyacente = c.CoordenadaArriba();
	Vector<Vector<bool> >* existe = this->matriz[adyacente.longitud()][adyacente.latitud()];
	/* CONSULTA: la siguiente comparación no debería ser 'existe == NULL' ?? */
	if(existe != NULL){
		return false;
	}
	else{
		cs.Eliminar(adyacente);
		return this->hayCaminoQ(c, adyacente.longitud(), adyacente.latitud(), cs);

	}
}

bool Mapa::existeCaminoPorAbajo(Coordenada& c, Conj<Coordenada>& cs) const{
	Coordenada adyacente = c.CoordenadaAbajo();
	Vector<Vector<bool> >* existe = this->matriz[adyacente.longitud()][adyacente.latitud()];
	/* CONSULTA: la siguiente comparación no debería ser 'existe == NULL' ?? */
	if(existe != NULL){
		return false;
	}
	else{
		cs.Eliminar(adyacente);
		return this->hayCaminoQ(c, adyacente.longitud(), adyacente.latitud(), cs);

	}
}

bool Mapa::existeCaminoPorDerecha(Coordenada& c, Conj<Coordenada>& cs) const{
	Coordenada adyacente = c.CoordenadaALaDerecha();
	Vector<Vector<bool> >* existe = this->matriz[adyacente.longitud()][adyacente.latitud()];
	/* CONSULTA: la siguiente comparación no debería ser 'existe == NULL' ?? */
	if(existe != NULL){
		return false;
	}
	else{
		cs.Eliminar(adyacente);
		return this->hayCaminoQ(c, adyacente.longitud(), adyacente.latitud(), cs);

	}
}

bool Mapa::existeCaminoPorIzquierda(Coordenada& c, Conj<Coordenada>& cs) const{
	Coordenada adyacente = c.CoordenadaALaIzquierda();
	Vector<Vector<bool> >* existe = this->matriz[adyacente.longitud()][adyacente.latitud()];
	/* CONSULTA: la siguiente comparación no debería ser 'existe == NULL' ?? */
	if(existe != NULL){
		return false;
	}
	else{
		cs.Eliminar(adyacente);
		return this->hayCaminoQ(c, adyacente.longitud(), adyacente.latitud(), cs);

	}
}

Vector<Vector<bool> > Mapa::crearMatrizMapa(Coordenada& c) const {
	Nat i = 0;
	Vector<Vector<bool> > nuevo;

	while(i < this->longitudmaxima){
		Nat j = 0;
		Vector<bool> posiciones;

		while (j < this->latitudmaxima){
			Conj<Coordenada> nuevo = this->coordenadasMapa();
			Conj<Coordenada> copiaNuevo = nuevo;
			posiciones.AgregarAtras(this->hayCaminoQ(c, i, j, copiaNuevo));
			j++;
		}
		nuevo.AgregarAtras(posiciones);
		i++;
	}
	return nuevo;
}


int main(){
	return 0;
}