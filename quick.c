#include<stdio.h>

#include<stdlib.h>

#include<time.h>

int a[100], n, ct = 0;
void swap(int x, int y) {
  int i = a[x];
  a[x] = a[y];
  a[y] = i;
}

int part(int l, int h) {
  int t[h - l + 1], p = a[l], i = l + 1, j = h - 1;
  while (1) {
    for (; i < h && a[i] < p; i++, ct++);
    for (; j > l && a[j] >= p; j--, ct++);
    ct++;
    if (i < j)
      swap(i, j);
    else {
      swap(l, j);
      break;
    }
  }
  return j;
}

void quick(int l, int h) {
  if (l >= h)
    return;
  int p = part(l, h);
  quick(l, p - 1);
  quick(p + 1, h);
}

int main() {
  int i;
  srand(time(0));
  scanf("%d", & n);
  for (i = 0; i < n; i++) {
    a[i] = rand() % 100;
    printf("%d\t", a[i]);
  }
  printf("\n");
  quick(0, n - 1);
  for (i = 0; i < n; i++)
    printf("%d\t", a[i]);

  printf("\n%d\n", ct);
}
