/* input.txt
4
t -7 t 4 x 2 x 5
*/
#include <iostream>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

const int MAX = 500;
long long res[MAX];
bool operation[2 * MAX];
long long poligon[2 * MAX];
long long temp[MAX][2 * MAX];
long long temp2[MAX][2 * MAX];

long long findOptimal(int n) {
  for(int i = 0; i < 2 * n; i++) {
    temp[0][i] = poligon[i];
    temp2[0][i] = poligon[i];
    }

  long long a = 0;
  long long b = 0;
  long long c = 0;
  long long d = 0;
  long long maxEl = 0;
  long long minEl = 0;
  bool oper = 1;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < 2 * n - 1 - i; j++) {
      temp[i][j] = INT64_MIN;
      temp2[i][j] = INT64_MAX;
      if(j >= n) {
          temp[i][j] = temp[i][j % n];
          temp2[i][j] = temp2[i][j % n];
          continue;
      }
      for(int k = 0; k < i; k++) {
        a = temp[i - k - 1][j];
        b = temp[k][j + i - k];
        c = temp2[i - k - 1][j];
        d = temp2[k][j + i - k];
        oper = operation[j + i - k];
        if(oper) {
          maxEl = max(max(a + b, a + d), max(c + d, c + b));
          minEl = min(min(a + b, a + d), min(c + d, c + b));
        }
        else {
          maxEl = max(max(a * b, a * d), max(c * d, c * b));
          minEl = min(min(a * b, a * d), min(c * d, c * b));
        }
        temp[i][j] = temp[i][j] > maxEl ? temp[i][j] : maxEl;
        temp2[i][j] = temp2[i][j] < minEl ? temp2[i][j] : minEl;
      }
    }
  }

  long long max = temp[n - 1][0];
  for(int j = 1; j < n; j++) {
    if(max < temp[n - 1][j]) max = temp[n - 1][j];
  }
  printf("%lld\n", max);
  string resStr = "";
  for(int j = 0; j < n; j++) {
    if(max == temp[n - 1][j]) {
      resStr = resStr + to_string(j + 1) + " ";
    }
  }
  resStr = resStr.substr(0, resStr.length() - 1);
  cout << resStr;
  return max;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  scanf("%d\n", &n);
  long long num = 0;
  char oper = 't';
  for(int i = 0; i < n; i++) {
    if(i != n - 1) scanf("%c %llu ", &oper, &num);
    else scanf("%c %llu", &oper, &num);
    poligon[i] = poligon[n + i] = num;
    operation[i] = operation[n + i] = oper == 't' ? 1 : 0;
  }

  findOptimal(n);
  return 0;
}