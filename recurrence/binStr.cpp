#include <iostream>

using namespace std;

pair<int, pair<int, int> > extendedEuclidianAlgorithm(long long a, long long b) {
  // a * x + b * y = gcd(a, b) (Find gcd(a,b), x and y which are r0, s0 and t0 after work of algorithm)
  long long s0 = 1;
  long long s1 = 0;
  long long t0 = 0;
  long long t1 = 1;
  long long r0 = a;
  long long r1 = b;
  long long q = 0;
  long long tmp = 0;
  while(r1 != 0) {
    q = r0 / r1;

    tmp = r1;
    r1 = r0 - q * r1;
    r0 = tmp;

    tmp = s1;
    s1 = s0 - q * s1;
    s0 = tmp;

    tmp = t1;
    t1 = t0 - q * t1;
    t0 = tmp;
  }

  pair<long long, pair<long long, long long> > res;
  res.first = r0;
  res.second.first = s0;
  res.second.second = t0;
  return res;
}

int main() {
  long long res = 1;
  long long n = 0;
  long long k = 0;
  cin >> n;
  cin >> k;
  long long r = n - k;
  long long mod = 1000000007;

  if(k == 0 || r == 0) {
    cout << res;
    return 0;
  }

  if(k < r) {
    r = k;
    k = n - k;
  }

  while(n != k) {
    res = ((res % mod) * (n % mod)) % mod;
    n--;
    if(r != 1) {
      pair<int, pair<int, int> > resF = extendedEuclidianAlgorithm(r, mod);
      long long rRev = resF.second.first;
      if(rRev < 0) rRev = (rRev + mod);
      
      res = ((res % mod) * (rRev % mod)) % mod;
      r--;
    }
  }
  cout << res;
  return 0;
}
