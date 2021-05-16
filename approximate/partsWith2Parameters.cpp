/*input.txt
7 3
10 6
1 15
10 10
5 15
14 8
6 7
4 12
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Part {
  long long deliveryTime;
  long long processTime;
};

bool Compare(pair<Part, int> tmp1, pair<Part, int> tmp2) {
  Part a = tmp1.first;
  Part b = tmp2.first;
  if(a.deliveryTime + a.processTime == b.deliveryTime + b.processTime) {
    if(a.deliveryTime == b.deliveryTime) return a.processTime > b.processTime;
    if(a.processTime == b.processTime) return a.deliveryTime > b.deliveryTime;
    return a.deliveryTime > b.deliveryTime;
  }
  return a.deliveryTime + a.processTime > b.deliveryTime + b.processTime;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  int m = 0;
  cin >> n >> m;

  priority_queue<pair<long long, int> > proc;
  for(int i = 0; i < m; i++) proc.push(make_pair(0, -i));

  vector<pair<Part, int> > parts;
  parts.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> parts[i].first.deliveryTime >> parts[i].first.processTime;
    parts[i].second = i;
  }

  sort(parts.begin(), parts.end(), Compare);

  pair<long long, int> cur;
  int* whichProc = new int[n];
  long long max = 0;
  for(int i = 0; i < n; i++) {
    cur = proc.top();
    proc.pop();
    whichProc[parts[i].second] = -cur.second + 1;
    if(-parts[i].first.deliveryTime < cur.first) cur.first = -parts[i].first.deliveryTime;
    cur.first -= parts[i].first.processTime;
    proc.push(cur);
    if(max > cur.first) max = cur.first;
  }

  max = -max;
  cout << max << "\n";
  for(int i = 0; i < n - 1; i++) {
    cout << parts[i].second + 1 << " " << whichProc[parts[i].second] << "\n";
  }
  cout << parts[n - 1].second + 1 << " " << whichProc[parts[n - 1].second];
}
