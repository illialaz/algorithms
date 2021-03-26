/*input.txt
6 4
3 1 -4 2 8 -1000
1 2 6 6
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

priority_queue <int, vector <int>, less<int> > maxheap;
priority_queue <int, vector <int>, greater<int> > minheap;

int find() {
  int res = maxheap.top();
  maxheap.push(minheap.top());
  minheap.pop();
  return res;
}

void add(int elem) {
	if(elem < maxheap.top()) {
    minheap.push(maxheap.top());
    maxheap.pop();
    maxheap.push(elem);
  }
  else minheap.push(elem);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  maxheap.push(INT32_MAX);

  int n = 0;
  int m = 0;
  cin >> m >> n;
  int* toAdd = new int[m];
  int* toFind = new int[n];

  for(int i = 0; i < m; i++) {
    scanf("%d", &toAdd[i]);
  }

  for(int i = 0; i < n; i++) {
    scanf("%d", &toFind[i]);
  }


  int a = 0;
  int f = 0;
  for(int i = 0; i < n + m; i++) {
    if(a == toFind[f]) {
      if(f == n - 1) printf("%d",find());
      else printf("%d ",find());
      f++;
    }
    else {
      add(toAdd[a]);
      a++;
    }
  }
}
