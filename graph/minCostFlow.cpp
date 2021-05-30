/*standard input
4 6
1 2 1
1 3 1
1 4 1
2 3 1
2 4 1
3 4 1
*/
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAXN = 200001; // число вершин
const int INF = INT32_MAX;
 
struct edge {
	int a, cap;
	long long flow;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
	edge e1 = { b, cap, 0 };
	edge e2 = { a, 0, 0 };
	g[a].push_back ((long long) e.size());
	e.push_back (e1);
	g[b].push_back ((long long) e.size());
	e.push_back (e2);
}

bool bfs() {
	long long qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].a;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

long long dfs (int v, long long flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(long long)g[v].size(); ++ptr[v]) {
		long long id = g[v][ptr[v]],
			to = e[id].a;
		if (d[to] != d[v] + 1)  continue;
		long long pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

long long dinic() {
	long long flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (long long pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int main() {
  cin >> n;
  s = 0;
  t = n - 1;
  int m = 0;
  cin >> m;
  int u = 0;
  int v = 0;
  int w = 0;
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &w);
    u--;
    v--;
    add_edge(u, v, w);
  }
  cout << dinic();
}
