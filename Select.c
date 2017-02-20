#include <stdio.h>

#define MaxSize 7

int main(void)
{
  int a[MaxSize] = {6,4,2,1,5,9,3};
  int i, j, k, tmp;
  for (i = 0; i < MaxSize; i++)
  {
    k = i;
    for (j = i + 1; j < MaxSize; j++)
    {
      if (a[j] < a[k])
        k = j;
    }
    if (k != i)
    {
        tmp = a[k];
        a[k] = a[i];
        a[i] = tmp;
    }
  }
  return 0;
}
