/* input.txt
5 5
1 2
3 4
1 3
3 5
1 5
*/
#include <iostream>
using namespace std;
const int capacity = 500000;
int parent[capacity];
int setSize[capacity];

int findSet(int x) {
  if(parent[x] == x) return x;
  parent[x] = findSet(parent[x]);
  return parent[x];
}

bool unionSets(int x, int y) {
  x = findSet(x);
  y = findSet(y);
  if(x == y) return 0;
  if(setSize[x] < setSize[y]) swap(x, y);
  parent[y] = x;
  setSize[x] += setSize[y];
  return 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  int q = 0;
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) {
    parent[i] = i;
    setSize[i] = 1;
  }

  int k = 0;
  int m = 0;
  for(int i = 0; i < q; i++) {
    scanf("%d %d", &k, &m);
    if(unionSets(k - 1, m - 1)) n--;
    printf("%d\n", n);
  }
  return 0;
}
