#include <stdio.h>
#define length 1000
#define maxn 1000
typedef struct {
  int data[length];
  int size;
} List;

void makeNullList(List *L){
  L->size = 0;
}
int emptyList(List *L){
  return L->size == 0;
}
int elementAt(List *L, int i){
  return L->data[i-1];
}
void pushBack(List *L, int x){
  if ( L->size + 1 == length) return;
  L->data[L->size++]=x;
}
void copyList(List *D, List *L){
  makeNullList(D);
  if(emptyList(L)) return;
  for(int i = 1; i <= L->size; i++){
    pushBack(D, elementAt(L, i));
  }
}

typedef struct {
  int arr[maxn][maxn];
  int n, m;
} Graph;

void initGraph(Graph *pG, int n) {
  pG->n = n;
  pG->m = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pG->arr[i][j] = 0;
    }
  }
}

void addEdge(Graph *pG, int u, int v) {
  pG->arr[u][v] = 1;
  pG->m++;
}

int r[maxn];

void rank(Graph *G){
  int d[maxn], n = G->n;
  for(int u = 1; u <= n; u++){
    d[u] = 0;
    for(int v = 1; v <= n; v++){
      if(G->arr[v][u]) d[u]++;
    }
  }

  List A, B;
  makeNullList(&A);
  for(int u = 1; u <= n; u++){
    if(!d[u]) pushBack(&A, u);
  }
  int k = 0;
  while(!emptyList(&A)){
    makeNullList(&B);
    for(int i = 1; i <= A.size; i++){
      int u = elementAt(&A, i);
      r[u] = k;

      for(int v = 1; v <= G->n; v++){
        if(G->arr[u][v]) {
          d[v]--;
          if(!d[v]) pushBack(&B, v);
        }
      }
    }
    copyList(&A, &B);
    k++;
  }
}

int main(){
  Graph G;
  int n, m;
  scanf("%d%d", &n, &m);
  initGraph(&G, n);
  for(int i = 0; i < m; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(&G, u, v);
  }

  rank(&G);

  printf("Xep hang dinh cua do thi:\n");
  for(int u = 1; u <= G.n; u++)
    printf("rank[%d] = %d\n", u, r[u]);

  return 0;
}
