 /*
 * Author: ?
 *
 * Lista doblemente enlazada.
 * 
 */
//BANANA SIGNIFICA QUE NO SE SI ALGO ESTA BIEN
#ifndef AED2_COLADEPRIORIDAD_H_
#define AED2_COLADEPRIORIDAD_H_

#include <ostream>
#include "TiposBasicos.h"

using namespace std;
namespace aed2
{

template <typename T>
class Coladeprioridad
{
  public:
  // forward declarations
  // Las estructuras estan definidas mas abajo
  class Iterador;

  struct Nodo
    {
      Nodo(const T& d) : dato(d), hijoIzq(NULL), hijoDer(NULL), padre(NULL){};
      Nodo(const typename Coladeprioridad<T>::Nodo* otro) :
                dato(otro->dato),  hijoIzq(NULL), hijoDer(NULL), padre(NULL) {};
      Nodo& operator=(const typename Coladeprioridad<T>::Nodo& otro)
       {dato(otro->dato), hijoIzq(otro->hijoIzq), hijoDer(otro->hijoDer), padre(otro->padre);}


    
     
     Nodo* hijoDer;
     Nodo* hijoIzq;
     T dato;     
     Nodo* padre;     

     Nat Dato(){    //TESTING
      return dato;
     }
     Nodo* DERECHA(){
      return hijoDer;
     }
     Nodo* IZQUIERDA(){
      return hijoIzq;
     }

     Nodo* PADRE(){
      return padre;
     }

     void HacerHijo(Nodo* n){
      if (hijoIzq == NULL){
        hijoIzq =  n;
        n->padre = this;
        }else{
          hijoDer = n;
        n->padre = this; 
        } 
      }
//CAMBIO
    void swap(Nodo* p2){
    if(padre == p2){
 
    typename Coladeprioridad<T>::Nodo* derecha = p2->hijoDer;
    typename Coladeprioridad<T>::Nodo* izquierda = p2->hijoIzq;
    typename Coladeprioridad<T>::Nodo* anterior = p2->padre;
    if(hijoIzq != NULL){   
    hijoIzq-> padre = p2;
    }
    if(hijoDer != NULL){
    hijoDer-> padre = p2;
    }   
    p2-> hijoIzq = hijoIzq;
    p2-> hijoDer = hijoDer;/*
    if(izquierda == this){
      hijoDer = derecha; 
      if(derecha != NULL){     
      derecha-> padre = this;
    }
      hijoIzq = p2;
    }else{
      hijoIzq = izquierda;
      if(izquierda != NULL){
      izquierda-> padre = this;
    }
      hijoDer = p2;
    }
    if(anterior != NULL){
    if(anterior-> hijoIzq = p2){
      anterior-> hijoIzq = this;
    }else{
      anterior-> hijoDer = this;
    }}   
   (p2->padre) = this;    
   (padre) = anterior;*/
  }else{
    typename Coladeprioridad<T>::Nodo* derecha = p2-> hijoDer;
    typename Coladeprioridad<T>::Nodo* izquierda = p2-> hijoIzq;
    typename Coladeprioridad<T>::Nodo* anterior = p2-> padre;
    if(hijoIzq != NULL){
    hijoIzq-> padre = p2;
    }
    if(hijoDer != NULL){
    hijoDer-> padre = p2;
    }
    if(padre-> hijoIzq = this){  
      padre-> hijoIzq= p2;
    }else{
      padre-> hijoDer= p2;
    }
    if(anterior != NULL){
    if(anterior-> hijoIzq = p2){
      anterior-> hijoIzq = this;
    }else{
      anterior-> hijoDer = this;
    }
    }
   // p2->hijoDer = p1->hijoIzq;
   // p2->hijoIzq = p1->hijoDer;
    p2-> hijoDer = hijoDer;
    p2-> hijoIzq = hijoIzq;
    p2-> padre = padre;
    hijoIzq =   izquierda;
    hijoDer = derecha;
    padre = anterior;
    izquierda-> padre = this;
    derecha-> padre= this;

    }
   }




     
  };


  //class const_Iterador;//Necesito de los 2 iteradores??//BANANA

