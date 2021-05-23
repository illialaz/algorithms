/*input.txt
6
1 6 5
2 6 5
6 5 3
4 5 4
3 5 6
4
1 2
1 4
4 6
1 3
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstdio>

using namespace std;

const int N = 50001;
const int M = 50001;
const int LOG = 17;
int maxEdge[N][LOG];
int prevPow[N][LOG];
struct Road {
  int num = 0;
  int price = INT32_MIN;
};
vector<Road> adj[N];
int roadsDepth[N];
bool visited[N];

void dfs(Road road) {
  int u = 0;
  int prevNum = -1;
  stack<Road> cur;
  stack<int> curDepth;
  stack<int> prev;
  int depth = 0;
  cur.push(road);
  curDepth.push(depth);
  prev.push(prevNum);
  while(!cur.empty()) {
    road = cur.top();
    depth = curDepth.top();
    prevNum = prev.top();
    cur.pop();
    curDepth.pop();
    prev.pop();

    u = road.num;
    roadsDepth[u] = depth;
    visited[u] = true;
    maxEdge[u][0] = road.price;
    prevPow[u][0] = prevNum;

    int n = adj[u].size();
    for(int v = 0; v < n; v++) {
      if(!visited[adj[u][v].num]) {
        cur.push(adj[u][v]);
        curDepth.push(depth + 1);
        prev.push(u);
      }
    }
  }
}

void findAllMax(int k, int n) {
  int pow2 = pow(2, k - 1);
  for(int i = 1; i <= n; i++) {
    if(roadsDepth[i] >= pow2) {
      maxEdge[i][k] = max(maxEdge[i][k - 1], maxEdge[prevPow[i][k - 1]][k - 1]);
      prevPow[i][k] = prevPow[prevPow[i][k - 1]][k - 1];
    }
  }
  if(k <= (int)log2(n)) findAllMax(k + 1, n);
}

int findMax(int u, int v) {
  if(u == v) return 0;
  int h1 = roadsDepth[u];
  int h2 = roadsDepth[v];
  int maxRoad = INT32_MIN;
  int diff = 0;
  int tmp = 0;
  int jump = 0;
  if(h1 < h2) {
    diff = h2 - h1;
    tmp = v;
  }
  if(h2 < h1) {
    diff = h1 - h2;
    tmp = u;
  }
  while(diff != 0) {
    jump = pow(2, (int)log2(diff));
    diff -= jump;
    jump = log2(jump);
    maxRoad = max(maxRoad, maxEdge[tmp][jump]);
    tmp = prevPow[tmp][jump];
  }
  if(h1 < h2) v = tmp;
  if(h2 < h1) u = tmp;

  if(u == v) return maxRoad;

  int height = min(h1, h2);
  jump = log2(height);
  while(prevPow[u][0] != prevPow[v][0]) {
    if(prevPow[u][jump] != prevPow[v][jump]) {
      maxRoad = max(maxRoad, max(maxEdge[u][jump], maxEdge[v][jump]));
      u = prevPow[u][jump];
      v = prevPow[v][jump];
    }
    jump--;
  }
  return max(maxRoad, max(maxEdge[u][0], maxEdge[v][0]));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  int m = 0;
  cin >> n;
  int u = 0;
  int v = 0;
  int w = 0;
  Road road;
  for(int i = 1; i < n; i++) {
    cin >> u >> v >> w;
    road.price = w;
    road.num = v;
    adj[u].push_back(road);
    road.num = u;
    adj[v].push_back(road);
  }

  dfs(road);
  findAllMax(1, n);

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    cout << findMax(u, v) << "\n";
  }
}
