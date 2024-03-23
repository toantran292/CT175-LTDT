
#include <stdio.h>
#define maxn 9999
#define max(a, b) ((a) < (b) ? (b) : (a))
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n + 1][n + 1], b[n + 1], ra[n + 1];
  for (int i = 1; i <= n; i++) {
    b[i] = ra[i] = 0;
    for (int j = 1; j <= n; j++)
      a[i][j] = 0;
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u][v] = 1;
    b[v]++;
  }

  int q[9999], f = -1, r = -1;

  for (int u = 1; u <= n; u++) {
    if (!b[u]) {
      q[++r] = u;
      ra[u] = 1;
    }
  }
  while (f != r) {
    int u = q[++f];
    for (int v = 1; v <= n; v++) {
      if (a[u][v]) {
        b[v]--;
        if (!b[v]) {
          q[++r] = v;
          ra[v] = ra[u] + 1;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    // printf("\n%d: ", i);
    for (int u = 1; u <= n; u++)
      if (ra[u] == i)
        printf("%d ", u);
  }
  return 0;
}
