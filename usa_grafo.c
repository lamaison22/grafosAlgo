/*
 * Tarefa de laboratorio 01 - Pilha
 *
 * GEN254 - Grafos - 2022/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"
#include "graph.h"

int main() {
    int N;
    Graph *graph;
    int i;
    Aresta aresta;

    // scanf("%d", &N);

    graph = GRAPHconstroi(5);
    GRAPHinsere_aresta(graph, ARESTA(0,1));
    GRAPHinsere_aresta(graph, ARESTA(0,2));
    GRAPHinsere_aresta(graph, ARESTA(0,4));

    GRAPHimprime(graph);

    GRAPHremove_aresta(graph,ARESTA(0,2));
    GRAPHimprime(graph);
    GRAPHcaminhoGeraMarcado(graph,0,4);
    
    printf("Num arestas: %d \n",GRAPHget_num_aresta(graph));
    printf("Num verts: %d \n",GRAPHget_num_vertice(graph));




  

    GRAPHdestroi(graph);

    return 0;
}
