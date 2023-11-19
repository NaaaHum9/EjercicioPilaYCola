#ifndef _cola_
#define _cola_
#define TAMCOLA 100
#define TAMPILA 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int cola[TAMCOLA];
    int primero, ultimo;
    int tam;

}Cola;

typedef Cola* COLA;
COLA crearCola();
int es_vaciaCola(COLA C);
int sig(int i);
void encolar(COLA C, int x);
int desencolar(COLA C);
int primero(COLA C);
int copiaCola(COLA C, COLA C1, COLA C2);


typedef struct {
    int pila[TAMPILA];
    int tope;
}Pila;

typedef Pila* PILA;
PILA crearPila();
void apilar(PILA S, char e);
int desapilar(PILA S);
int es_vaciaPila(PILA S);
int elemtope(PILA S);
int copiaPila(PILA S, PILA S2);

#endif