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
      Nodo(const T& d) :  hijoDer(NULL), hijoIzq(NULL), dato(d), padre(NULL){};
      Nodo(const typename Coladeprioridad<T>::Nodo* otro) :
      hijoDer(NULL), hijoIzq(NULL), dato(otro->dato), padre(NULL) {};
      Nodo& operator=(const typename Coladeprioridad<T>::Nodo& otro)
      { hijoIzq(otro->hijoDer), hijoDer(otro->hijoIzq),dato(otro->dato), padre(otro->padre);}


      Nodo* hijoDer;
      Nodo* hijoIzq;
      T dato;     
      Nodo* padre;     

     T Dato(){    //TESTING
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
    void swap(Nodo* &p2){
      if(this != p2){
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
        p2-> hijoDer = hijoDer;
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
          if(anterior-> hijoIzq == p2){
            anterior-> hijoIzq = this;
          }else{
            anterior-> hijoDer = this;
          }
        }   
        (p2->padre) = this;    
        (padre) = anterior;
      }else{
        typename Coladeprioridad<T>::Nodo* derecha = p2-> hijoDer;
        typename Coladeprioridad<T>::Nodo* izquierda = p2-> hijoIzq;
        typename Coladeprioridad<T>::Nodo* anterior = p2-> padre;
        if(hijoIzq != NULL){
          hijoIzq-> padre = p2;
        }
        p2-> hijoIzq = hijoIzq;
        if(hijoDer != NULL){
          hijoDer-> padre = p2;
        }
        p2-> hijoDer = hijoDer;
        if(padre != anterior){
        if(padre-> hijoIzq == this){  
          padre-> hijoIzq= p2;
        }else{
          padre-> hijoDer= p2;
        }
        if(anterior != NULL){
          if(anterior-> hijoIzq == p2){
            anterior-> hijoIzq = this;
          }else{
            anterior-> hijoDer = this;
          }
        }
      }else{
        if(padre-> hijoIzq == this){
          padre ->hijoIzq = p2;
          padre ->hijoDer = this;
        }else{
          padre ->hijoDer = p2;
          padre ->hijoIzq = this;
        }
      }
   // p2->hijoDer = p1->hijoIzq;
   // p2->hijoIzq = p1->hijoDer;       
        p2-> padre = padre;
        hijoIzq =   izquierda;
        hijoDer = derecha;
        padre = anterior;
        if(izquierda != NULL){
        izquierda-> padre = this;
        }
        if(derecha != NULL){
        derecha-> padre= this;
        }

      }
    }  
  }


    };

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

   typename Coladeprioridad<T>::Nodo** recorrocamino(typename Coladeprioridad<T>::Nodo* &h, Nat n, Nat cant) {      
      Nat potencia = n;
      Nat resta = 1;   
      while(potencia > 0) {
        resta = resta << 1;
        potencia--;  
      }
      if (cant == 0) {
        return (&h);
      } 
      if(cant == 1){          
       return (&h->hijoIzq);
      }
      if((n == 1) && (!EstaCompleto(n, cant))){      
        return &(h->hijoDer);       
      }else{        
        if(EstaCompleto(n, cant)){              
          recorrocamino(h->hijoIzq, n-1, cant - resta);
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
     
     //return NULL;
   }


















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



















  /// Crea una coladeprioridad vacía. (Operación Vacia())
   Coladeprioridad();
  Nat Claves();//TESTING
  Nat Nivel(); //TESTING


  /// Crea por copia una coladeprioridad (operación Copiar())
 // Coladeprioridad(const Coladeprioridad& otra);

  /// Destruye la coladepriorida, incluyendo los T alojados
  ~Coladeprioridad();

  /// Operacion de asignacion
  //Coladeprioridad<T>& operator=(const Coladeprioridad<T>& otra);


  /// Opreaciones básicas
  bool EsVacia() const;




  Coladeprioridad<T>::Iterador Encolar(const T& elem);
  //Coladeprioridad<T>::Iterador Desencolar();
  void Desencolar();





  //ve el top de la cola
  T& tope() const; 


 Coladeprioridad<T>::Iterador CrearIt();
  /**********************************
   * Iterador de ColadeprioridadLista, modificable *
   **********************************/
   class Iterador
   {
   public:  


      //Iterador(const typename Coladeprioridad<T>::Iterador& otro);

      Iterador& operator = (const typename Coladeprioridad<T>::Iterador& otro){
        cola_ = otro.cola_;
        apuntador_ = otro.apuntador_;
        return *this;
      }

      Iterador(const typename Coladeprioridad<T>::Iterador& otro);




      bool HaySiguiente();// const;

      T& Siguiente();


      void borrarSiguiente();//toma un iterador, lo inicializa con la cola que lo llamo, y agrega.

     // void Agregar(const T& elem);

      //const T& Siguiente() const;  


     // bool operator == (const typename Lista<T>::Iterador& otro) const;

    private:


     Coladeprioridad<T>* cola_;


     typename Coladeprioridad<T>::Nodo* apuntador_;


     Iterador(){
      cola_= NULL;
      apuntador_ = NULL;        
    }
    Iterador(Coladeprioridad<T>* c, typename Coladeprioridad<T>::Nodo* p){
      cola_= c;
      apuntador_ = p;        
    }


    friend typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::CrearIt(typename Coladeprioridad<T>::Nodo* p); 
    friend typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::CrearIt(); 

      //friend typename Coladeprioridad<T>::Iterador CrearIt(typename Coladeprioridad<T>::Nodo* n);







  };



private:




 Nodo* heap_;
 Nat cantClaves_;
 Nat nivel_;





 // Coladeprioridad<T>::Nodo* recorrocamino(Coladeprioridad::Nodo* h, Nat n, Nat cant);

T minimodato(Coladeprioridad<T>::Nodo* p1, Coladeprioridad<T>::Nodo* p2);
Nodo* minimonodo(Coladeprioridad<T>::Nodo* p1, Coladeprioridad<T>::Nodo* p2); 
Coladeprioridad<T>::Iterador CrearIt(typename Coladeprioridad<T>::Nodo* p);



};





//template<class T>
//std::ostream& operator << (std::ostream& os, const Lista<T>& l);

//template<class T>
//bool operator == (const Lista<T>& l1, const Lista<T>& k2);

 //  Implementacion de Coladeprioridad
template <typename T>
Coladeprioridad<T>::Coladeprioridad()
: heap_(NULL), cantClaves_(0), nivel_(0)
{}

template <typename T>//TESTING
Nat Coladeprioridad<T>::Claves(){
	return cantClaves_;
}

template <typename T>//TESTING
Nat Coladeprioridad<T>::Nivel(){
	return nivel_;
}

 
template <typename T>
Coladeprioridad<T>::Iterador::Iterador(const typename Coladeprioridad<T>::Iterador& otro)
  : cola_(otro.cola_), apuntador_(otro.apuntador_)
{}










//template <typename T>
//Coladeprioridad<T>::Coladeprioridad(const Coladeprioridad<T>& otra)
//  : primero_(NULL), longitud_(0)
//{
  // TODO la idea es que haga shallow copy? //QUE SIGNIFICA ESTO  
  // Pense que por convencon definiamos este operador con deep copy
  // de hecho el operador = hace deep copy
//  *this = otra;
//}



template <typename T>
Coladeprioridad<T>::~Coladeprioridad()
{
  while(!EsVacia()) {
    Desencolar();
  }
}

template <typename T>
bool Coladeprioridad<T>::EsVacia() const
{
  return heap_ == NULL;
}


template<class T>
T& Coladeprioridad<T>::tope() const {

  return heap_-> dato;

} 








template<class T>
T Coladeprioridad<T>::minimodato(typename Coladeprioridad<T>::Nodo* p1, typename Coladeprioridad<T>::Nodo* p2){
  if(p1->dato < p2->dato){
    return p1->dato;
  }else{
    return p2->dato;
  }

}

template<class T>
typename Coladeprioridad<T>::Nodo* Coladeprioridad<T>::minimonodo(typename Coladeprioridad<T>::Nodo* p1, typename Coladeprioridad<T>::Nodo* p2){
  if(minimodato(p1,p2) == p1->dato){
    return p1;
  }else{
    return p2;
  }

}



template<class T>
typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::Encolar(const T& elem){
   Nat potencia = nivel_ + 1;
  Nat cambioniv = 1;
  while(potencia > 0){
    cambioniv= cambioniv << 1;
    potencia--;
  } 
  typename Coladeprioridad<T>::Nodo* ultimo = *(recorrocamino(heap_, nivel_, cantClaves_));      
  cantClaves_++;
  if(cantClaves_== cambioniv){
   nivel_++;
  } 
 ultimo = new typename Coladeprioridad<T>::Nodo(elem);
 if(cantClaves_ == 1){
   heap_ = ultimo;           
 }else{
  typename Coladeprioridad<T>::Nodo* ultpadre = *(recorrocamino(heap_, nivel_-1, (cantClaves_/2)-1 ));  
  ultimo-> padre = ultpadre;  
  if(ultpadre-> hijoIzq != NULL){
    ultpadre -> hijoDer = ultimo;
  }else{
    ultpadre -> hijoIzq = ultimo;
  }     
  if(ultimo -> padre != NULL){   
    while((ultimo->padre != NULL) and (ultimo-> dato < ((ultimo->padre) -> dato))){
      cout << "padre" <<ultpadre->dato << endl;
      cout << "hijo"<<ultimo->dato << endl;    
      (*ultimo).swap(ultimo->padre);
      cout << "llega"<< endl;
    }      
  }    
    if(ultimo->padre == NULL){
      heap_ = (ultimo);
    }    
}

 typename Coladeprioridad<T>::Iterador nuevo = CrearIt(ultimo); 
 return nuevo;
 
}

/*
template<class T>
typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::Desencolar(){
  typename Coladeprioridad<T>::Iterador nuevo = CrearIt(heap_);  
  nuevo.borrarSiguiente();
  return nuevo;
}
*/

template<class T>
 void Coladeprioridad<T>::Desencolar(){
  typename Coladeprioridad<T>::Iterador nuevo = CrearIt(heap_);  
  nuevo.borrarSiguiente();  
}







 template<class T>
typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::CrearIt(typename Coladeprioridad<T>::Nodo* p){
  typename Coladeprioridad<T>::Iterador nuevo(this, p);
  return nuevo;//VER SI ESTO NO DEBERIA DEVOLVER VOID
}


template<class T>
typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::CrearIt(){
  typename Coladeprioridad<T>::Iterador nuevo(this, this->heap_);
  return nuevo;//VER SI ESTO NO DEBERIA DEVOLVER VOID
}

//FUNCIONES DEL ITERADOR::

   template<class T> 
bool Coladeprioridad<T>::Iterador::HaySiguiente(){
  return (apuntador_ != NULL);


 }// const;
  template<class T>    
 T& Coladeprioridad<T>::Iterador::Siguiente(){
  return (apuntador_ -> dato);

}

 template<class T>
//typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::Iterador::borrarSiguiente(){
  void Coladeprioridad<T>::Iterador::borrarSiguiente(){  
  Nat potencia = cola_->nivel_;
  Nat cambionivel = 1;
  while(potencia > 0){
    cambionivel = cambionivel << 1;
    potencia--;
  }
  if(cola_-> cantClaves_ > 0 ){
  cola_-> cantClaves_--;
  }  
  if(cola_->cantClaves_ == (cambionivel)-1){
    if(cola_->nivel_ > 0){    
     cola_->nivel_--;
    }    
  }
  typename Coladeprioridad<T>::Nodo* ultimo = (*(*cola_).recorrocamino(cola_->heap_,cola_->nivel_, ((cola_->cantClaves_))));
  //cout <<"ultimodato" << (*ultimo).Dato() << endl;
  typename Coladeprioridad<T>::Nodo* raizaborrar = apuntador_;
  typename Coladeprioridad<T>::Nodo* ultpadre = ultimo->padre;
  //en el arbol real hay una mas hasta que se elimine el ultimo. 
  if( cola_->cantClaves_ == 0 ){    
    cola_->heap_ = NULL;    
    delete(ultimo);
  }else{      
  (*ultimo).swap(raizaborrar); 
  if(raizaborrar->padre != NULL){       
  if((raizaborrar->padre)->hijoDer == raizaborrar){     
    (raizaborrar->padre)->hijoDer = NULL;
  }
  if((raizaborrar->padre)->hijoIzq == raizaborrar){     
    (raizaborrar->padre)->hijoIzq = NULL;
  }
  }  
  if(ultimo->padre == NULL){   
  cola_->heap_ = ultimo;
  }
  if(raizaborrar == ultimo){   
  delete(raizaborrar);
  }else{ 
  delete(raizaborrar); 
  //aca va el sifht up de agregar
  ultpadre = ultimo->padre;
  if(ultimo -> padre != NULL){         
    //while((ultimo -> dato < ( ultpadre -> dato)) and (ultimo->padre != NULL)){ 
    while((ultimo->padre != NULL) and (ultimo-> dato < ((ultimo->padre) -> dato))){           
      (*ultimo).swap(ultimo->padre);
    }      
  } 
  if(ultimo->padre == NULL){
  cola_->heap_ = ultimo;
  }    
  while(((ultimo->hijoDer != NULL) and (ultimo->dato > ultimo->hijoDer->dato)) or ((ultimo->hijoIzq != NULL) and (ultimo->dato > ultimo->hijoIzq->dato))){  
    if(ultimo->hijoDer != NULL){  
      if(ultimo->dato > (*cola_).minimodato(ultimo->hijoIzq, ultimo->hijoDer)){        
        typename Coladeprioridad<T>::Nodo* minnodo = (*cola_).minimonodo(ultimo->hijoIzq, ultimo->hijoDer);
        (*minnodo).swap(ultimo);        
        if(minnodo->padre == NULL){
           cola_->heap_ = minnodo;           
        }  
     }else{  
         typename Coladeprioridad<T>::Nodo* ulthDer = ultimo->hijoDer;
      if(ultimo->dato > ulthDer->dato){
        (*(ulthDer)).swap(ultimo);
        if((ulthDer)->padre == NULL){
           cola_->heap_ = ulthDer;
        }
      }else{
        typename Coladeprioridad<T>::Nodo* ulthIzquierda = ultimo->hijoIzq;
       (*(ulthIzquierda)).swap(ultimo);
       if((ulthIzquierda)->padre == NULL){
           cola_->heap_ = ulthIzquierda;
        }
     }
   }
 }else{  
  typename Coladeprioridad<T>::Nodo* ulthIz = ultimo->hijoIzq;
  (*(ulthIz)).swap(ultimo);  
  if((ulthIz -> padre) == NULL){   
     cola_->heap_ = ulthIz;
  }
}
}
}
}
//if(ultimo->padre == NULL){
//  cola_->heap_ = ultimo;
//}
 apuntador_= NULL;  
}


/*
 template<class T>
void  Coladeprioridad<T>::Iterador::Agregar(const T& elem){
  Nat potencia = cola_->nivel_ + 1;
  Nat cambioniv = 1;
  while(potencia > 0){
    cambioniv= cambioniv << 1;
    potencia--;
  } 
  typename Coladeprioridad<T>::Nodo* ultimo = (*(*cola_).recorrocamino(cola_->heap_, cola_->nivel_, cola_ -> cantClaves_));      
  cola_->cantClaves_++;
  if(cola_-> cantClaves_== cambioniv){
   cola_->nivel_++;
  } 
 ultimo = new typename Coladeprioridad<T>::Nodo(elem);
 if(cola_-> cantClaves_ == 1){
   cola_->heap_ = ultimo;           
 }else{
  typename Coladeprioridad<T>::Nodo* ultpadre = *((*cola_).recorrocamino(cola_->heap_, cola_->nivel_-1, (cola_->cantClaves_/2)-1 ));  
  ultimo-> padre = ultpadre;  
  if(ultpadre-> hijoIzq != NULL){
    ultpadre -> hijoDer = ultimo;
  }else{
    ultpadre -> hijoIzq = ultimo;
  }   

  if(ultimo -> padre != NULL){      
    while((ultimo -> dato < ( ultpadre -> dato)) and (ultimo->padre != NULL)){
      cout << ultpadre->dato << endl;    
      (*ultimo).swap(ultimo->padre);

    }      
  }    
    if(ultimo->padre == NULL){
      cola_->heap_ = (ultimo);
    }    
}
apuntador_ = ultimo;
}

*/



/*


template<class T>
//typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::Encolar(const T& elem){
 void Coladeprioridad<T>::Encolar(const T& elem){ 
  Nat cantidad = cantClaves_;
  Nat niv = nivel_;
  Nat potencia = niv + 1;
  Nat cambioniv = 1;
  while(potencia > 0){
    cambioniv= cambioniv << 1;
    potencia--;
  }  
  typename Coladeprioridad<T>::Nodo** ultimo = recorrocamino(heap_, niv, cantidad);      
  cantClaves_++;
  if(cantClaves_== cambioniv){
    nivel_++;
  }
  (*ultimo) = new typename Coladeprioridad<T>::Nodo(elem);
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
    typename Coladeprioridad<T>::Nodo hola(3);
    typename Coladeprioridad<T>::Nodo* dirhola = &(hola);
    typename Coladeprioridad<T>::Nodo adios(4);
    typename Coladeprioridad<T>::Nodo* diradios = &(adios);
    //adios.HacerHijo(dirhola);       
    //hola.swap(diradios);
    (*(*ultimo)).swap(ultpadre);
  }
}
}
  //return CrearIt((*ultimo));
}

template<class T>
void Coladeprioridad<T>::Borrar( typename Coladeprioridad<T>::Iterador ih){ 
  Nat potencia = nivel_;
  Nat cambionivel = 1;
  while(potencia > 0){
  cambionivel = cambionivel << 1;
  potencia--;
  }
  if(cantClaves_ == (cambionivel)-1){
    if(nivel_>0){
      nivel_--;
    }    
  }
   typename Coladeprioridad<T>::Nodo** ultimo = recorrocamino(heap_, nivel_, cantClaves_-1);
   typename Coladeprioridad<T>::Nodo* raizaborrar = ih.Siguiente();
   (*ultimo)swap(raizaborrar);
    if(raizaborrar->padre->hijoDer == raizaborrar){
    raizaborrar->padre->hijoDer = NULL;
   }else{
    raizaborrar->padre->hijoIzq = NULL;
  }
  heap_= (*ultimo);
  delete(raizaborrar);
  while((*ultimo)->dato <((*ultimo)->padre->dato) or (*ultimo)->padre == NULL){
    if((*ultimo)->padre = NULL){
      heap_ = (*ultimo);
    }
    (*ultimo).swap((*ultimo)->padre);
  }
  while((((*ultimo)->hijoDer != NULL) and ((*ultimo)->dato > (*ultimo)->hijoDer->dato)) or (((*ultimo)->hijoIzqu != NULL) and ((*ultimo)->dato > (*ultimo)->hijoIzq->dato))){
    if((*ultimo)->hijoDer != NULL){
      if((*ultimo)->dato > minimodato((*ultimo)->hijoIzq, (*ultimo)->hijoDer)){
       minimonodo((*ultimo)->hijoIzq, (*ultimo)->hijoDer).swap((*ultimo));        
      }else{
        if((*ultimo)->dato > (*ultimo)->hijoDer->dato){
          (*ultimo)->hijoDer.swap((*ultimo));
        }else{
         (*ultimo)->hijoIzq.swap((*ultimo));
        }
      }
    }else{
      (*ultimo)->hijoIzq.swap((*ultimo));
    }
  }
  cantClaves_--;
}


template<class T>
typename Coladeprioridad<T>::Iterador Coladeprioridad<T>::Desencolar(){
  typename Coladeprioridad<T>::Nodo* raiz = heap_;
  Nat potencia = nivel_;
  Nat cambionivel = 1;
  while(potencia > 0){
  cambionivel = cambionivel << 1;
  potencia--;
  }
  if(cantClaves_ == cambionivel-1){
    if(nivel_>0){
      nivel_--;
    }    
  }
   typename Coladeprioridad<T>::Nodo** ultimo = recorrocamino(heap_, nivel_, cantClaves_-1);
   (*ultimo).swap(raiz);
   if(raiz->padre->hijoDer=raiz){
    raiz->padre->hijoDer = NULL;
   }else{
    raiz->padre->hijoIzq = NULL;
  }
  heap_= (*ultimo);
  T result = raiz->dato;
  delete(raiz);
  while((((*ultimo)->hijoDer != NULL) and ((*ultimo)->dato > (*ultimo)->hijoDer->dato)) or (((*ultimo)->hijoIzq != NULL) and ((*ultimo)->dato > (*ultimo)->hijoIzq->dato))){
    if((*ultimo)->hijoDer != NULL){
      if((*ultimo)->dato > minimodato((*ultimo)->hijoIzq, (*ultimo)->hijoDer)){
       minimonodo((*ultimo)->hijoIzq, (*ultimo)->hijoDer).swap( (*ultimo));        
      }else{
        if((*ultimo)->dato > (*ultimo)->hijoDer->dato){
          (*ultimo)->hijoDer.swap((*ultimo));
        }else{
         (*ultimo)->hijoIzq.swap((*ultimo));
        }
      }
    }else{
      (*ultimo)->hijoIzq.swap((*ultimo));
    }
  }
  cantClaves_--;
  return result;
}





*/










}

#endif // AED2_COLADEPRIORIDAD_H_INCLUDED