  /// Crea una coladeprioridad vacía. (Operación Vacia())
  Coladeprioridad();
  Nat Claves();//TESTING
  Nat Nivel(); //TESTING


  /// Crea por copia una coladeprioridad (operación Copiar())
  //Coladeprioridad(const Coladeprioridad& otra);

  /// Destruye la coladepriorida, incluyendo los T alojados
  //~Coladeprioridad();

  /// Operacion de asignacion
  //Lista<T>& operator=(const Lista<T>& otra);

  /// Opreaciones básicas
  bool EsVacia() const;
 //void swap(Coladeprioridad<T>::Nodo* p1,Coladeprioridad<T>::Nodo* p2);
 Coladeprioridad<T>::Iterador CrearIt(Coladeprioridad<T>::Nodo* p);

  Nat NodosDeNivelCompleto(Nat n){
    Nat potencia = n+1;
    Nat res = 1;
    while(potencia  > 0){  //return (2^(n+1))-1;
    res = res << 1;
    potencia = potencia -  1;
    }
    res--;
    return res;
  }

  Nat mitadnodosdenivel(Nat n){
   Nat potencia = n-1;
   Nat res = 1;
   if (potencia == 0){//en el codigo no va a pasar
    return 0;
   }else{
    while(potencia > 0){
      res = res << 1;
      potencia--;
    }
   } 
   return res;
  //return 2^(n-1);
  }

  bool EstaCompleto(Nat n, Nat cant ){
 return (NodosDeNivelCompleto(n)-cant == 0);
 }
  bool IrPorSubarbolIz(Nat n, Nat cant ){
  return (NodosDeNivelCompleto(n)-cant > mitadnodosdenivel(n));
  }
   bool EstaEnLaMitad(Nat n, Nat cant ){
  return (NodosDeNivelCompleto(n)-cant ==  mitadnodosdenivel(n));
  }
 



 // Coladeprioridad<T>::Nodo* recorrocamino(Coladeprioridad::Nodo* h, Nat n, Nat cant);
  typename Coladeprioridad<T>::Nodo** recorrocamino(typename Coladeprioridad<T>::Nodo* h, Nat n, Nat cant ){
   Nat potencia = n;
   Nat resta = 1;   
    while(potencia > 0){
      resta = resta << 1;
      potencia--;  
    }
  if(cant == 0){
    return (&h);
  }else{
    if(cant == 1){
      return &(h->hijoIzq);
    }else{
    if((n == 1) && (!EstaCompleto(n, cant))){      
        return &(h->hijoDer);       
      }else{        
      
        if(EstaCompleto(n, cant)){
          recorrocamino((h->hijoIzq), n-1, cant - resta);
        }
        else{
          if(IrPorSubarbolIz(n, cant)){
            recorrocamino(h->hijoIzq, n-1, cant - resta/2);
          }
          else{
            if(EstaEnLaMitad(n,cant)){
              recorrocamino((h->hijoDer), n-2, cant - resta);
            }else{
               recorrocamino(h->hijoDer, n-1, cant - resta);
            }

      }
    }
    }
  }
}
}


 //Coladeprioridad<T>::Iterador Encolar(const T& elem);
void Encolar(const T& elem);

 void Encolarprueba(Coladeprioridad<T>::Nodo* n){
  cantClaves_++;
  if (cantClaves_ == (2^(nivel_+1))){
    nivel_++;
  }  
    heap_ = n; 
  }
  Nodo* HEAP(){
    return heap_;
  } 



  //ve el top de la cola
 // T& tope() const;
  //const T& tope() const;



 // void Desencolar();

  //encola elementostypename 


  //desencola elementos
//  Coladeprioridad<T>::Iterador Desencolar();

  //void Borrar( Coladeprioridad<T>::Iterador ih);

  //borra elementos
  //Iterador Borrar(Iterador aborrar);



  /// Creación del const_Iterador
 // const_Iterador CrearIt() const;
  //const_Iterador CrearItUlt() const;

  /**********************************
   * Iterador de ColadeprioridadLista, modificable *
   **********************************/
  class Iterador
  {
    public:     

