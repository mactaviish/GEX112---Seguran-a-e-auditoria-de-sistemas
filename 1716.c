#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

int _Phi(int);
int _InvMod(int, int);
void _EuclidExt(int, int);
ll _FastExp(ll, ll, ll);

int c, d, e, n, x, y;

int main(int argc, char ** argv) {
  scanf("%d %d %d", & n, & e, & c);
  d = _InvMod(e, _Phi(n));
  printf("%lld\n", _FastExp(c, d, n));

  return 0;
}

int _Phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0)
        n /= i;

      result -= result / i;
    }
  }
  
  if (n > 1)
    result -= result / n;

  return result;
}

int _InvMod(int a, int m) {
  _EuclidExt(a, m);
  return (x % m + m) % m;
}

void _EuclidExt(int a, int b) {
  if (!b) {
    x = 1;
    y = 0;
    d = a;

    return;
  }
  _EuclidExt(b, a % b);

  int x1 = y, y1 = x - (a / b) * y;
  x = x1, y = y1;
}

ll _FastExp(ll p, ll q, ll m) {
  ll r = 1;
  while (q) {
    if (q & 1)
      r = (r * p) % m;

    p = (p * p) % m;
    q >>= 1;
  }

  return r;
}