/*input.txt
6
3 2
5 4
3 1
3 5
5 6
*/
#include <iostream>

using namespace std;

const int MAX = 100000;
int arr[100000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) arr[i] = 0;

  int a = 0;
  int b = 0;
  for(int i = 0; i < n - 1; i++) {
    scanf("%d %d", &a, &b);
    b--;
    arr[b] = a;
  }

  for(int i = 0; i < n - 1; i++) printf("%d ", arr[i]);
  printf("%d\n", arr[n - 1]);
}