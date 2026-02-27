#include <stdio.h>
#include "grafo.h"

int main() {
    graph* G = crear_grafo();

    vertex* v1 = crear_vertice(1);
    vertex* v2 = crear_vertice(2);
    vertex* v3 = crear_vertice(3);

    agregar_vertice(G, v1);
    agregar_vertice(G, v2);
    agregar_vertice(G, v3);

    agregar_arista(G, v1, v2);
    agregar_arista(G, v2, v3);

    int n = contar_vertices(G->Vertices);

    int** matriz = obtenerMatrizadyacencia(G);

    printf("Matriz de adyacencia:\n");
    imprimir_matriz(matriz, n);

    liberar_matriz(matriz, n);
    destruir_grafo(G);

    return 0;
}