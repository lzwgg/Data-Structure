#include <stdio.h>

#define MaxSize 7

int main(void)
{
  int a[MaxSize] = {6,4,2,1,5,9,3};
  int i, j, tmp;
  for (i = 1; i < MaxSize; i++)
  {
    tmp = a[i];
    j = i - 1;
    for (j >= 0 && a[j] > tmp)
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = tmp;
  }
  return 0;
}
