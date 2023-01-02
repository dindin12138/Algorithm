#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, k, q[N];

int quick_select(int l, int r, int k) {
  if (l >= r)
    return q[l];
  int mid = q[(l + r) >> 1], i = l - 1, j = r + 1;
  while (i < j) {
    while (q[++i] < mid)
      ;
    while (q[--j] > mid)
      ;
    if (i < j)
      swap(q[i], q[j]);
  }
  int sl = j - l + 1;
  if (k <= sl)
    return quick_select(l, j, k);
  else
    return quick_select(j + 1, r, k - sl);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &q[i]);
  printf("%d", quick_select(0, n - 1, k));
  return 0;
}