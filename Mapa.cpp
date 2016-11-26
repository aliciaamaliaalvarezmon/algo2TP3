#include "Mapa.h"

Mapa::Mapa() : longitudmaxima(0), latitudmaxima(0), matriz() , coordenadas() {}
/*CONSULTA: esta bien inicializarlo así?*/

void Mapa::agregarCoord(Coordenada& c){
	coordenadas.AgregarRapido(c);
	if (c.longitud() >= this->longitudmaxima){
		while(this->longitudmaxima <= c.longitud()){
			Vector< Vector<Vector<bool> > > nuevo;
			Nat i = 0;
			while (i <= this->longitudmaxima){
				Vector<Vector<bool> > posVacia;
				nuevo.AgregarAtras(posVacia);
				i++;
			}
	this->matriz.AgregarAtras(nuevo);
	this->longitudmaxima++;
		}
	}
	if (c.latitud() >= this->latitudmaxima){
		while (this->latitudmaxima <= c.latitud()){
				Nat j = 0; 
				while (j < this->longitudmaxima){
						Vector<Vector<bool> > nuevaPos;
						this->matriz[j].AgregarAtras(nuevaPos);
						j++;
				}
				this->latitudmaxima++;
		}
	}
	cout <<"Latitud: " << latitudmaxima <<endl;
	cout << "Longitud: " << longitudmaxima <<endl;
	Conj<Coordenada> coords = coordenadas;
	Conj<Coordenada>::Iterador it = coords.CrearIt();
	while(it.HaySiguiente()){
		Coordenada paraLasRelaciones = it.Siguiente();
		Conj<Coordenada> vacio;
		vacio.Agregar(paraLasRelaciones);
		Conj<Coordenada> res;
//		cout << "YoloA" <<endl;
		res = Lindantes(vacio,coords,res);
//		cout << "YoloB1" <<endl;
		Vector <Vector <bool> > matrizF = MatrizDeFalse(latitudmaxima-1,longitudmaxima-1);
		cout << "Latitud de la matriz de caminos: " << matriz.Longitud() <<endl;
		cout <<"Longitud de la matriz de caminos: " << matriz[0].Longitud() <<endl;
		Rellenar(matrizF,res);
//		cout << "YoloD3" <<endl;
		(matriz[it.Siguiente().latitud()][it.Siguiente().longitud()]) = matrizF;
//		cout << "YoloE4" <<endl;
		it.Avanzar();
	}

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


Conj<Coordenada> 	Mapa::Lindantes(Conj<Coordenada> c,Conj<Coordenada> coordenadas,Conj<Coordenada> res) const{
	Conj<Coordenada>::Iterador it =c.CrearIt();
	Conj<Coordenada> ParaLaRecursion;
	while(it.HaySiguiente()){
		Conj<Coordenada> lindastesDeC = (it.Siguiente()).Lindantes();
		Conj<Coordenada>::Iterador it2 = lindastesDeC.CrearIt();
		while(it2.HaySiguiente()){
			if(coordenadas.Pertenece(it2.Siguiente())){
				res.Agregar(it2.Siguiente());
				ParaLaRecursion.Agregar(it2.Siguiente());
				coordenadas.Eliminar(it2.Siguiente());
			}
			it2.Avanzar();
		}
		it.Avanzar();
	}
	if(ParaLaRecursion.Cardinal()!=0){
		return Lindantes(ParaLaRecursion,coordenadas,res);
	}else{
		return res;
	}
}


Vector <Vector < bool> > Mapa::MatrizDeFalse(Nat i, Nat j){
	Vector <Vector < bool> >* res = new Vector <Vector < bool> >;
//	Vector <bool>* nuevo = new Vector < bool>;
	int k=0;
	while(k<= i){
		int r = 0;
		Vector <bool>* nuevo = new Vector < bool>;
		while(r<=j){
			/*cout << matriz.Longitud() <<endl ;*/
			bool f = false;
			nuevo->AgregarAtras(f);
			r++;
		}
		res->AgregarAtras(*nuevo);
		k++;
	}
	return *res;
}

void Mapa::Rellenar(Vector <Vector < bool> >& matriz,Conj<Coordenada> linda){
	Conj<Coordenada>::Iterador it = linda.CrearIt();
	while(it.HaySiguiente()){
		(matriz)[it.Siguiente().latitud()][it.Siguiente().longitud()]=true;
		it.Avanzar();
	}
	
}

bool Mapa::hayCamino(Coordenada c, Coordenada c2) const{
//	Vector< Vector<bool> > matrizDeRelacion = (matriz[c.latitud()][c.longitud()]);
	return ((matriz[c.latitud()][c.longitud()]))[c2.latitud()][c2.longitud()];
}
