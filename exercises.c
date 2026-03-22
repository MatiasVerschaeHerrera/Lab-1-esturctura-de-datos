#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for(int i = 0; i < 11; i++){
      int* ptr = (int*) malloc(sizeof(int));
      *ptr = i;
      pushFront(L, ptr);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int cont = 0;
   int* primerElemento = first(L);
   while(primerElemento != NULL){
      cont += *primerElemento;
      primerElemento = next(L);
   }
   return cont;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int* primerElemento = first(L);
   while(primerElemento != NULL){
      if(*primerElemento == elem){
         popCurrent(L);
      }
      primerElemento = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* pilaAux = create_stack();
   Stack* pilaAux2 = create_stack();
   while(top(P1) != NULL){
      push(pilaAux, top(P1));
      push(pilaAux2, pop(P1));
   }
   while(top(pilaAux) != NULL){
      push(P2, pop(pilaAux));
   }
   while(top(pilaAux2) != NULL)
      push(P1, pop(pilaAux2));
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* pila = create_stack();
   int posCadena = 0;
   while(cadena[posCadena] != '\0'){
      char elemento = cadena[posCadena];
      if(elemento == '(' || elemento == '{' || elemento == '['){
         push(pila, elemento);
      }
      else if(elemento == ')' || elemento == '}' || elemento == ']'){
         if(pila != NULL){
            if((elemento == ')' && top(pila) == '(') || (elemento == '}' && top(pila) == '{') || (elemento == ']' && top(pila) == '[')){
               pop(pila);
               if(pila == NULL) return 1;
            }
         }
         else return 0;
      }
      posCadena++;
   }
}

/*link chat gpt:
https://chatgpt.com/s/t_69bc557b5b888191909be64ec4447937
*/