// input.txt 13

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  long long n = 0;
  cin >> n;
  int len = (int) log2(n) + 1;
  bool* res = new bool[len];
  int i = 0;

  while(n != 0) {
    res[i++] = n % 2;
    n /= 2;
  }

  for(int i = 0; i < len; i++) if(res[i]) printf("%d\n", i);
}
