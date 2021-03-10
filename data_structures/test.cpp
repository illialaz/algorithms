#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  int n = 500000;
  int k = (rand() % 3) + 1;
  int max = 1000000;
  printf("%d %d\n", n, k);
  for(int i = 0; i < n; i++) {
    printf("%d\n", (rand() % max) + 1);
  }
}