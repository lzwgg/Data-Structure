
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
  int x, y, pre;
}MGQuene, MGStack;

static int top = -1;
static int front = -1, rear = -1;

MGStack st[100];
MGQuene qu[100];

int main(void)
{
  int xi, yi, index = -1;
  xi = yi = 1;
  rear++;
  qu[rear].x = xi;
  qu[rear].y = yi;
  qu[rear].pre = front;
  while (front <= rear)
  {
    front++;
	// get the stack top element
    xi = qu[front].x;
    yi = qu[front].y;
       
    if (xi == 8 && yi == 8)
    {
      // arrive
      printf("arrived\n");
      while (qu[front].pre != -1)
      {
        top++;
        st[top].x = qu[front].x;
        st[top].y = qu[front].y;
        front = qu[front].pre;
      }
        top++;
        st[top].x = qu[front].x;
        st[top].y = qu[front].y;
        while (top > -1)
        {
            printf("[%d,%d]\n", st[top].x, st[top].y);
            top--;
        }
      return 0;
    }
    index = -1;
    while (index < 3)
    {
      index++;      // search the next node
      switch(index)
      {
        case 0:
        xi = qu[front].x + 1;
        yi = qu[front].y;
        break;
        case 1:
        xi = qu[front].x;
        yi = qu[front].y + 1;
        break;
        case 2:
        xi = qu[front].x - 1;
        yi = qu[front].y; 
        break;       
        case 3:
        xi = qu[front].x;
        yi = qu[front].y - 1; 
        break;
      }
      if (!mg[xi][yi])
      {
	  rear++;
	  qu[rear].x = xi;
	  qu[rear].y = yi;
	  qu[rear].pre = front;
	  mg[xi][yi] = -1;
      }
    }
  }
  return 0;
}
