#include <iostream>
#include <string>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  string str;
  cin >> str;
  int n = str.length();

  int** resLen = new int*[n]; // resLen[i][j] - length of max palindrom from string[i] to string[j]
  for(int i = 0; i < n; i++) {
    resLen[i] = new int[n];
    for(int j = 0; j < i; j++) {
      resLen[i][j] = 0;
    }
    resLen[i][i] = 1;
  }

  for(int j = 1; j < n; j++) {
    for(int i = j - 1; i >= 0; i--) {
      resLen[i][j] = str[i] == str[j] ? resLen[i + 1][j - 1] + 2 : max(resLen[i + 1][j], resLen[i][j - 1]);
    }
  }

  int len = resLen[0][n - 1];
  char resStr [len];
  int a = 0;
  int b = n - 1;
  int half = len / 2 + len % 2;
  int cur = 0;
  while(cur != half) {
    if(a != b && resLen[a][b] == resLen[a + 1][b]) a += 1;
    else if(a != b && resLen[a][b] == resLen[a][b - 1]) b -= 1;
    else {
      resStr[cur] = resStr[len - cur - 1] = str[a];
      a += 1;
      b -= 1;
      cur++;
    }
  }

  cout << resLen[0][n - 1] << "\n";
  for(int i = 0; i < len; i++) cout << resStr[i];
}
