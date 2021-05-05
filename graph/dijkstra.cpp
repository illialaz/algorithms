#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > * edge;
long long MAX = INT64_MAX;
vector<long long> dijkstra;
vector<bool> isMin;
struct Road {
  double cost = 0;
  int num = 0;
};

struct Compare {
  bool operator()(Road const& p1, Road const& p2){
    return p2.cost < p1.cost;
  }
};

priority_queue<Road, vector<Road>, Compare> roads;

void init(int n) {
  edge = new vector<pair<int, int> >[n];
  dijkstra.resize(n, MAX);
  isMin.resize(n, false);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  int m = 0;
  int u = 0;
  int v = 0;
  int w = 0;
  scanf("%d %d", &n, &m);
  init(n);

  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &w);
    u--;
    v--;
    edge[u].push_back(make_pair(v, w));
    edge[v].push_back(make_pair(u, w));
  }

  Road road;
  int cur = 0;
  int len = 0;
  dijkstra[cur] = 0;
  road.cost = 0;
  road.num = 0;
  roads.push(road);

  while(roads.size()) {
    if(isMin[n - 1]) break;
    road = roads.top();
    roads.pop();
    cur = road.num;
    if(isMin[cur]) continue;
    isMin[cur] = true;

    len = edge[cur].size();
    for(int i = 0; i < len; i++) {
      int to = edge[cur][i].first;
      long long tmp = dijkstra[to];
      dijkstra[to] = min(dijkstra[to], dijkstra[cur] + edge[cur][i].second);
      road.cost = dijkstra[to];
      road.num = to;
      if(dijkstra[to] != tmp) roads.push(road);
    }
  }

  printf("%lld", dijkstra[n - 1]);
}