      //Iterador(const typename Coladeprioridad<T>::Iterador& otro);

      //Iterador& operator = (const typename Coladeprioridad<T>::Iterador& otro);

     
     // bool HaySiguiente() const;
     
      //T& Siguiente();
   
      //const T& Siguiente() const;  


     // bool operator == (const typename Lista<T>::Iterador& otro) const;

  private:


    
     //typename Coladeprioriodad<T>; 

      typename Coladeprioridad<T>::Nodo* apuntador_;
      Iterador(){
        apuntador_ = NULL;
      }
      Iterador(typename Coladeprioridad<T>::Nodo* p){
        apuntador_ = p;
      }


      




      //friend typename Coladeprioridad<T>::Iterador CrearIt(typename Coladeprioridad<T>::Nodo* n);

   
      //friend class Coladeprioridad<T>::Iterador;

     


      // devuelve el nodo siguiente en la lista circular
      //typename Lista<T>::Nodo* SiguienteReal() const;
  };



private:

    /* struct Nodo
    {
      Nodo(const T& d) : dato(d), hijoIzq(NULL), hijoDer(NULL), padre(NULL){};

     T dato;
     Nodo* hijoIzq;
     Nodo* hijoDer;
     Nodo* padre;
    };
*/
   Nodo* heap_;
   Nat cantClaves_;
   Nat nivel_;

/*

  Nodo* recorrocamino(Coladeprioridad::Nodo* h, Nat n, Nat cant);
  /*bool EstaCompleto(Nat n, Nat cant );
  bool IrPorSubarbolIz(Nat n, Nat cant );
  bool EstaEnLaMitad(Nat n, Nat cant );
  Nat NodosDeNivelCompleto(Nat n);
  Nat mitadnodosdenivel(Nat n);
  T minimodato(Coladeprioridad<T>::Nodo* p1, Coladeprioridad<T>::Nodo* p2);
  Nodo* minimonodo(Coladeprioridad<T>::Nodo* p1, Coladeprioridad<T>::Nodo* p2);
  void swap(Coladeprioridad<T>::Nodo* p1, Coladeprioridad<T>::Nodo* p2);
  Coladeprioridad<T>::Iterador CrearIt(Coladeprioridad<T>::Nodo* p);
*/



};





//template<class T>
//std::ostream& operator << (std::ostream& os, const Lista<T>& l);

//template<class T>
//bool operator == (const Lista<T>& l1, const Lista<T>& k2);

