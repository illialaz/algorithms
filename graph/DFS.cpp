/*input.txt
7
0 1 1 0 0 0 0
0 0 0 0 1 0 0
0 1 0 1 1 0 0
0 1 0 0 1 0 0
0 0 0 0 0 1 0
0 0 0 1 0 0 0
0 0 0 0 0 1 0
*/
#include <iostream>

using namespace std;

int matr[100][100];
int visited[100];
int ind = 1;

void dfs(int v, int n) {
  visited[v] = ind;
  ind++;

  for(int u = 0; u < n; u++) {
    if(matr[v][u] && visited[u] == -1) dfs(u, n);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  scanf("%d", &n);

  int tmp = 0;
  for(int i = 0; i < n; i++) {
    visited[i] = -1;
    for(int j = 0; j < n; j++) {
      scanf("%d", &tmp);
      matr[i][j] = tmp;
    }
  }
  for(int i = 0; i < n; i++){
    if(visited[i] == -1) dfs(i, n);
  }
  for(int i = 0; i < n; i++) printf("%d ", visited[i]);
}