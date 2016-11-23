#include <iostream>
#include <ostream>
#include "ColadeprioridadH.h"


/*void test_esVacia() {
	aed2::Coladeprioridad<int> hola;
	ASSERT(hola.EsVacia());
}
*/









int main(){
	aed2::Coladeprioridad<int> hola;
	std::cout << hola.Claves()<< std::endl;
	std::cout << hola.Nivel() << std::endl;
	std::cout << hola.EsVacia() << std::endl;
	hola.Encolar(1);
	
	return 0;
	
} 

