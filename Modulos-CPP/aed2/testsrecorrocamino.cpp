#include <iostream>
#include "mini_test.h"

#include "ColadeprioridadH.h"
#include "Conj.h"

using namespace aed2;

void test_vacio() {
	Coladeprioridad<int> hola;
	typename Coladeprioridad<int>::Nodo* raiz = hola.HEAP();
	typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(raiz, 0,0 );
	ASSERT(res == &raiz);
}

void test_un_nodo() {
	Coladeprioridad<int> hola;
	typename Coladeprioridad<int>::Nodo primero(1);
	typename Coladeprioridad<int>::Nodo* dirhIz= primero.IZQUIERDA();
	//cout<< &(dirhIz)<< endl;
	hola.Encolarprueba(&primero);
	typename Coladeprioridad<int>::Nodo* raiz = hola.HEAP();
	typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(raiz, 0,1);
	cout<< res<< endl;
	ASSERT((*res) == dirhIz);
}

void test_dos_nodos() {
	Coladeprioridad<int> hola;
	typename Coladeprioridad<int>::Nodo primero(1);
	typename Coladeprioridad<int>::Nodo segundo(2);
	hola.Encolarprueba(&primero);
	primero.HacerHijo(&segundo);
	typename Coladeprioridad<int>::Nodo* raiz = hola.HEAP();
	typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(raiz, 1,2);
	ASSERT((*res) == primero.DERECHA());
}


void test_tres_nodos() {

	Coladeprioridad<int> hola;
	ASSERT(hola.EstaCompleto(1, 3));
	typename Coladeprioridad<int>::Nodo primero(1);
	typename Coladeprioridad<int>::Nodo segundo(2);
	typename Coladeprioridad<int>::Nodo tercero(3);
	hola.Encolarprueba(&primero);
	primero.HacerHijo(&segundo);
	primero.HacerHijo(&tercero);
	//ASSERT((*(hola.HEAP())).IZQUIERDA() == &segundo);
	typename Coladeprioridad<int>::Nodo* raiz = hola.HEAP();
	//typename Coladeprioridad<int>::Nodo* dirsegu= &segundo;
	typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(raiz, 1,3);	
	//typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(dirsegu, 0, 1); 
	cout << res << endl;

	ASSERT((*res) == segundo.IZQUIERDA());
}


void test_cuatro_nodos() {

	Coladeprioridad<int> hola;
	ASSERT(hola.EstaCompleto(1, 3));
	typename Coladeprioridad<int>::Nodo primero(1);
	typename Coladeprioridad<int>::Nodo segundo(2);
	typename Coladeprioridad<int>::Nodo tercero(3);
	typename Coladeprioridad<int>::Nodo cuarto(4);	
	hola.Encolarprueba(&primero);
	primero.HacerHijo(&segundo);
	primero.HacerHijo(&tercero);
	segundo.HacerHijo(&cuarto);	
	//ASSERT((*(hola.HEAP())).IZQUIERDA() == &segundo);
	typename Coladeprioridad<int>::Nodo* raiz = hola.HEAP();
	//typename Coladeprioridad<int>::Nodo* dirsegu= &segundo;
	typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(raiz, 2,4);	
	//typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(dirsegu, 0, 1); 
	cout << res << endl;
	ASSERT((*res) == segundo.DERECHA());
}




void test_cinco_nodos() {

	Coladeprioridad<int> hola;
	ASSERT(hola.EstaCompleto(1, 3));
	typename Coladeprioridad<int>::Nodo primero(1);
	typename Coladeprioridad<int>::Nodo segundo(2);
	typename Coladeprioridad<int>::Nodo tercero(3);
	typename Coladeprioridad<int>::Nodo cuarto(4);
	typename Coladeprioridad<int>::Nodo quinto(5);
	hola.Encolarprueba(&primero);
	primero.HacerHijo(&segundo);
	primero.HacerHijo(&tercero);
	segundo.HacerHijo(&cuarto);
	segundo.HacerHijo(&quinto);
	//ASSERT((*(hola.HEAP())).IZQUIERDA() == &segundo);
	typename Coladeprioridad<int>::Nodo* raiz = hola.HEAP();
	//typename Coladeprioridad<int>::Nodo* dirsegu= &segundo;
	typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(raiz, 2,5);	
	//typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(dirsegu, 0, 1); 
	cout << res << endl;
	ASSERT((*res) == tercero.IZQUIERDA());
	ASSERT((*res) == tercero.DERECHA());
}


