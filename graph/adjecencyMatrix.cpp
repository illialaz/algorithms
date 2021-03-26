/*input.txt
4 3
1 2
1 3
2 4
*/
#include <iostream>

using namespace std;
int matr[100][100];

void init(int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      matr[i][j] = 0;
    }
  }
}

void print(int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - 1; j++) {
      printf("%d ", matr[i][j]);
    }
    printf("%d\n", matr[i][n - 1]);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  int m = 0;
  scanf("%d %d", &n, &m);
  int a = 0;
  int b = 0;
  init(n);

  for(int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    a--;
    b--;
    matr[a][b] = matr[b][a] = 1;
  }

  print(n);
}
