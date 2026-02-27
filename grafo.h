#ifndef GRAFO_H
#define GRAFO_H

typedef struct vertex {
    int id;
} vertex;

typedef struct edge {
    struct vertex* V1;
    struct vertex* V2;
} edge;

typedef struct Node {
    void* Dato;
    struct Node* N1;
} Node;

typedef struct graph {
    Node* Vertices;
    Node* Aristas;
} graph;

/* Funciones */
graph* crear_grafo();
vertex* crear_vertice(int id);
void agregar_vertice(graph* G, vertex* v);
void agregar_arista(graph* G, vertex* v1, vertex* v2);
int contar_vertices(Node* vertices);
int** obtenerMatrizadyacencia(graph* G);
void imprimir_matriz(int** matriz, int n);
void liberar_matriz(int** matriz, int n);
void destruir_grafo(graph* G);

#endif