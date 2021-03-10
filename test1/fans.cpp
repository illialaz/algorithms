/* input.txt
5
5 10 15
2 10 15
5 5 5
20 20 1
20 1 1
*/

#include <iostream>

using namespace std;

int min(int a, int b, int c) {
  int res = a;
  if(b < res) res = b;
  if(c < res) res = c;
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  scanf("%d", &n);

  int** fans = new int*[n];

  for(int i = 0; i < n; i++) {
    fans[i] = new int[3];
    scanf("%d %d %d", &fans[i][0], &fans[i][1], &fans[i][2]);
  }

  int res [n + 1];
  res[n] = 0;
  if(n > 0) res[n-1] = fans[n-1][0];
  if(n > 1) res[n-2] = min(fans[n-2][1], fans[n-2][0] + res[n - 1]);
  for(int i = n - 3; i >= 0; i--) {
    res[i] = min(fans[i][2] + res[i + 3], fans[i][1] + res[i + 2], fans[i][0] + res[i + 1]);
  }

  cout << res[0];
}
