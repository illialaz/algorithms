/*input.txt
10 1 9
11
21
35
4
32
5
6
70
100
*/
#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 100000;
int hashtable[MAX];

void init(int m) {
  for(int i = 0; i < m; i++) hashtable[i] = -1;
}

int hashFunc(int x, int c, int m, int i) {
  return ((x % m) + c * i) % m;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int m = 0;
  int c = 0;
  int n = 0;
  scanf("%d %d %d", &m, &c, &n);

  init(m);

  int num = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &num);
    int j = 0;
    bool paste = false;
    while(!paste) {
      int el = hashFunc(num, c, m, j);
      if(hashtable[el] == num) paste = true;
      else if(hashtable[el] != -1) j++;
      else {
        hashtable[el] = num;
        paste = true;
      }
    }
  }

  for(int i = 0; i < m; i++) printf("%d ", hashtable[i]);
}