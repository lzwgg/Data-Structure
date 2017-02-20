#include <stdio.h>

#define MaxSize 7

int main(void)
{
  int a[MaxSize] = {6,4,2,1,5,9,3};
  int i, j, tmp;
  for (i = 0; i < MaxSize; i++)
  {
    for (j = 0; j < MaxSize - 1; j++) // because we campare a[j+1] with a[j], so j < MaxSize - 1
    {
      if (a[j+1] < a[j])
      {
        tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
      }
    }
  }
}
