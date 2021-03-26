/*input.txt
6
0 0 0 0 0 0
0 0 0 0 0 0
1 1 0 0 1 0
0 0 0 0 0 0
0 0 0 1 0 1
0 0 0 0 0 0
*/
#include <iostream>

using namespace std;

const int MAX = 100;
int arr[MAX];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) arr[i] = 0;

  int a = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &a);
      if(a == 1) arr[j] = i + 1;
    }
  }

  for(int i = 0; i < n - 1; i++) printf("%d ", arr[i]);
  printf("%d\n", arr[n - 1]);
}