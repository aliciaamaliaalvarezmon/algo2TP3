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

















void test_swap_hijo_con_nodo_con_padre() {
}


void test_swap_hijo_dos_ramas() {
}


void test_swap_hijo_dos_ramas_distinto_nivel() {
	
}











int main() {
	//RUN_TEST(test_vacio);
	//RUN_TEST(test_un_nodo);
	//RUN_TEST(test_dos_nodos);
	RUN_TEST(test_tres_nodos);
	RUN_TEST(test_cuatro_nodos);
	RUN_TEST(test_cinco_nodos);
	RUN_TEST(test_cinco_nodos_con_hijos); 
	
	return 0;
}
