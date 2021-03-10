#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

std::vector<int> simple;
std::vector<int> keys;
std::vector<int> numbers;

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

void findSimpleDeviders(int* a, int n) {
  int maxElem = a[0];
  for(int i = 1; i < n; i++) maxElem = max(maxElem, a[i]);

  int num = sqrt(maxElem);
  for(int i = 2; i <= num; i++) {
    int j = i - 1;
    bool isSimple = true;
    while(isSimple && j >= 2) {
      if(i % j == 0) {
        isSimple = false;
        break;
      }
      j--;
    }
    if(isSimple) {
      simple.push_back(0);
      keys.push_back(i);
      numbers.push_back(INT32_MAX);
    }
  }
}

int findMaxSubseqGCDNotOne(int* a, int n) {
  findSimpleDeviders(a, n);
  bool isChecked = false;
  for(int i = 0; i < n; i++) {
    int maxEl = 0;
    if(a[i] == 1) continue;
    for(int j = 0; j < simple.size(); j++) {
      if(a[i] % keys[j] == 0) {
        maxEl = max(maxEl, simple[j]);
        isChecked = true;
      }
    }
    if(!isChecked) {
      simple.push_back(1);
      keys.push_back(a[i]);
    }
    else {
      for(int j = 0; j < simple.size(); j++) {
        if(a[i] % keys[j] == 0) simple[j] = maxEl + 1;
      }
    }
  }

  int res = 0;
  for(int i = 0; i < simple.size(); i++) res = max(res, simple[i]);
  return res;
}

vector<int> findMaxNonDecrSubseq(int* a, int n) {
  int* prev = new int[n];

  int* pos = new int[n + 1];
  pos[0] = -1;

  int* cur = new int[n + 1];
  cur[0] = INT32_MIN;
  for(int i = 1; i <= n; i++) cur[i] = INT32_MAX;

  int j = 0;
  int length = 0;

  for(int i = 0; i < n; i++) {
    j = lowerBound(cur, n, a[i]);
    if(cur[j] == a[j]) j = upperBound(cur, n, a[i]);
    if(cur[j - 1] <= a[i] && a[i] < cur[j]) {
      cur[j] = a[i];
      pos[j] = i;
      prev[i] = pos[j - 1];
      length = max(length, j);
    }
  }

  vector<int> res;
  int p = pos[length];

  while(p != -1) {
    res.push_back(a[p]);
    p = prev[p];
  }
  reverse(res.begin(), res.end());
  return res;
}

int findMaxNonDecrSubseqGCDNotOne(int* a, int n) {
  vector<int> subseq = findMaxNonDecrSubseq(a, n);
  n = subseq.size();
  a = new int[n];
  for(int i = 0; i < n; i++) a[i] = subseq[i];
  return findMaxSubseqGCDNotOne(a, n);
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n = 0;
  int k = 0;
  cin >> n;
  cin >> k;

  int* arr = new int[n];
  for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
  // vector<int> res;
  int res = 0;
  vector<int> resVector;
  if(k == 1) {
    resVector = findMaxNonDecrSubseq(arr, n);
    printf("%lu\n", resVector.size());
  }
  if(k == 2) {
    res = findMaxSubseqGCDNotOne(arr, n);
    cout << res << "\n";
  }
  if(k == 3) {
    res = findMaxNonDecrSubseqGCDNotOne(arr, n);
    cout << res << "\n";
  }
}
