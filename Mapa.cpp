#include "Mapa.h"

Mapa::Mapa() : longitudmaxima(0), latitudmaxima(0), matriz() , coordenadas() {}
/*CONSULTA: esta bien inicializarlo así?*/

void Mapa::agregarCoord(Coordenada& c){
	coordenadas.AgregarRapido(c);
	Vector< Vector<Vector<bool> > >* fila = new Vector< Vector<Vector<bool> > >; 
	Vector<Vector<bool> >* elem = new Vector<Vector<bool> >;
	if(c.latitud() >= latitudmaxima and c.longitud() >= longitudmaxima){
		while(fila->Longitud() <= c.longitud()){
			fila->AgregarAtras(*elem);
		}
		while(matriz.Longitud() <= c.latitud()){
			matriz.AgregarAtras(*fila);
		}
		latitudmaxima = c.latitud()+1;
		longitudmaxima = c.longitud()+1;
	}else{
		if(c.latitud() >= latitudmaxima){
			while(fila->Longitud() < longitudmaxima){
				fila->AgregarAtras(*elem);
			}
			while(matriz.Longitud() <= c.latitud()){
				matriz.AgregarAtras(*fila);
			}
			latitudmaxima = c.latitud()+1;
		}else{
//			cout << "entre aca" <<endl;
			if(c.longitud() >= longitudmaxima){
				int i = 0;
				while(i< matriz.Longitud()){
					while(matriz[i].Longitud()<= c.longitud()){
						matriz[i].AgregarAtras(*elem);
					}
					i++;
				}
				longitudmaxima = c.longitud()+1;
			}
		}
		
	}
	int i=0;
	while(i<matriz.Longitud()){
		cout << "La Longitud de la matriz es : " << matriz[i].Longitud() <<endl;
		i++;
	}
//	cout <<"Latitud: " << latitudmaxima <<endl;
//	cout << "Longitud: " << longitudmaxima <<endl;
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
		Vector <Vector <bool> > matrizF = MatrizDeFalse(latitudmaxima+1,longitudmaxima+1);
		//		cout << "Latitud de la matriz de caminos: " << matriz.Longitud() <<endl;
		//		int i=0;
		//		while(i<matriz.Longitud()){
		//		cout <<"Longitud de la matriz de caminos: " << matriz[i].Longitud() <<endl;
		//		i++;
		//		}
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
	Vector <bool>* nuevo = new Vector < bool>;
	//	int k=0;
	//	int r=0;
	bool f;
	f= false;
	//			cout<< i <<endl;
	//			cout<< j <<endl;
	while(res->Longitud() <= i){
		nuevo = new Vector < bool>;
		while(nuevo->Longitud()< j){
			nuevo->AgregarAtras(f);
			//			r++;
		}
		//		cout<< nuevo->Longitud() <<endl;
		res->AgregarAtras(*nuevo);
		//		cout<< nuevo->Longitud() <<endl;
	}
	//	cout << res->Longitud() <<"     " << nuevo->Longitud() <<endl;
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
	return (matriz[c.latitud()][c.longitud()])[c2.latitud()][c2.longitud()];
}
