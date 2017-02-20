#include <stdio.h>

#define MaxSize 7

int main(void)
{
  int a[MaxSize] = {6,4,2,1,5,9,3};
  int i, j, tmp, sortedFlag;
  for (i = 0; i < MaxSize; i++)
  {
    sortedFlag = 0; // added to judge the array whether sorted or not before loop ends
    for (j = 0; j < MaxSize - 1; j++) // because we compare a[j+1] with a[j], so j < MaxSize - 1
    {
      if (a[j+1] < a[j])
      {
        tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
        sortedFlag = 1;
      }
    }
    if (!sortedFlag)  break;
  }
  return 0;
}
