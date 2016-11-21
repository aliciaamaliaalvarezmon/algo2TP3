#include "ColadeprioridadH.h"
#include <iostream>


using namespace aed2;
using namespace std;


int main(){

Coladeprioridad<int> hola;
Coladeprioridad<int>::Nodo nuevo(5);
Coladeprioridad<int>::Nodo segundo(9);
//Coladeprioridad<int>::Nodo tercero(10);
//Coladeprioridad<int>::Nodo cuarto(12);
//Coladeprioridad<int>::Nodo quinto(15);
//Coladeprioridad<int>::Nodo sexto(17);
//Coladeprioridad<int>::Nodo septimo(21);
//Coladeprioridad<int>::Nodo octavo(22);
//Coladeprioridad<int>::Nodo noveno(23);

Coladeprioridad<int>::Nodo* dirnue = (&nuevo);
//hola.Encolarprueba(dirnue);

Coladeprioridad<int>::Nodo* dirseg = (&segundo);
//hola.Encolarprueba(dirseg);
//Coladeprioridad<int>::Nodo* dirter = (&tercero);
//Coladeprioridad<int>::Nodo* dircuarto =(&cuarto);
//Coladeprioridad<int>::Nodo* dirquinto =(&quinto);
//Coladeprioridad<int>::Nodo* dirsexto =(&sexto);
//Coladeprioridad<int>::Nodo* dirseptimo =(&septimo);
//Coladeprioridad<int>::Nodo* diroctavo =(&octavo);
//Coladeprioridad<int>::Nodo* dirnoveno =(&noveno);
nuevo.HacerHijo(dirseg);
//nuevo.HacerHijo(dirter);
//nuevo.HacerHijo(dirter);
//segundo.HacerHijo(dircuarto);
//segundo.HacerHijo(dirquinto);
//tercero.HacerHijo(dirsexto);
//tercero.HacerHijo(dirseptimo);
//cuarto.HacerHijo(diroctavo);
//cuarto.HacerHijo(dirnoveno);
/*cout<< "probando conexion" << endl;
cout << nuevo.Dato() << endl;
cout << nuevo.DERECHA() << endl;
cout << nuevo.IZQUIERDA() << endl;
cout << nuevo.PADRE() << endl;
cout << segundo.PADRE() << endl;

cout<< "probando swap" << endl;

*/
cout << dirnue << endl;
cout << nuevo.IZQUIERDA() << endl;
cout << segundo.PADRE() << endl;
segundo.swap(dirnue);
cout << segundo.IZQUIERDA() << endl;
cout << nuevo.PADRE() << endl;
/*

//cout << nuevo.PADRE() << endl;
/*cout << nuevo.PADRE() << endl;
cout << nuevo.IZQUIERDA() << endl;
cout <<  nuevo.DERECHA() << endl;
cout << tercero.PADRE() << endl;
cout << tercero.IZQUIERDA() << endl;
cout <<  tercero.DERECHA() << endl;*/
//cout << segundo.PADRE() << endl;
//cout << segundo.IZQUIERDA() << endl;
//cout << segundo.DERECHA() << endl;
//cout<< nuevo.IZQUIERDA() << endl;
//cout << (*(dirseg)).PADRE() << endl;
//tercero.swap(dirnue);
//cout << segundo.PADRE() << endl;
//cout << segundo.IZQUIERDA() << endl;
//cout << segundo.DERECHA() << endl;
/* cout << "probando swap entre no padre hijo" << endl;
 cout<< "antes" << endl;
 cout << "nuevo" << endl;
 cout << nuevo.PADRE() << endl;
 cout << nuevo.IZQUIERDA() << endl;
 cout << nuevo.DERECHA() << endl;
 cout << "segundo"<< endl;
 cout << segundo.PADRE() << endl;
 cout << segundo.IZQUIERDA() << endl;
 cout << segundo.DERECHA() << endl;
 cout << "tercero" << endl;
 cout << tercero.PADRE() << endl;
 cout << tercero.IZQUIERDA() << endl;
 cout << tercero.DERECHA() << endl;
 cout << "cuarto" << endl;
 cout << cuarto.PADRE() << endl;
 cout << cuarto.IZQUIERDA() << endl;
 cout << cuarto.DERECHA() << endl;

 cuarto.swap(dirnue);
cout << "despues" << endl;
 cout << "nuevo" << endl;
 cout << nuevo.PADRE() << endl;
 cout << nuevo.IZQUIERDA() << endl;
 cout << nuevo.DERECHA() << endl;
  cout << "segundo"<< endl;
 cout << segundo.PADRE() << endl;
 cout << segundo.IZQUIERDA() << endl;
 cout << segundo.DERECHA() << endl;
  cout << "tercero" << endl;
 cout << tercero.PADRE() << endl;
  cout << tercero.IZQUIERDA() << endl;
 cout << tercero.DERECHA() << endl;
  cout << "cuarto" << endl;
  cout << cuarto.PADRE() << endl;
 cout << cuarto.IZQUIERDA() << endl;
 cout << cuarto.DERECHA() << endl;



cout << "¡¡¡¡¡¡¡¡¡¡¡¡ EL SWAP FUNCA !!!!!!!!!!!!"<< endl;*/

//cout <<"probando recorro camino"<< endl;
//cout << hola.HEAP() << endl;
//cout << dirnue << endl;
//cout << nuevo.DERECHA() << endl;
//cout << nuevo.IZQUIERDA() << endl;
//cout << nuevo.PADRE() << endl;
//cout<< dirquinto << endl;
//cout << segundo.DERECHA() << endl;
//cout << (*dirseg).DERECHA() << endl;
//cout <<  hola.EstaEnLaMitad(2,5) << endl;
//cout << hola.EstaCompleto(1,3) << endl; 
//cout << hola.NodosDeNivelCompleto(1) << endl;
//cout << hola.mitadnodosdenivel(1) << endl;
//cout <<"actualize" << endl;
//cout << hola.recorrocamino(dirnue,3,9)<< endl;

cout <<"encolar"<< endl;
 hola.Encolar(6);
 hola.Encolar(5);
 // hola.Encolar(8);
 // hola.Encolar(7); 
 //cout << hola.HEAP() << endl; 
 //cout <<(*hola.HEAP()).Dato() << endl; 
 //cout << (*(hola.HEAP())).IZQUIERDA() << endl;
 //cout << (*(*(hola.HEAP())).IZQUIERDA()).Dato() << endl;
 // cout << (*(*(hola.HEAP())).IZQUIERDA()).PADRE() << endl;
 //cout << (*(hola.HEAP())).DERECHA() << endl;
 //cout << (*(*(hola.HEAP())).DERECHA()).Dato() << endl;
 //cout << (*(*(hola.HEAP())).IZQUIERDA()).IZQUIERDA() << endl;
 //cout << (*(*(*(hola.HEAP())).IZQUIERDA()).IZQUIERDA()).Dato() << endl;

 //cout << (*(hola.HEAP())).PADRE() << endl;
 // cout << (*(hola.HEAP())).Dato() << endl;

return 0;
}
  