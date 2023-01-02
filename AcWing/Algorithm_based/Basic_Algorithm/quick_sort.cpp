#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, q[N];

void quick_sort(int q[], int l, int r) {
  if (l >= r)
    return;
  int mid = q[(l + r) >> 1], i = l - 1, j = r + 1;
  while (i < j) {
    while (q[++i] < mid)
      ;
    while (q[--j] > mid)
      ;
    if (i < j)
      swap(q[i], q[j]);
  }
  quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &q[i]);
  quick_sort(q, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d ", q[i]);
  return 0;
}
