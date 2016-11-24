#include "ColadeprioridadH.h"
#include <iostream>


using namespace aed2;
using namespace std;


int main(){

Coladeprioridad<int> hola;/*
Coladeprioridad<int>::Nodo nuevo(5);
Coladeprioridad<int>::Nodo segundo(9);
Coladeprioridad<int>::Nodo tercero(10);
Coladeprioridad<int>::Nodo cuarto(12);
Coladeprioridad<int>::Nodo quinto(15);
Coladeprioridad<int>::Nodo sexto(17);
Coladeprioridad<int>::Nodo septimo(21);
Coladeprioridad<int>::Nodo octavo(22);
Coladeprioridad<int>::Nodo noveno(23);

Coladeprioridad<int>::Nodo* dirnue = (&nuevo);
Coladeprioridad<int>::Nodo* dirseg = (&segundo);
Coladeprioridad<int>::Nodo* dirter = (&tercero);
Coladeprioridad<int>::Nodo* dircuarto =(&cuarto);
Coladeprioridad<int>::Nodo* dirquinto =(&quinto);
Coladeprioridad<int>::Nodo* dirsexto =(&sexto);
Coladeprioridad<int>::Nodo* dirseptimo =(&septimo);
Coladeprioridad<int>::Nodo* diroctavo =(&octavo);
Coladeprioridad<int>::Nodo* dirnoveno =(&noveno);

hola.Encolarprueba(dirnue);
nuevo.HacerHijo(dirseg);
nuevo.HacerHijo(dirter);
nuevo.HacerHijo(dirter);
segundo.HacerHijo(dircuarto);
segundo.HacerHijo(dirquinto);
tercero.HacerHijo(dirsexto);
tercero.HacerHijo(dirseptimo);
cuarto.HacerHijo(diroctavo);
cuarto.HacerHijo(dirnoveno);
cout<< "probando conexion" << endl;
cout << nuevo.Dato() << endl;
cout << nuevo.DERECHA() << endl;
cout << nuevo.IZQUIERDA() << endl;
cout << nuevo.PADRE() << endl;
cout << segundo.PADRE() << endl;

cout<< "probando swap entre padre e hijo" << endl;

cout<< "antes"<< endl;
cout << "nuevo" << endl;
 cout << nuevo.DERECHA() << endl;
 cout << nuevo.IZQUIERDA() << endl;
 cout << nuevo.PADRE() << endl; 
 cout << "segundo"<< endl;
 cout << segundo.DERECHA() << endl;
 cout << segundo.IZQUIERDA() << endl;
 cout << segundo.PADRE() << endl;
 cout << "tercero" << endl;
 cout << tercero.DERECHA() << endl;
 cout << tercero.IZQUIERDA() << endl;
 cout << tercero.PADRE() << endl;
 cout << "cuarto" << endl;
 cout << cuarto.DERECHA() << endl;
 cout << cuarto.IZQUIERDA() << endl;
 cout << cuarto.PADRE() << endl;
 cout << "quinto" << endl;
 cout << quinto.DERECHA() << endl;
 cout << quinto.IZQUIERDA() << endl;
 cout << quinto.PADRE() << endl;
 cout << "sexto" << endl;
 cout << sexto.DERECHA() << endl;
 cout << sexto.IZQUIERDA() << endl;
 cout << sexto.PADRE() << endl;
 cout << "septimo" << endl;
 cout << septimo.DERECHA() << endl;
 cout << septimo.IZQUIERDA() << endl;
 cout << septimo.PADRE() << endl;
 cout << "octavo" << endl;
 cout << octavo.DERECHA() << endl;
 cout << octavo.IZQUIERDA() << endl;
 cout << octavo.PADRE() << endl;
  cout << "noveno" << endl;
 cout << noveno.DERECHA() << endl;
 cout << noveno.IZQUIERDA() << endl;
 cout << noveno.PADRE() << endl;
segundo.swap(dirnue);
cout<< "despues"<< endl;
cout << "nuevo" << endl;
 cout << nuevo.DERECHA() << endl;
 cout << nuevo.IZQUIERDA() << endl;
 cout << nuevo.PADRE() << endl; 
 cout << "segundo"<< endl;
 cout << segundo.DERECHA() << endl;
 cout << segundo.IZQUIERDA() << endl;
 cout << segundo.PADRE() << endl;
 cout << "tercero" << endl;
 cout << tercero.DERECHA() << endl;
 cout << tercero.IZQUIERDA() << endl;
 cout << tercero.PADRE() << endl;
 cout << "cuarto" << endl;
 cout << cuarto.DERECHA() << endl;
 cout << cuarto.IZQUIERDA() << endl;
 cout << cuarto.PADRE() << endl;
 cout << "quinto" << endl;
 cout << quinto.DERECHA() << endl;
 cout << quinto.IZQUIERDA() << endl;
 cout << quinto.PADRE() << endl;
 cout << "sexto" << endl;
 cout << sexto.DERECHA() << endl;
 cout << sexto.IZQUIERDA() << endl;
 cout << sexto.PADRE() << endl;
 cout << "septimo" << endl;
 cout << septimo.DERECHA() << endl;
 cout << septimo.IZQUIERDA() << endl;
 cout << septimo.PADRE() << endl;
 cout << "octavo" << endl;
 cout << octavo.DERECHA() << endl;
 cout << octavo.IZQUIERDA() << endl;
 cout << octavo.PADRE() << endl;
  cout << "noveno" << endl;
 cout << noveno.DERECHA() << endl;
 cout << noveno.IZQUIERDA() << endl;
 cout << noveno.PADRE() << endl;

 cout << "probando swap entre no padre hijo" << endl;

 
 cout<< "antes" << endl;

 cout << "nuevo" << endl;
 cout << nuevo.DERECHA() << endl;
 cout << nuevo.IZQUIERDA() << endl;
 cout << nuevo.PADRE() << endl; 
 cout << "segundo"<< endl;
 cout << segundo.DERECHA() << endl;
 cout << segundo.IZQUIERDA() << endl;
 cout << segundo.PADRE() << endl;
 cout << "tercero" << endl;
 cout << tercero.DERECHA() << endl;
 cout << tercero.IZQUIERDA() << endl;
 cout << tercero.PADRE() << endl;
 cout << "cuarto" << endl;
 cout << cuarto.DERECHA() << endl;
 cout << cuarto.IZQUIERDA() << endl;
 cout << cuarto.PADRE() << endl;
 cout << "quinto" << endl;
 cout << quinto.DERECHA() << endl;
 cout << quinto.IZQUIERDA() << endl;
 cout << quinto.PADRE() << endl;
 cout << "sexto" << endl;
 cout << sexto.DERECHA() << endl;
 cout << sexto.IZQUIERDA() << endl;
 cout << sexto.PADRE() << endl;
 cout << "septimo" << endl;
 cout << septimo.DERECHA() << endl;
 cout << septimo.IZQUIERDA() << endl;
 cout << septimo.PADRE() << endl;
 cout << "octavo" << endl;
 cout << octavo.DERECHA() << endl;
 cout << octavo.IZQUIERDA() << endl;
 cout << octavo.PADRE() << endl;
  cout << "noveno" << endl;
 cout << noveno.DERECHA() << endl;
 cout << noveno.IZQUIERDA() << endl;
 cout << noveno.PADRE() << endl;
 cuarto.swap(dirnue);

cout << "despues" << endl;

 cout << "nuevo" << endl;
 cout << nuevo.DERECHA() << endl;
 cout << nuevo.IZQUIERDA() << endl;
 cout << nuevo.PADRE() << endl; 
 cout << "segundo"<< endl;
 cout << segundo.DERECHA() << endl;
 cout << segundo.IZQUIERDA() << endl;
 cout << segundo.PADRE() << endl;
 cout << "tercero" << endl;
 cout << tercero.DERECHA() << endl;
 cout << tercero.IZQUIERDA() << endl;
 cout << tercero.PADRE() << endl;
 cout << "cuarto" << endl;
 cout << cuarto.DERECHA() << endl;
 cout << cuarto.IZQUIERDA() << endl;
 cout << cuarto.PADRE() << endl;
 cout << "quinto" << endl;
 cout << quinto.DERECHA() << endl;
 cout << quinto.IZQUIERDA() << endl;
 cout << quinto.PADRE() << endl;
 cout << "sexto" << endl;
 cout << sexto.DERECHA() << endl;
 cout << sexto.IZQUIERDA() << endl;
 cout << sexto.PADRE() << endl;
 cout << "septimo" << endl;
 cout << septimo.DERECHA() << endl;
 cout << septimo.IZQUIERDA() << endl;
 cout << septimo.PADRE() << endl;
 cout << "octavo" << endl;
 cout << octavo.DERECHA() << endl;
 cout << octavo.IZQUIERDA() << endl;
 cout << octavo.PADRE() << endl;
  cout << "noveno" << endl;
 cout << noveno.DERECHA() << endl;
 cout << noveno.IZQUIERDA() << endl;
 cout << noveno.PADRE() << endl;



cout << "¡¡¡¡¡¡¡¡¡¡¡¡ EL SWAP FUNCA !!!!!!!!!!!!"<< endl;
cout << "¿¿¿¿¿¿¿¿¿¿¿¿ EL SWAP FUNCA ????????????"<< endl;
/*

cout <<"probando recorro camino"<< endl;
cout << hola.HEAP() << endl;
cout << dirnue << endl;
cout << nuevo.DERECHA() << endl;
cout << nuevo.IZQUIERDA() << endl;
cout << nuevo.PADRE() << endl;
//cout<< dirquinto << endl;
//cout << segundo.DERECHA() << endl;
//cout << (*dirseg).DERECHA() << endl;
//cout <<  hola.EstaEnLaMitad(2,5) << endl;
//cout << hola.EstaCompleto(1,3) << endl; 
//cout << hola.NodosDeNivelCompleto(1) << endl;
//cout << hola.mitadnodosdenivel(1) << endl;
cout <<"actualize" << endl;
//Aca voy cambiando los numeros del recorrer camino y me fijo que den bien.
cout << hola.recorrocamino(dirnue,3,4)<< endl;
 cout << hola.HEAP() << endl; 
 cout <<(*hola.HEAP()).Dato() << endl; 
 cout << (*(hola.HEAP())).IZQUIERDA() << endl;
 cout << (*(*(hola.HEAP())).IZQUIERDA()).Dato() << endl;
  cout << (*(*(hola.HEAP())).IZQUIERDA()).PADRE() << endl;
 cout << (*(hola.HEAP())).DERECHA() << endl;
 cout << (*(*(hola.HEAP())).DERECHA()).Dato() << endl;
 cout << (*(*(hola.HEAP())).IZQUIERDA()).IZQUIERDA() << endl;
 //cout << (*(*(*(hola.HEAP())).IZQUIERDA()).IZQUIERDA()).Dato() << endl;

 //cout << (*(hola.HEAP())).PADRE() << endl;
 //cout << (*(hola.HEAP())).Dato() << endl;
*/
cout <<"encolar"<< endl;
 hola.Encolar(6);
 cout << hola.EsVacia() << endl;
 cout << hola.tope() << endl;
 hola.Encolar(7); 
// hola.Encolar(9);
 hola.Encolar(8);  
  hola.Encolar(12);
 hola.Encolar(13);







return 0;
}
  