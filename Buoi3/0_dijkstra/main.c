
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

int dijkstra(Graph *pG, int st, int fi) {
  int mark[MAX], pi[MAX], p[MAX];
  for (int i = 1; i <= pG->n; i++) {
    pi[i] = oo;
    mark[i] = 0;
  }
  pi[st] = 0;
  p[st] = -1;
  int u = st;
  for (int e = 1; e <= pG->n; e++) {
    // Choose pi min
   int min_pi = oo;
    for (int i = 1; i <= pG->n; i++) {
      if (!mark[i] && pi[i] < min_pi) {
        min_pi = pi[i];
        u = i;
      }
    }
    mark[u] = 1;
    for (int v = 1; v <= pG->n; v++) {
      if (!mark[v] && pG->arr[u][v] != oo) {
        pi[v] = min(pi[v], pi[u] + pG->arr[u][v]);
        p[v] = u;
      }
    }
  }

  return (pi[fi] == oo ? -1 : pi[fi]);
}

int getShortestPath(Graph *pG, int st, int fi) {
  return dijkstra(pG, st, fi);
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

// lớn hơn 20,  đi qua đỉnh 4 hỏi đã duyệt các đỉnh nào
