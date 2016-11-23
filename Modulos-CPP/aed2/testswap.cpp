#include <iostream>
#include "mini_test.h"

#include "ColadeprioridadH.h"
#include "Conj.h"

using namespace aed2;

void test_hijo_dos_nodos() {
	Coladeprioridad<int>::Nodo padre(1);
	Coladeprioridad<int>::Nodo hijo(2);
	padre.HacerHijo(&hijo);

	ASSERT(padre.IZQUIERDA() == &hijo);
	ASSERT(padre.DERECHA() == NULL);
	ASSERT(padre.PADRE() == NULL);
	ASSERT(hijo.DERECHA() == NULL);
	ASSERT(hijo.IZQUIERDA() == NULL);
	ASSERT(hijo.PADRE() == &padre);
	ASSERT(&hijo != &padre);

	Coladeprioridad<int>::Nodo* pPadre = &padre;
	hijo.swap(pPadre);

	ASSERT(padre.IZQUIERDA() == NULL);
	ASSERT(padre.DERECHA() == NULL);
	ASSERT(padre.PADRE() == &hijo);
	ASSERT(hijo.DERECHA() == NULL);
	ASSERT(hijo.IZQUIERDA() == &padre);
	ASSERT(hijo.PADRE() == NULL);
	ASSERT(&hijo != &padre);
}

void test_hijo_con_hijo() {
	Coladeprioridad<int>::Nodo padre(1);
	Coladeprioridad<int>::Nodo hijoI(2);
	Coladeprioridad<int>::Nodo hijoD(3);
	Coladeprioridad<int>::Nodo nieto(4);
	padre.HacerHijo(&hijoI);
	padre.HacerHijo(&hijoD);
	hijoI.HacerHijo(&nieto);

	ASSERT(padre.IZQUIERDA() == &hijoI);
	ASSERT(padre.DERECHA() == &hijoD);
	ASSERT(padre.PADRE() == NULL);

	ASSERT(hijoI.DERECHA() == NULL);
	ASSERT(hijoI.IZQUIERDA() == &nieto);
	ASSERT(hijoI.PADRE() == &padre);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == NULL);
	ASSERT(hijoD.PADRE() == &padre);

	Conj<Coladeprioridad<int>::Nodo*> c;
	c.Agregar(&padre);
	c.Agregar(&hijoI);
	c.Agregar(&hijoD);
	c.Agregar(&nieto);
	ASSERT(c.Cardinal() == 4);

	Coladeprioridad<int>::Nodo* pPadre = &padre;
	hijoI.swap(pPadre);

	ASSERT(padre.IZQUIERDA() == &nieto);
	ASSERT(padre.DERECHA() == NULL);
	ASSERT(padre.PADRE() == &hijoI);

	ASSERT(hijoI.PADRE() == NULL);
	ASSERT(hijoI.DERECHA() == &hijoD);
	ASSERT(hijoI.IZQUIERDA() == &padre);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == NULL);
	ASSERT(hijoD.PADRE() == &hijoI);
	
	c = Conj<Coladeprioridad<int>::Nodo*>();
	c.Agregar(&padre);
	c.Agregar(&hijoI);
	c.Agregar(&hijoD);
	c.Agregar(&nieto);
	ASSERT(c.Cardinal() == 4);
}

void test_swap_nieto_con_abuelo() {
	Coladeprioridad<int>::Nodo padre(1);
	Coladeprioridad<int>::Nodo hijoI(2);
	Coladeprioridad<int>::Nodo hijoD(3);
	Coladeprioridad<int>::Nodo nieto(4);
	padre.HacerHijo(&hijoI);
	padre.HacerHijo(&hijoD);
	hijoI.HacerHijo(&nieto);

	ASSERT(padre.IZQUIERDA() == &hijoI);
	ASSERT(padre.DERECHA() == &hijoD);
	ASSERT(padre.PADRE() == NULL);

	ASSERT(hijoI.DERECHA() == NULL);
	ASSERT(hijoI.IZQUIERDA() == &nieto);
	ASSERT(hijoI.PADRE() == &padre);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == NULL);
	ASSERT(hijoD.PADRE() == &padre);

	ASSERT(nieto.DERECHA() == NULL);
	ASSERT(nieto.IZQUIERDA() == NULL);
	ASSERT(nieto.PADRE() == &hijoI);

	Coladeprioridad<int>::Nodo* pPadre = &padre;
	nieto.swap(pPadre);

	ASSERT(padre.IZQUIERDA() == NULL);
	ASSERT(padre.DERECHA() == NULL);
	ASSERT(padre.PADRE() == &hijoI);

	ASSERT(hijoI.DERECHA() == NULL);
	ASSERT(hijoI.IZQUIERDA() == &padre);
	ASSERT(hijoI.PADRE() == &nieto);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == NULL);
	ASSERT(hijoD.PADRE() == &nieto);

	ASSERT(nieto.DERECHA() == &hijoD);
	ASSERT(nieto.IZQUIERDA() == &hijoI);
	ASSERT(nieto.PADRE() == NULL);
}

