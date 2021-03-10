/*
huffman.in
6
1 1 2 2 5 8
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("huffman.in", "r", stdin);
  freopen("huffman.out", "w", stdout);

  priority_queue<long long, vector<long long>, greater<long long> > haff;
  int n = 0;
  scanf("%d", &n);
  int elem = 0;

  for(int i = 0; i < n; i++) {
    scanf("%d", &elem);
    haff.push(elem);
  }

  long long res = 0;
  long long a = 0;
  long long b = 0;
  long long c = 0;

  while(haff.size() > 1) {
    a = haff.top();
    haff.pop();
    b = haff.top();
    haff.pop();
    c = a + b;
    res += c;
    haff.push(c);
  }

  printf("%llu", res);
  return 0;
}
