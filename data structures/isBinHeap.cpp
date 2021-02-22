/* input.txt
10
9 17 16 25 21 20 60 25 40 33
*/
#include <iostream>

using namespace std;

string isBinHeap(int* heap, int n) {
  int cur = 0;
  while(cur != n) {
    if(2 * cur + 1 < n && heap[2 * cur + 1] < heap[cur]) return "No";
    if(2 * cur + 2 < n && heap[2 * cur + 2] < heap[cur]) return "No";
    cur += 1;
  }
  return "Yes";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  scanf("%d", &n);
  int* heap = new int[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &heap[i]);
  }
  cout << isBinHeap(heap, n);
}
