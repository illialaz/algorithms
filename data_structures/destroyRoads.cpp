/* input.txt
4 5 3
2 3
3 4
4 1
3 1
4 2
1
5
3
*/
#include <iostream>
#include <string.h>
using namespace std;
const int capacity = 750000;
int parent[capacity];
int setSize[capacity];
pair<int, int> roads [capacity];
int requestsDestroy[capacity];
int res[capacity];
bool isChecked[capacity];

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
  int m = 0;
  int q = 0;

  scanf("%d %d %d", &n, &m, &q);
  memset(isChecked, false, m);

  for(int i = 0; i < n; i++) {
    parent[i] = i;
    setSize[i] = 1;
  }

  for(int i = 0; i < m; i++) {
    scanf("%d %d", &roads[i].first, &roads[i].second);
    roads[i].first--;
    roads[i].second--;
  }

  for(int i = 0; i < q; i++) {
    scanf("%d", &requestsDestroy[i]);
    requestsDestroy[i]--;
    isChecked[requestsDestroy[i]] = true;
  }

  for(int i = 0; i < m; i++) {
    if(!isChecked[i]) {
      if(unionSets(roads[i].first, roads[i].second)) n--;
    }
  }

  int req = 0;
  int i = q - 1;
  int num = q;
  while(n != 1 && i >= 0) {
    req = requestsDestroy[i];
    if(unionSets(roads[req].first, roads[req].second)) n--;
    num--;
    i--;
  }
  while(num != 0) {
    printf("%d", 1);
    q--;
    num--;
  }
  while(q != 0) {
    printf("%d", 0);
    q--;
  }
  return 0;
}
