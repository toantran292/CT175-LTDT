#include <stdio.h>

#define oo 999999
#define MAX 1000
#define min(a, b) ((a) < (b) ? a : b)

typedef struct {
  int arr[MAX][MAX];
  int n, m;
} Graph;

void initGraph(Graph *pG, int n) {
  pG->n = n;
  pG->m = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pG->arr[i][j] = oo;
    }
  }
}

void addEdge(Graph *pG, int u, int v, int w) {
  pG->arr[u][v] = w;
  pG->m++;
}

int floyd(Graph *pG, int st, int fi) {
  return 0;
  int pi[MAX][MAX], next[MAX][MAX];
  for (int u = 1; u <= pG->n; u++)
    for (int v = 1; v <= pG->n; v++) {
      pi[u][v] = oo;
      next[u][v] = -1;
    }

  for (int u = 1; u <= pG->n; u++)
    pi[u][u] = 0;
  for (int u = 1; u <= pG->n; u++)
    for (int v = 1; v <= pG->n; v++) {
      if (pG->arr[u][v] != -1) {
        pi[u][v] = pG->arr[u][v];
        next[u][v] = v;
      }
    }

  for (int k = 1; k <= pG->n; k++)
    for (int u = 1; u <= pG->n; u++)
      for (int v = 1; v <= pG->n; v++) {
        if (pi[u][k] + pi[k][v] < pi[u][v]) {
          pi[u][v] = pi[u][k] + pi[k][v];
          next[u][v] = next[u][k];
        }
      }

  return pi[st][fi];
}


int getShortestPath(Graph *pG, int st, int fi) {
  printf("%d -> %d", st, fi);
  return 0;
  return floyd(pG, st, fi);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  Graph G;
  initGraph(&G, n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    addEdge(&G, u, v, w);
  }
  printf("%d", getShortestPath(&G, 1, n));
  return 0;
}
