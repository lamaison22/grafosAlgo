/*
 * Tarefa de laboratorio 00_a - Pilha
 *
 * GEN254 - GRAPHs - 2022/2
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


struct graph {
    int num_v;
    int num_a;
    int **matriz;
};

Graph *GRAPHconstroi(int num_v) {
    Graph *g;

    g = malloc(sizeof(*g));

    g->num_v = num_v;
    g->num_a = 0;

    g->matriz = malloc(num_v * sizeof(int*));

    for (int i = 0; i < num_v; i++)
    {
        g->matriz[i] = malloc(num_v * sizeof(int));
    }
    
    for (int i = 0; i < num_v; i++)
    {
        for (int j = 0; j < num_v; j++)
        {
            g->matriz[i][j] = 0;
        }
    }

    return g;
}
void GRAPHinsere_aresta(Graph *g, Aresta a){
    if(a.v1==a.v2)return;
    if(g->matriz[a.v1][a.v2]==0){
        g->matriz[a.v1][a.v2]=1;
        g->matriz[a.v2][a.v1]=1;
        g->num_a++;
    }
}
void GRAPHremove_aresta(Graph *g, Aresta a){

    if(g->matriz[a.v1][a.v2]==1){
        g->matriz[a.v1][a.v2]=0;
        g->matriz[a.v2][a.v1]=0;
        g->num_a--;
    }
}
int GRAPHget_num_aresta(Graph *g){
    return g->num_a;
}

int GRAPHget_num_vertice(Graph *g){
    return g->num_v;
}
void GRAPHimprime(Graph *g){
    for (int i = 0; i < g->num_v; i++)
    {
        printf("%d:",i);
        for (int j = 0; j < g->num_v; j++){
            if(g->matriz[i][j]==1){
                printf(" %d",j);
            }
        }
            printf("\n");
        
    }
    
}


// static bool GRAPHcaminho(Graph *g, int v, int w, int marcado[], int indent) {
//     for (int i = 0; i < indent; i++) printf("    ");
//     printf("caminho | v1: %d, v2: %d\n", v, w);

//     if (v == w) {
//         printf("%d ", v);
//         return true;
//     }

//     marcado[v] = 1;
//     for (int u = 0; u < g->num_v; u++)
//         if (g->matriz[v][u] != 0)
//             if (marcado[u] == 0)
//                 if (caminho(g, u, w, marcado, indent + 1)) {
//                     printf("%d ", v);
//                     return true;
//                 }
//     return false;
// }

bool GRAPHcaminho(Graph *g, int v, int w) {
    int marcado[g->num_v];

    for (int i = 0; i < g->num_v; i++) {
        marcado[i] = 0;
    }

    bool has_path = caminho(g, w, v, marcado, 0);
    printf("\n");
    return has_path;
}

int GRAPHconexo(Graph *g){
    for(int i = 0; i < g->num_v; i++){
        for(int j = i + 1; j < g->num_v; j++){
            if(i != j)
                if(GRAPHcaminho(g, i, j) == false) return 1;
        }
    }
    return 0;
}
// bool GRAPHcaminhoGeraMarcado(Graph *g,int v, int w){
//     int marcado[g->num_v];
//     for (int i = 0; i < g->num_v; i++)
//     {
//         marcado[i]=0;
//     }
//     return GRAPHcaminho(g,v,w,marcado);
    


// }


void GRAPHdestroi(Graph *g) {
    
    for (int i = 0; i < g->num_v; i++)
    {
        free(g->matriz[i]); //linha
    }
    
    free(g->matriz); //vet q segura a linha
    free(g); // struct
}