void test_cinco_nodos_con_hijos() {

	Coladeprioridad<int> hola;
	ASSERT(hola.EstaCompleto(1, 3));
	typename Coladeprioridad<int>::Nodo primero(1);
	typename Coladeprioridad<int>::Nodo segundo(2);
	typename Coladeprioridad<int>::Nodo tercero(3);
	typename Coladeprioridad<int>::Nodo cuarto(4);
	typename Coladeprioridad<int>::Nodo quinto(5);
	//typename Coladeprioridad<int>::Nodo sexto(6)
	hola.Encolarprueba(&primero);
	primero.HacerHijo(&segundo);
	primero.HacerHijo(&tercero);
	segundo.HacerHijo(&cuarto);
	segundo.HacerHijo(&quinto);
	//ASSERT((*(hola.HEAP())).IZQUIERDA() == &segundo);
	typename Coladeprioridad<int>::Nodo* raiz = hola.HEAP();
	//typename Coladeprioridad<int>::Nodo* dirsegu= &segundo;
	typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(raiz, 1,3);	
	//typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(dirsegu, 0, 1); 
	cout << res << endl;
	ASSERT((*res) == &cuarto);
	//ASSERT((*res) == tercero.DERECHA());
}

void test_doce_nodos() {

	Coladeprioridad<int> hola;
	ASSERT(hola.EstaCompleto(1, 3));
	typename Coladeprioridad<int>::Nodo primero(1);
	typename Coladeprioridad<int>::Nodo segundo(2);
	typename Coladeprioridad<int>::Nodo tercero(3);
	typename Coladeprioridad<int>::Nodo cuarto(4);
	typename Coladeprioridad<int>::Nodo quinto(5);
	typename Coladeprioridad<int>::Nodo sexto(6);
	typename Coladeprioridad<int>::Nodo septimo(7);
	typename Coladeprioridad<int>::Nodo octavo(8);
	typename Coladeprioridad<int>::Nodo noveno(9);
	typename Coladeprioridad<int>::Nodo decimo(10);
	typename Coladeprioridad<int>::Nodo undecimo(11);
	typename Coladeprioridad<int>::Nodo doceavo(12);

	hola.Encolarprueba(&primero);
	primero.HacerHijo(&segundo);
	primero.HacerHijo(&tercero);
	segundo.HacerHijo(&cuarto);
	segundo.HacerHijo(&quinto);
	tercero.HacerHijo(&sexto);
	tercero.HacerHijo(&septimo);
	cuarto.HacerHijo(&octavo);
	cuarto.HacerHijo(&noveno);
	quinto.HacerHijo(&decimo);
	quinto.HacerHijo(&undecimo);
	sexto.HacerHijo(&doceavo);
	//ASSERT((*(hola.HEAP())).IZQUIERDA() == &segundo);
	typename Coladeprioridad<int>::Nodo* raiz = hola.HEAP();
	//typename Coladeprioridad<int>::Nodo* dirsegu= &segundo;
	typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(raiz, 3,12);	
	//typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(dirsegu, 0, 1); 
	cout << res << endl;
	ASSERT((*res) == sexto.DERECHA());
	//ASSERT((*res) == tercero.DERECHA());
}


/*
void test_padre_agrego_segundo_nodo(){
	Coladeprioridad<int> hola;
	typename Coladeprioridad<int>::Nodo primero(1);
	hola.Encolarprueba(&primero);
	typename Coladeprioridad<int>::Nodo** res = hola.recorrocamino(raiz, 1,(2/2)-1);



}

*/

void encolar(){
	Coladeprioridad<int> hola;
	Coladeprioridad<int>::Iterador it = hola.Encolar(6);
	ASSERT(hola.Claves() == 1);
	ASSERT(hola.Nivel() == 0);
	ASSERT(it.HaySiguiente());
	ASSERT(it.Siguiente() == 6);
	hola.Desencolar();
	//cout << hola.HEAP() << endl;	
	//ASSERT((*hola.HEAP()).Dato() == 6);	
	ASSERT(hola.EsVacia());
	/*hola.Encolar(5);
	ASSERT(it.HaySiguiente());
	ASSERT(it.Siguiente() == 6);
	hola.Encolar(1);
	cout << (*hola.HEAP()).Dato() << endl;
	cout << (*(*hola.HEAP()).IZQUIERDA()).Dato() << endl;
	hola.Encolar(9);
	hola.Encolar(10);
	hola.Encolar(0);		
	ASSERT(hola.Claves() == 6);
	ASSERT(hola.tope() == 0);
*/
}











void test_padre() {
}


void test_swap_hijo_dos_ramas() {
}


void test_swap_hijo_dos_ramas_distinto_nivel() {
	
}











int main() {
	//RUN_TEST(test_vacio);
	//RUN_TEST(test_un_nodo);
	//RUN_TEST(test_dos_nodos);
	//RUN_TEST(test_tres_nodos);
	//RUN_TEST(test_cuatro_nodos);
	//RUN_TEST(test_cinco_nodos);
	//RUN_TEST(test_cinco_nodos_con_hijos); 
	//RUN_TEST(test_doce_nodos);
	RUN_TEST(encolar);
	
	return 0;
}
