/*input.txt
5 4
1 2
4 3
2 4
2 3
*/
#include <iostream>
#include <stack>

using namespace std;

const int MAX = 100000;
stack<int> arr[100000];

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
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    a--;
    arr[a].push(b);
    a++;
    b--;
    arr[b].push(a);
  }

  for(int i = 0; i < n; i++) {
    int k = arr[i].size();
    printf("%d ", k);
    for(int j = 0; j < k; j++) {
      printf("%d ", arr[i].top());
      arr[i].pop();
    }
    printf("\n");
  }
}
