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

const long long MAXN = 200001; // число вершин
const long long INF = INT64_MAX;
 
struct edge {
	long long a, b, cap, flow;
};
 
long long n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<long long> g[MAXN];

void add_edge (long long a, long long b, long long cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
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
		long long v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			long long id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

long long dfs (long long v, long long flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(long long)g[v].size(); ++ptr[v]) {
		long long id = g[v][ptr[v]],
			to = e[id].b;
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
  long long m = 0;
  cin >> m;
  long long u = 0;
  long long v = 0;
  long long w = 0;
  for(long long i = 0; i < m; i++) {
    scanf("%llu %llu %llu", &u, &v, &w);
    u--;
    v--;
    add_edge(u, v, w);
  }
  cout << dinic();
}
