#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int datosEntrada(COLA, PILA);//solicita los datos int hasta que el usuario indique qeu ya no mas
void mostrarCola(COLA);
int pedirNumero();
int divicion(int, COLA, PILA);
//void llenarPila(COLA, PILA);
int verificarCapicula(COLA, PILA);
void mostrarSiono(int);
void liberarMem(COLA, COLA, PILA, PILA);
void manejaError(int);

int main(){
    COLA C, C1, C2;
    PILA S, S1;
    int veri, nume;

    C = crearCola();
    C1 = crearCola();
    C2 = crearCola();
    S = crearPila();
    S1 = crearPila();
    
    nume = pedirNumero();
    //datosEntrada(C, S);
    divicion(nume, C, S);
    copiaCola(C, C1, C2);
    copiaPila(S, S1);
    veri = verificarCapicula(C, S);
    mostrarCola(C2);
    mostrarSiono(veri);
    liberarMem(C, C1, S, S1);
}

int pedirNumero(){
    int nume;
    printf("\nIngrese el numero:");
    scanf("%i", nume);
    return nume;
}

int divicion(int nume, COLA C, PILA S){
    int div;
    while (es_vaciaCola(C) == FALSE){
        div = nume / 10;
        encolar(C, div);
        apilar(S, div);
    }
    
}

int verificarCapicula(COLA C, PILA S){
    int aux, aux1, veri;
    while (es_vaciaCola(C) == FALSE){
        aux = desencolar(C);
        aux1 = desapilar(S);
        if (aux != aux1){
            veri = 0;
            break;
        }

    }
    return veri;    
}

void mostrarCola(COLA C2){
    int x;
    printf("\nElementos de la cola:\n");
    while (es_vaciaCola(C2) == FALSE){
        x = desencolar(C2);
        printf("%i, ", x);
    }
    
}

void mostrarSiono(int veri){
    if (veri == 0){
        printf("\nEl numero NO es capicua\n");
    }else{
        printf("\nEl numero SI es capicua\n");
    }
    
}

void liberarMem(COLA C, COLA C1, PILA S, PILA S1){
    free(C);
    free(C1);
    free(S);
    free(S1);
    manejaError(1);
}

void manejaError(int msg){
    char * mensajes[] = {"\n\nNo hay memoria disponible", "\n\nSe ha liberado la memoria", 
                        "\n\nPila llena", "\n\nPila vacia", "\n\nCola llena", "\n\nCola vacia"};
    printf("%s", mensajes[msg] );
}