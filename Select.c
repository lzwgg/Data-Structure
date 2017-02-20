#include <stdio.h>

#define MaxSize 7

int main(void)
{
  int a[MaxSize] = {6,4,2,1,5,9,3};
  int i, j, tmp;
  for (i = 0; i < MaxSize; i++)
  {
    for (j = i + 1; j < MaxSize; j++)
    {
      if (a[j] < a[i])
      {
        tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
      }
    }
  }
  return 0;
}
