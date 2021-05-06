/* input.txt
5
5
1 5 1 10
1 3 1 10
1 4 0 30
1 2 0 1000
4 3 0 10
5 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

const int N = 1000;
const int M = 1000000;
double MAX = INT64_MAX;
double dejkstra[N][2];
bool isMinRoad[N];
bool isMinRails[N];
double graphHighWays[N][N];
double graphRailRoads[N][N];
vector<int> edge[N];
vector<int> edge2[N];

struct Road {
  double cost = 0;
  bool type = 0;
  int num = 0;
};

struct Compare {
  bool operator()(Road const& p1, Road const& p2){
    return p2.cost < p1.cost;
  }
};

priority_queue<Road, vector<Road>, Compare> roads;

void init(int n) {
  for(int i = 0; i < n; i++) {
    isMinRoad[i] = false;
    isMinRails[i] = false;
    dejkstra[i][0] = MAX;
    dejkstra[i][1] = MAX;
    for(int j = 0; j < n; j++) {
      graphHighWays[i][j] = 0;
      graphRailRoads[i][j] = 0;
    }
  }
}

void dejkstraAlgo(int n, int start, int finish) {
  int minEl;
  double minRoad = 0;
  double mulStart = 1.1;
  double mulRoad = 1;
  bool isFirst = true;
  double tmp;
  int len;
  Road road;
  bool type;
  bool isMin = false;

  len = edge[start].size();

  for(int k = 0; k < len; k++) {
    int i = edge[start][k];
    dejkstra[i][0] = graphHighWays[start][i] * mulStart;
    road.cost = dejkstra[i][0];
    road.type = 0;
    road.num = i;
    roads.push(road);
  }

  len = edge2[start].size();

  for(int k = 0; k < len; k++) {
    int i = edge2[start][k];
    dejkstra[i][1] = graphRailRoads[start][i] * mulStart;
    road.cost = dejkstra[i][1];
    road.type = 1;
    road.num = i;
    roads.push(road);
  }

  while(roads.size() > 0) {
    minEl = start;
    minRoad = MAX;

    road = roads.top();
    roads.pop();
    if(road.type == 1 && isMinRails[road.num]) continue;
    if(road.type == 0 && isMinRoad[road.num]) continue;

    minRoad = road.cost;
    minEl = road.num;
    if(road.type == 1) isMinRails[minEl] = true;
    else isMinRoad[minEl] = true;

    if(isMinRoad[finish] && isMinRails[finish]) break;

    type = road.type;

    if(minRoad >= MAX) break;

    len = edge[minEl].size();

    if(type == 0) mulRoad = 1;
    else mulRoad = 1.1;

    for(int k = 0; k < len; k++) {
      int i = edge[minEl][k];
      if(!isMinRoad[i]) {
        tmp = dejkstra[i][0];
        dejkstra[i][0] = min(dejkstra[i][0], minRoad + graphHighWays[minEl][i] * mulRoad);
        if(tmp != dejkstra[i][0]) {
          road.cost = dejkstra[i][0];
          road.type = 0;
          road.num = i;
          roads.push(road);
        }
      }
    }

    len = edge2[minEl].size();

    if(type == 0) mulRoad = 1.1;
    else mulRoad = 1;

    for(int k = 0; k < len; k++) {
      int i = edge2[minEl][k];
      if(!isMinRails[i]) {
        tmp = dejkstra[i][1];
        dejkstra[i][1] = min(dejkstra[i][1], minRoad + graphRailRoads[minEl][i] * mulRoad);
        if(tmp != dejkstra[i][1]) {
          road.cost = dejkstra[i][1];
          road.type = 1;
          road.num = i;
          roads.push(road);
        }
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  int m = 0;
  scanf("%d\n%d", &n, &m);
  init(n);
  int x = 0;
  int y = 0;
  int t = 0;
  double p = 0;
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d %lf", &x, &y, &t, &p);
    x -= 1;
    y -= 1;
    if(t == 0) {
      if(graphHighWays[x][y] == 0 || graphHighWays[x][y] > p) {
        if(graphHighWays[x][y] == 0) {
          edge[x].push_back(y);
          edge[y].push_back(x);
        }
        graphHighWays[x][y] = p;
        graphHighWays[y][x] = p;
      }
    }
    if(t == 1) {
      if(graphRailRoads[x][y] == 0 || graphRailRoads[x][y] > p) {
        if(graphRailRoads[x][y] == 0) {
          edge2[x].push_back(y);
          edge2[y].push_back(x);
        }
        graphRailRoads[x][y] = p;
        graphRailRoads[y][x] = p;
      }
    }
  }

  int start = 0;
  int finish = 0;
  scanf("%d %d", &start, &finish);
  start -= 1;
  finish -= 1;
  dejkstraAlgo(n, start, finish);
  if(min(dejkstra[finish][0], dejkstra[finish][1]) >= MAX) {
    printf("No");
    return 0;
  }
  printf("Yes\n%.2lf", min(dejkstra[finish][0], dejkstra[finish][1]));
}
