#include <stdio.h>
#define MAXN 1000
typedef struct {
  int u, v, w;
} Edge;

typedef struct {
  Edge edges[MAXN];
  int n, m;
} Graph;

void initGraph(Graph *pG, int n){
  pG->n = n;
  pG->m = 0;
}

void addEgde(Graph *pG, int u, int v, int w){
  pG->edges[pG->m].u = u;
  pG->edges[pG->m].v = v;
  pG->edges[pG->m++].w = w;
}

int par[MAXN];

void swap(Edge *a, Edge *b){
  Edge c = *a;
  *a = *b;
  *b = c;
}

void initPar(int n){
  for(int i = 1; i <= n; i++){
    par[i] = i;
  }
}

int findRoot(int u){
  if(par[u] == u) return u;
  return par[u] = findRoot(par[u]);
}

int join(int u, int v){
  u = findRoot(u);
  v = findRoot(v);
  if(u == v) return 0;
  par[v] = u;
  return 1;
}



int Kruskral(Graph *pG, Graph *pT){
  int n = pG->n, m = pG->m;
  for(int u = 0; u < m; u++){
    for(int v = 0; v < m; v++){
      if(pG->edges[u].w < pG->edges[v].w)
        swap(&pG->edges[u], &pG->edges[v]);
    }
  }

  // for(int i = 0; i < m; i++){
  //   printf("\n%d %d %d", pG->edges[i].u, pG->edges[i].v, pG->edges[i].w);
  // }

  initGraph(pT, n);
  initPar(n);

  int total = 0;
  for(int i = 0; i < m; i++){
    int u = pG->edges[i].u,
        v = pG->edges[i].v,
        w = pG->edges[i].w;

    if(join(u, v)){
      addEgde(pT, u, v, w);
      total += w;
    }
  }

  return total;
}

int main(){
  Graph G, T;
  int n, m;
  scanf("%d%d", &n, &m);
  initGraph(&G, n);

  for(int i = 0; i < m; i++){
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    addEgde(&G, u, v, w);
  }

  int sum = Kruskral(&G, &T);
  printf("Cay khung co trong so nho nhat la: %d", sum);

  for(int i = 0; i < T.m; i++){
    printf("\n%d %d %d", T.edges[i].u, T.edges[i].v, T.edges[i].w);
  }

  return 0;
}

// Tong chi phi cua he thong, khong di qua duong 4 - 5
