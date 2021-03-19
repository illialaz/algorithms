/* input.txt examples
8 1
1 4 2 5 5 6 1 2

10 2
15 14 7 7 2 6 18 24 49 56

13 2
1 2 4 8 3 9 8 7 7 7 7 21 126

10 3
15 14 7 7 2 6 18 24 3 1

12 3
15 14 7 7 2 6 18 24 3 1 21 63

create test input:
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  int n;
  cin >> n;
  int k = (rand() % 3) + 1;
  int max = 1000000;
  printf("%d %d\n", n, k);
  for(int i = 0; i < n; i++) {
    printf("%d\n", (rand() % max) + 1);
  }
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <string.h>
#include <ctime>

using namespace std;

struct Node {
  int elem;
  int l;
  int r;
  Node* left;
  Node* right;
  Node(int a, int b, int c) {
    elem = a;
    l = b;
    r = c;
    left = nullptr;
    right = nullptr;
  }
};

const int str = 500000;
int arr[str];
int lenSubseq[2 * str + 1];
Node* lenSubseq2[2 * str + 1];
int n;
int maxEl;

int lowerBound(int* a, int elem) {
  int l = 0;
  int r = n;
  int k = 0;
  while(l < r) {
    k = (l + r) / 2;
    elem <= a[k] ? r = k : l = k + 1;
  }
  return l;
}

vector<int> simpleDev(int a) {
  vector<int> res;
  for(int i = 2; i <= sqrt(a); i++) {
    if(a % i == 0) {
      res.push_back(i);
      while(a % i == 0) {
        a /= i;
      }
    }
  }
  if(a != 1) res.push_back(a);
  return res;
}

int maxLen(Node* & a, int num, int l, int r) {
  if(r - l == 1) {
    if(a == nullptr) a = new Node(0, l, r);
    return a->elem;
  }
  if(a == nullptr) a = new Node(0, l, r);
  int res = 0;
  int half = (l + r) / 2;
  int tmp;
  if(num >= half) {
    l = half;
    res = maxLen(a->right, num, l, r);
    if(a->left != nullptr) res = res > a->left->elem ? res : a->left->elem;
  }
  else {
    r = half;
    res = maxLen(a->left, num, l, r);
  }
  return res;
}

void push(Node* & a, int num, int size, int l, int r) {
  if(r - l == 1) {
    a->elem = size;
    return;
  }
  int half = (l + r) / 2;
  if(num >= half) {
    l = half;
    push(a->right, num, size, l, r);
    a->elem = a->elem > a->right->elem ? a->elem : a->right->elem;
  }
  else {
    r = half;
    push(a->left, num, size, l, r);
    a->elem = a->elem > a->left ->elem ? a->elem : a->left->elem;
  }
}

bool compare(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

vector<int> findMaxNonDecrSubseq() {
  int* prev = new int[n];

  int* pos = new int[n + 1];
  pos[0] = -1;

  int* cur = new int[n + 1];
  cur[0] = INT32_MIN;
  for(int i = 1; i <= n; i++) cur[i] = INT32_MAX;

  int j = 0;
  int length = 0;

  for(int i = 0; i < n; i++) {
    j = lowerBound(cur, arr[i]);
    if(cur[j] == arr[i]) j = lowerBound(cur, arr[i] + 1);
    if(cur[j - 1] <= arr[i] && arr[i] < cur[j]) {
      cur[j] = arr[i];
      pos[j] = i;
      prev[i] = pos[j - 1];
      length = max(length, j);
    }
  }

  vector<int> res;
  int p = pos[length];

  while(p != -1) {
    res.push_back(arr[p]);
    p = prev[p];
  }
  reverse(res.begin(), res.end());
  return res;
}

int findMaxSubseqGCDNotOne() {
  vector<int> simple;
  int max = 0;
  int res = 0;

  for(int i = 0; i < n; i++) {
    simple = simpleDev(arr[i]);
    for(int i = 0; i < simple.size(); i++) max = max > lenSubseq[simple[i]] ? max : lenSubseq[simple[i]];
    max += 1;
    for(int i = 0; i < simple.size(); i++) lenSubseq[simple[i]] = max;
    res = res > max ? res : max;
    max = 0;
  }
  return res;
}

int findMaxNonDecrSubseqGCDNotOne() {
  vector<int> simple;
  int max = 0;
  int res = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i] == 1) continue;
    max = 0;
    simple = simpleDev(arr[i]);
    for(int j = 0; j < simple.size(); j++) {
      int tmp = maxLen(lenSubseq2[simple[j]], arr[i], 0, maxEl + 1);
      max = max > tmp ? max : tmp;
    }
    max += 1;
    for(int j = 0; j < simple.size(); j++) {
      push(lenSubseq2[simple[j]], arr[i], max, 0, maxEl + 1);
    }
    res = res > max ? res : max;
  }
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int k = 0;
  cin >> n;
  cin >> k;

  maxEl = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    maxEl = maxEl > arr[i] ? maxEl : arr[i];
  }
  int res = 0;
  vector<int> resVector;
  if(k == 1) {
    resVector = findMaxNonDecrSubseq();
    printf("%lu\n", resVector.size());
  }
  if(k == 2) {
    res = findMaxSubseqGCDNotOne();
    cout << res << "\n";
  }
  if(k == 3) {
    res = findMaxNonDecrSubseqGCDNotOne();
    cout << res << "\n";
  }
  return 0;
}
