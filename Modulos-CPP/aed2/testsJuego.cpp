#include <iostream>
#include "mini_test.h"

#include "Juego.h"
#include "Conj.h"

using namespace aed2;

void compila(){
	Mapa m;
	Juego nuevo(m);
	ASSERT(nuevo.VerMapa()  == m);


	}







int main() {
	RUN_TEST(compila);
	return 0;
}
