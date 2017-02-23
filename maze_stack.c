
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define M 8
#define N 8

static int mg[M+2][N+2] = {
{1,1,1,1,1,1,1,1,1,1},
{1,0,0,1,0,0,0,1,0,1},
{1,0,0,1,0,0,0,1,0,1},
{1,0,0,0,0,1,1,0,0,1},
{1,0,1,1,1,0,0,0,0,1},
{1,0,0,0,1,0,0,0,0,1},
{1,0,1,0,0,0,1,0,0,1},
{1,0,1,1,1,0,1,1,0,1},
{1,1,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};

typedef struct
{
  int x, y, di;
}MGStack;

static int top = -1;

MGStack st[100];

int main(void)
{
  int xi, yi, di = 0, find;
  xi = yi = 1;
  top++;
  st[top].x = xi;
  st[top].y = yi;
  st[top].di = di;
  while (top > -1)
  {
	// get the stack top element
    xi = st[top].x;
    yi = st[top].y;
    di = st[top].di;
       
    if (xi == 8 && yi == 8)
    {
      // arrive
      printf("arrived\n");
      for (xi = 0; xi <= top; xi++)
      {
        printf("[%d,%d]\n", st[xi].x, st[xi].y);
      }
      return 0;
    }
	// find the element maybe useful
    find = 0;

    while (di < 3 && find == 0)
    {
      di++;      // search the next node
      switch(di)
      {
        case 0:
        xi = st[top].x + 1;
        yi = st[top].y;
        break;
        case 1:
        xi = st[top].x;
        yi = st[top].y + 1;
        break;
        case 2:
        xi = st[top].x - 1;
        yi = st[top].y; 
        break;       
        case 3:
        xi = st[top].x;
        yi = st[top].y - 1; 
        break;
      }
      if (!mg[xi][yi]) find = 1;
    }
    // check the node effectively
    if (find)
    {
      st[top].di = di;
      top++;
      st[top].x = xi;
      st[top].y = yi;
      st[top].di = -1;
      mg[xi][yi] = -1;
    }
    else
    {
      mg[st[top].x][st[top].y] = 0;
      top--;
    }
  }
  return 0;
}
