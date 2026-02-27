#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



graph* crear_grafo() {
    graph* G = malloc(sizeof(graph));
    G->Vertices = NULL;
    G->Aristas = NULL;
    return G;
}

vertex* crear_vertice(int id) {
    vertex* v = malloc(sizeof(vertex));
    v->id = id;
    return v;
}

void agregar_vertice(graph* G, vertex* v) {
    Node* nuevo = malloc(sizeof(Node));
    nuevo->Dato = v;
    nuevo->N1 = G->Vertices;
    G->Vertices = nuevo;
}

void agregar_arista(graph* G, vertex* v1, vertex* v2) {
    edge* e = malloc(sizeof(edge));
    e->V1 = v1;
    e->V2 = v2;

    Node* nuevo = malloc(sizeof(Node));
    nuevo->Dato = e;
    nuevo->N1 = G->Aristas;
    G->Aristas = nuevo;
}


int contar_vertices(Node* vertices) {
    int count = 0;
    while (vertices) {
        count++;
        vertices = vertices->N1;
    }
    return count;
}

int obtener_indice(vertex** array, int n, vertex* v) {
    for (int i = 0; i < n; i++) {
        if (array[i] == v)
            return i;
    }
    return -1;
}

int** obtenerMatrizadyacencia(graph* G) {
    int n = contar_vertices(G->Vertices);

    vertex** vertices_array = malloc(n * sizeof(vertex*));
    Node* temp = G->Vertices;

    for (int i = 0; i < n; i++) {
        vertices_array[i] = (vertex*) temp->Dato;
        temp = temp->N1;
    }

    int** matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = calloc(n, sizeof(int));
    }

    Node* arista_node = G->Aristas;
    while (arista_node) {
        edge* e = (edge*) arista_node->Dato;

        int i = obtener_indice(vertices_array, n, e->V1);
        int j = obtener_indice(vertices_array, n, e->V2);

        if (i != -1 && j != -1) {
            matriz[i][j] = 1;
            matriz[j][i] = 1;  
        }

        arista_node = arista_node->N1;
    }

    free(vertices_array);
    return matriz;
}

void imprimir_matriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void liberar_matriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void destruir_grafo(graph* G) {
    Node* temp;

    while (G->Vertices) {
        temp = G->Vertices;
        G->Vertices = G->Vertices->N1;
        free(temp->Dato);
        free(temp);
    }

    while (G->Aristas) {
        temp = G->Aristas;
        G->Aristas = G->Aristas->N1;
        free(temp->Dato);
        free(temp);
    }

    free(G);
}