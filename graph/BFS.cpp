/*input.txt
7
0 1 1 0 0 0 0
0 0 0 0 1 0 0
0 1 0 1 1 0 0
0 1 0 0 1 0 0
0 0 0 0 0 1 0
0 0 0 1 0 0 0
0 0 0 0 0 1 0
*/
#include <iostream>
#include <deque>

using namespace std;

const int MAX = 100;
int mark[MAX];
bool graph[MAX][MAX];
int ind = 1;

void bfs(int n, int start) {
  deque<int> q;
  mark[start] = ind;
  q.push_back(start);
  ind += 1;
  int cur = 0;
  while(!q.empty()) {
    cur = q.front();
    q.pop_front();
    for(int i = 0; i < n; i++) {
      if(graph[cur][i] == 1 && mark[i] == -1) {
        mark[i] = ind;
        q.push_back(i);
        ind++;
      }
    }
  }
}

int findStart(int n) {
  for(int i = 0; i < n; i++) {
    if(mark[i] == -1) return i;
  }
  return n;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) mark[i] = -1;
  int a = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &a);
      graph[i][j] = a;
    }
  }

  int start = findStart(n);
  while(start != n) {
    bfs(n, start);
    start = findStart(n);
  }
  for(int i = 0; i < n; i++) printf("%d ", mark[i]);
  return 0;
}
