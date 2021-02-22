/* input.txt
6
1 100 3 4 1000
*/

#include <iostream>

using namespace std;

int max(int a, int b) {
  return a - b > 0 ? a : b;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  scanf("%d", &n);
  if(n == 2) {
    cout << -1;
    return 0;
  }

  int* mosqLilies = new int[n + 1];
  mosqLilies[0] = -2001;
  scanf("%d", &mosqLilies[1]);
  mosqLilies[2] = -2001;

  int curMosq = 0;
  int prev1 = 0;
  int prev2 = 0;
  scanf("%d", &prev1);

  for(int i = 3; i <= n; i++) {
    scanf("%d", &curMosq);
    prev1 = mosqLilies[i - 2];
    prev2 = mosqLilies[i - 3];
    mosqLilies[i] = i - 2 == 2 ? prev2 + curMosq : i - 3 == 2 ? prev1 + curMosq : max(prev2 + curMosq, prev1 + curMosq);
  }
  cout << mosqLilies[n];
}