  //  Implementacion de Lista

template <typename T>
Coladeprioridad<T>::Coladeprioridad()
  : heap_(NULL), cantClaves_(0), nivel_(0)
{}

template <typename T>
Nat Coladeprioridad<T>::Claves(){
	return cantClaves_;
}

template <typename T>
Nat Coladeprioridad<T>::Nivel(){
	return nivel_;
}




//template <typename T>
//Coladeprioridad<T>::Coladeprioridad(const Coladeprioridad<T>& otra)
//  : primero_(NULL), longitud_(0)
//{
  // TODO la idea es que haga shallow copy? //QUE SIGNIFICA ESTO  
  // Pense que por convencon definiamos este operador con deep copy
  // de hecho el operador = hace deep copy
//  *this = otra;
//}



/*template <typename T>
Coladeprioridad<T>::~Coladeprioridad()
{
  while(!EsVacia()) {
    Desencolar();
  }
}
*/
template <typename T>
bool Coladeprioridad<T>::EsVacia() const
{
  return heap_ == NULL;
}

/*
template<class T>
T& Coladeprioridad<T>::tope() const {

return heap_-> dato;

} 

/*template<class T>
T& Coladeprioridad<T>::tope() const {

return heap_-> dato;

} 


*/


/*
Nat NodosDeNivelCompleto(Nat n){
 return (2^(n+1))-1;
}*/

/*
Nat mitadnodosdenivel(Nat n){
return 2^(n-1);
}





bool EstaCompleto(Nat n, Nat cant ){
 return (NodosDeNivelCompleto(n)-cant == 0);
}


bool IrPorSubarbolIz(Nat n, Nat cant ){
return (NodosDeNivelCompleto(n)-cant > mitadnodosdenivel(n));
}


bool EstaEnLaMitad(Nat n, Nat cant ){
return (NodosDeNivelCompleto(n)-cant == mitadnodosdenivel(n));
}
*/

/*
template<class T>
typename Coladeprioridad<T>::Nodo* recorrocamino(typename Coladeprioridad<T>::Nodo* h, Nat n, Nat cant ){
  if(cant == 0){
    return h;
  }else{
    if(n == 0){
      if(h.hijoDer == NULL){
        return h.hijoDer;//esto va a devolver 0
      }else{
        return h.hijoIzq;// esto va a devolver 0
      }}
      else{
        if(EstaCompleto(n, cant)){
          recorrocamino(h.hijoIzq, n-1, cant - 2^n);
        }
        else{
          if(IrPorSubarbolIz(n, cant)){
            recorrocamino(h.hijoIzq, n-1, cant - 2^n);
          }
          else{
            if(EstaEnLaMitad(n,cant)){
              recorrocamino(h.hijoDer, n-2, cant - 2^n);
            }else{
               recorrocamino(h.hijoDer, n-1, cant - 2^n);
            }

      }
    }
  }
}
}

/*
template<class T>
T minimodato(typename Coladeprioridad<T>::Nodo* p1, typename Coladeprioridad<T>::Nodo* p2){
  if(p1->dato > p2->dato){
    return p1->dato;
  }else{
    return p2->dato;
  }

}

template<class T>
typename Coladeprioridad<T>::Nodo* minimonodo(typename Coladeprioridad<T>::Nodo* p1, typename Coladeprioridad<T>::Nodo* p2){
  if(minimodato(p1,p2) == p1->dato){
    return p1;
}else{
  return p2;
}

}


*/




template<class T>
//typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::Encolar(const T& elem){
 void Coladeprioridad<T>::Encolar(const T& elem){ 
  Nat cantidad = cantClaves_;
  Nat niv = nivel_;
  Nat potencia = niv +1;
  Nat cambioniv = 1;
  while(potencia > 0){
    cambioniv= cambioniv << 1;
    potencia--;
  }
  //typename Coladeprioridad<T>::Nodo prueba = heap_;
  typename Coladeprioridad<T>::Nodo** ultimo = recorrocamino(heap_, niv, cantidad);    
  cantClaves_++;
  if(cantClaves_== cambioniv){
    nivel_++;
  }

  (*ultimo) = new typename Coladeprioridad<T>::Nodo(elem);
  (*ultimo) -> dato = elem;
  (*ultimo) -> hijoIzq = NULL;
  (*ultimo) -> hijoDer = NULL;
  if(cantClaves_ == 1){
    heap_ = (*ultimo);    
  }else{
  	typename Coladeprioridad<T>::Nodo* ultpadre = *(recorrocamino(heap_, nivel_-1, (cantClaves_/2)-1));
  (*ultimo)-> padre = ultpadre;
  if(ultpadre-> hijoIzq != NULL){
  	ultpadre -> hijoDer = (*ultimo);
  }else{
  	ultpadre -> hijoIzq = (*ultimo);
  }
  if((*ultimo) -> padre != NULL){      
  while(((*ultimo) -> dato < ( ultpadre -> dato)) or (ultpadre == NULL)){
    if((*ultimo)-> padre == NULL){
      heap_ = (*ultimo);
    }    
    (*(*ultimo)).swap(ultpadre);
  }
}
}
  //return CrearIt((*ultimo));
}

/*

template<class T>
void Coladeprioridad<T>::Encolar(const T& elem){
  Nat cantidad = cantClaves_;
  Nat niv = nivel_;
  //typename Coladeprioridad<T>::Nodo prueba = heap_;
/*  typename Coladeprioridad<T>::Nodo* ultimo = recorrocamino(heap_, niv, cantidad);

)
    
  cantClaves_++;
  if(cantClaves_== 2^(niv+1)){
    nivel_++;
  }
  ultimo = new typename Coladeprioridad<T>::Nodo(elem);
  ultimo -> dato = elem;
  ultimo ->hijoIzq =NULL;
  ultimo-> hijoDer = NULL;
  ultimo -> padre =recorrocamino(heap_, niv-1, (cantidad/2)-1);
  while(ultimo->dato <(ultimo->padre->dato) or ultimo->padre == NULL){
    if(ultimo->padre = NULL){
      heap_ = ultimo;
    }
    swap(ultimo, ultimo->padre);
  }
  return CrearIt(ultimo);
}*/
















/*
template<class T>
typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::Desencolar(){
  typename Coladeprioridad<T>::Nodo* raiz = heap_;
  if(cantClaves_ = (2^nivel_)-1){
    if(nivel_>0){
      nivel_--;
    }    
  }
   typename Coladeprioridad<T>::Nodo* ultimo = recorrocamino(heap_, nivel_, cantClaves_-1);
   swap(ultimo, raiz);
   if(raiz->padre->hijoDer=raiz){
    raiz->padre->hijoDer = NULL;
   }else{
    raiz->padre->hijoIzq = NULL;
  }
  heap_= ultimo;
  T result = raiz->dato;
  delete(raiz);
  while(((ultimo->hijoDer != NULL) and (ultimo->dato > ultimo->hijoDer->dato)) or ((ultimo->hijoIzq != NULL) and (ultimo->dato > ultimo->hijoIzq->dato))){
    if(ultimo->hijoDer != NULL){
      if(ultimo->dato > minimodato(ultimo->hijoIzq, ultimo->hijoDer)){
        swap(minimonodo(ultimo->hijoIzq, ultimo->hijoDer), ultimo);        
      }else{
        if(ultimo->dato > ultimo->hijoDer->dato){
          swap(ultimo->hijoDer, ultimo);
        }else{
          swap(ultimo->hijoIzq, ultimo);
        }
      }
    }else{
      swap(ultimo->hijoIzq, ultimo);
    }
  }
  cantClaves_--;
  return result;
}

template<class T>
void Coladeprioridad<T>::Borrar( typename Coladeprioridad<T>::Iterador ih){ 
  if(cantClaves_ = (2^nivel_)-1){
    if(nivel_>0){
      nivel_--;
    }    
  }
   typename Coladeprioridad<T>::Nodo* ultimo = recorrocamino(heap_, nivel_, cantClaves_-1);
   typename Coladeprioridad<T>::Nodo* raizaborrar = ih.Siguiente();
   swap(ultimo, raizaborrar);
    if(raizaborrar->padre->hijoDer=raizaborrar){
    raizaborrar->padre->hijoDer = NULL;
   }else{
    raizaborrar->padre->hijoIzq = NULL;
  }
  heap_= ultimo;
  delete(raizaborrar);
  while(ultimo->dato <(ultimo->padre->dato) or ultimo->padre == NULL){
    if(ultimo->padre = NULL){
      heap_ = ultimo;
    }
    swap(ultimo, ultimo->padre);
  }
  while(((ultimo->hijoDer != NULL) and (ultimo->dato > ultimo->hijoDer->dato)) or ((ultimo->hijoIzqu != NULL) and (ultimo->dato > ultimo->hijoIzq->dato))){
    if(ultimo->hijoDer != NULL){
      if(ultimo->dato > minimodato(ultimo->hijoIzq, ultimo->hijoDer)){
        swap(minimonodo(ultimo->hijoIzq, ultimo->hijoDer), ultimo);        
      }else{
        if(ultimo->dato > ultimo->hijoDer->dato){
          swap(ultimo->hijoDer, ultimo);
        }else{
          swap(ultimo->hijoIzq, ultimo);
        }
      }
    }else{
      swap(ultimo->hijoIzq, ultimo);
    }
  }
  cantClaves_--;
}
*/

 template<class T>
 typename Coladeprioridad<T>::Iterador CrearIt(typename Coladeprioridad<T>::Nodo* p){
  typename Coladeprioridad<T>::Iterador nuevo;
  return nuevo;
 }


}

#endif // AED2_COLADEPRIORIDAD_H_INCLUDED
