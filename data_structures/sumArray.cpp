const int capacity = 300000;
int arr[capacity];
long long tree[4 * capacity];
#include <iostream>
#include <string.h>

using namespace std;

void createTree(int cur, int left, int right) {
  if(right - left == 1) {
    tree[cur] = arr[left];
  }
  else {
    int half = (left + right) / 2;
    createTree(2 * cur, left, half);
    createTree(2 * cur + 1, half, right);
    tree[cur] = tree[2 * cur] + tree[2 * cur + 1];
  }
}

void addElem(int pos, int elem, int cur, int left, int right) {
  if(right - left == 1) {
    tree[cur] += elem;
    return;
  }
  int half = (left + right) / 2;
  if(pos < half) {
    addElem(pos, elem, 2 * cur, left, half);
  }
  else addElem(pos, elem, 2 * cur + 1, half, right);
  tree[cur] = tree[2 * cur] + tree[2 * cur + 1];
}

long long findSumArr(int start, int end, int cur, int left, int right) {
  if(left == start && right == end) return tree[cur];
  int half = (left + right) / 2;
  if(end <= half) return findSumArr(start, end, 2 * cur, left, half);
  if(start >= half) return findSumArr(start, end, 2 * cur+ 1, half, right);
  return findSumArr(start, half, 2 * cur, left, half) +
  findSumArr(half, end, 2 * cur + 1, half, right);
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n;
  scanf("%d", &n);
  memset(&arr, 0, n);
  memset(&tree, 0, 4 * n);
  for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
  createTree(1, 0, n);

  int q;
  scanf("%d", &q);
  int a = 0;
  int b = 0;
  char findSum[] = "FindSum";
  char add[] = "Add";
  char type[10];
  for(int i = 0; i < q; i++) {
    scanf("%s %d %d", type, &a, &b);
    if(strcmp(type, findSum) == 0) {
      printf("%lld\n", findSumArr(a, b, 1, 0, n));
    }
    if(strcmp(type, add) == 0) {
      addElem(a, b, 1, 0, n);
    }
  }
}