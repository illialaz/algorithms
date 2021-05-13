/*folding.in
NEERCYESYESYESNEERCYESYESYES
*/
#include <iostream>
#include <string>

using namespace std;

const int N = 700;
string subs[N][N];

string compress(string str, int cur) {
  int half = str.length() / 2;
  for(int size = 1; size <= half; size++) {
    if(str.length() % size != 0) continue;

    string sub = str.substr(0, size);
    int len = size;
    int n = 1;
    while(len <= str.length() - size && sub == str.substr(len, size)) {
      len += size;
      n++;
    }

    if(n * size == str.length()) return to_string(n) + "(" + subs[cur][cur + size - 1] + ")";
  }
  return str;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("folding.in", "r", stdin);
  freopen("folding.out", "w", stdout);

  string str;
  cin >> str;
  int len = str.length();
  if(len < 4) {
    cout << str;
    return 0;
  }

  for(int i = 0; i < len; i++) {
    for(int j = i; j < i + 4; j++) {
      if(j < len) subs[i][j] = str.substr(i, j - i + 1);
    }
  }

  int minLen = 0;
  string minStr = "";
  string minStrComp = "";

  for(int i = 4; i < len; i++) {
    for(int j = 0; j < len - i; j++) {
      minLen = i + 1;
      minStr = str.substr(j, i + 1);
      for(int k = j; k < i + j; k++) {
        if(subs[j][k].length() + subs[k + 1][i + j].length() < minLen) {
          minLen = subs[j][k].length() + subs[k + 1][i + j].length();
          minStr = subs[j][k] + subs[k + 1][i + j];
        }
      }

      minStrComp = compress(str.substr(j, i + 1), j);

      subs[j][i+j] = minStr.length() > minStrComp.length() ? minStrComp : minStr;
    }
  }

  cout << subs[0][len - 1];
}
