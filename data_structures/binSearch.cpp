/* standard input
1
1
3
0 1 2
*/

#include <iostream>
#include <algorithm>

using namespace std;

int lowerBound(int* arr, int len, int elem) {
  int l = 0;
  int r = len;
  int k = 0;
  while(l < r) {
    k = (l + r) / 2;
    elem <= arr[k] ? r = k : l = k + 1;
  }
  return l;
}

int upperBound(int* arr, int len, int elem) {
  int l = 0;
  int r = len;
  int k = 0;
  while(l < r) {
    k = (l + r) / 2;
    elem < arr[k] ? r = k : l = k + 1;
  }
  return l;
}

bool binSearch(int* arr, int len, int elem) {
  int l = 0;
  int r = len;
  int k = 0;
  while(l < r) {
    k = (l + r) / 2;
    if(elem == arr[k]) return true;
    elem < arr[k] ? r = k : l = k + 1;
  }
  return false;
}

int main() {
  int n = 0;
  cin >> n;
  int* arr = new int[n];
  for(int i = 0; i < n; i++) cin >> arr[i];

  int k = 0;
  cin >> k;
  int elem;
  for(int i = 0; i < k; i++) {
    cin >> elem;
    cout << binSearch(arr, n, elem) << " " << lowerBound(arr, n, elem) << " " << upperBound(arr, n, elem) << "\n";
  }
}