void test_swap_hijo_con_nodo_con_padre() {
	Coladeprioridad<int>::Nodo padre(1);
	Coladeprioridad<int>::Nodo hijoI(2);
	Coladeprioridad<int>::Nodo hijoD(3);
	Coladeprioridad<int>::Nodo nieto(4);
	padre.HacerHijo(&hijoI);
	padre.HacerHijo(&hijoD);
	hijoI.HacerHijo(&nieto);

	ASSERT(padre.IZQUIERDA() == &hijoI);
	ASSERT(padre.DERECHA() == &hijoD);
	ASSERT(padre.PADRE() == NULL);

	ASSERT(hijoI.DERECHA() == NULL);
	ASSERT(hijoI.IZQUIERDA() == &nieto);
	ASSERT(hijoI.PADRE() == &padre);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == NULL);
	ASSERT(hijoD.PADRE() == &padre);

	ASSERT(nieto.DERECHA() == NULL);
	ASSERT(nieto.IZQUIERDA() == NULL);
	ASSERT(nieto.PADRE() == &hijoI);

	Coladeprioridad<int>::Nodo* phijoI = &hijoI;
	nieto.swap(phijoI);

	ASSERT(padre.IZQUIERDA() == &nieto);
	ASSERT(padre.DERECHA() == &hijoD);
	ASSERT(padre.PADRE() == NULL);

	ASSERT(hijoI.DERECHA() == NULL);
	ASSERT(hijoI.IZQUIERDA() == NULL);
	ASSERT(hijoI.PADRE() == &nieto);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == NULL);
	ASSERT(hijoD.PADRE() == &padre);

	ASSERT(nieto.DERECHA() == NULL);
	ASSERT(nieto.IZQUIERDA() == &hijoI);
	ASSERT(nieto.PADRE() == &padre);
}


void test_swap_hijo_dos_ramas() {
	Coladeprioridad<int>::Nodo padre(1);
	Coladeprioridad<int>::Nodo hijoI(2);
	Coladeprioridad<int>::Nodo hijoD(3);
	Coladeprioridad<int>::Nodo nieto(4);
	padre.HacerHijo(&hijoI);
	padre.HacerHijo(&hijoD);
	hijoI.HacerHijo(&nieto);

	ASSERT(padre.IZQUIERDA() == &hijoI);
	ASSERT(padre.DERECHA() == &hijoD);
	ASSERT(padre.PADRE() == NULL);

	ASSERT(hijoI.DERECHA() == NULL);
	ASSERT(hijoI.IZQUIERDA() == &nieto);
	ASSERT(hijoI.PADRE() == &padre);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == NULL);
	ASSERT(hijoD.PADRE() == &padre);

	ASSERT(nieto.DERECHA() == NULL);
	ASSERT(nieto.IZQUIERDA() == NULL);
	ASSERT(nieto.PADRE() == &hijoI);

	Coladeprioridad<int>::Nodo* phijoD = &hijoD;
	hijoI.swap(phijoD);


	ASSERT(padre.IZQUIERDA() == &hijoD);
	ASSERT(padre.DERECHA() == &hijoI);
	ASSERT(padre.PADRE() == NULL);

	ASSERT(hijoI.DERECHA() == NULL); 
	ASSERT(hijoI.IZQUIERDA() == NULL); 
	ASSERT(hijoI.PADRE() == &padre);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == &nieto);
	ASSERT(hijoD.PADRE() == &padre);

	ASSERT(nieto.DERECHA() == NULL);
	ASSERT(nieto.IZQUIERDA() == NULL);
	ASSERT(nieto.PADRE() == &hijoD);


}


void test_swap_hijo_dos_ramas_distinto_nivel() {
	Coladeprioridad<int>::Nodo padre(1);
	Coladeprioridad<int>::Nodo hijoI(2);
	Coladeprioridad<int>::Nodo hijoD(3);
	Coladeprioridad<int>::Nodo nieto(4);
	padre.HacerHijo(&hijoI);
	padre.HacerHijo(&hijoD);
	hijoI.HacerHijo(&nieto);

	ASSERT(padre.IZQUIERDA() == &hijoI);
	ASSERT(padre.DERECHA() == &hijoD);
	ASSERT(padre.PADRE() == NULL);

	ASSERT(hijoI.DERECHA() == NULL);
	ASSERT(hijoI.IZQUIERDA() == &nieto);
	ASSERT(hijoI.PADRE() == &padre);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == NULL);
	ASSERT(hijoD.PADRE() == &padre);

	ASSERT(nieto.DERECHA() == NULL);
	ASSERT(nieto.IZQUIERDA() == NULL);
	ASSERT(nieto.PADRE() == &hijoI);

	Coladeprioridad<int>::Nodo* phijoD = &hijoD;
	nieto.swap(phijoD);


	ASSERT(padre.IZQUIERDA() == &hijoI);
	ASSERT(padre.DERECHA() == &nieto);
	ASSERT(padre.PADRE() == NULL);

	ASSERT(hijoI.DERECHA() == NULL); 
	ASSERT(hijoI.IZQUIERDA() == &hijoD); 
	ASSERT(hijoI.PADRE() == &padre);

	ASSERT(hijoD.DERECHA() == NULL);
	ASSERT(hijoD.IZQUIERDA() == NULL);
	ASSERT(hijoD.PADRE() == &hijoI);

	ASSERT(nieto.DERECHA() == NULL);
	ASSERT(nieto.IZQUIERDA() == NULL);
	ASSERT(nieto.PADRE() == &padre);


}











int main() {
	RUN_TEST(test_hijo_dos_nodos);
	RUN_TEST(test_hijo_con_hijo);
	RUN_TEST(test_swap_nieto_con_abuelo);
	RUN_TEST(test_swap_hijo_con_nodo_con_padre);
	RUN_TEST(test_swap_hijo_dos_ramas);
	RUN_TEST(test_swap_hijo_dos_ramas_distinto_nivel);
	
	return 0;
}
