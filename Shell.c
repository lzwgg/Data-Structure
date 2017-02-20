#include <stdio.h>

#define MaxSize 7

int main(void)
{
  int a[MaxSize] = {6,4,2,1,5,9,3};
  int i, j, tmp, gap;
  gap = MaxSize / 2;
  while (gap > 0)
  {
    for (i = gap; i < MaxSize; i++)
    {
      tmp = a[i];
      j = i - gap;
      while (j >= 0 && tmp < a[j])
      {
        a[j+gap] = a[j];
        j -= gap;
      }
      a[j+gap] = tmp;
    }
    gap /= 2;
  }
  return 0;
}
