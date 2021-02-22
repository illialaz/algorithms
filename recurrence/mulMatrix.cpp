/* input.txt
4
20 5
5 35
35 4
4 25
*/

#include <iostream>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int s = 0;
  scanf("%d", &s);

  pair<int, int> * matricesSize = new pair<int, int>[s];

  for(int i = 0; i < s; i++) {
    scanf("%d %d", &matricesSize[i].first, &matricesSize[i].second);
  }

  int** resMatrix = new int*[s];
  for(int i = 0; i < s; i++) {
    resMatrix[i] = new int[s];
    resMatrix[i][i] = 0;
  }

  for(int l = 1; l < s; l++) {
    for(int i = 0; i < s - l; i++) {
      int j = i + l;
      resMatrix[i][j] = INT32_MAX;
      int mulRes = 0;
      for(int k = i; k < j; k++) {
        mulRes = resMatrix[i][k] + resMatrix[k + 1][j] + matricesSize[i].first * matricesSize[k].second * matricesSize[j].second;
        if(mulRes < resMatrix[i][j]) resMatrix[i][j] = mulRes;
      }
    }
  }

  cout << resMatrix[0][s - 1];
}
