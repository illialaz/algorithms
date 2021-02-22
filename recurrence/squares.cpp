/* input
3 4
1 1 1 1
1 1 1 1
1 1 0 1
*/
#include <iostream>

using namespace std;

int min(int a, int b, int c) {
  if(a <= b && a <= c) return a;
  if(b <= a && b <= c) return b;
  if(c <= a && c <= b) return c;
}

int main() {
  int n = 0;
  int m = 0;
  scanf("%d %d", &n, &m);

  int** arr = new int*[n];
  for(int i = 0; i < n; i++) {
    arr[i] = new int[m];
    for(int j = 0; j < m; j++) scanf("%d", &arr[i][j]);
  }
  for(int i = 1; i < n; i++) {
    for(int j = 1; j < m; j++) {
      if(arr[i][j] != 0) arr[i][j] += min(arr[i][j - 1], arr[i - 1][j], arr[i - 1][j - 1]);
    }
  }
  int res = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      res += arr[i][j];
    }
  }
  cout << res;
}