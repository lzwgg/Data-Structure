#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*  the matrix is
 *
 *  1 0 0 2
 *  0 0 3 0
 *  0 0 0 4
 *
 */

typedef struct mxtn
{
  int i, j; // the index of matrix
  struct mxtn * down, *right; // for the head node of row and column
  union
  {
    struct mxtn *next;  // for the head node
    int val; // for the element
  }tag;
}CrossList;


typedef struct
{
  int i, j, data;
}TriElement;

TriElement mx[12];
static   int top = -1;

int A[] = {1,2,3,4};
int iA[] = {0, 2, 3, 4};
int jA[] = {0, 3, 2, 3};

void create_maxtrix (void)
{
  int i, j;
  int size = sizeof(A) / sizeof(int);
  if (!size)  return;
  size = sizeof(iA) / sizeof(int);
  for (i = 1; i < size; i++)
  {
    for (j = iA[i - 1]; j < iA[i]; j++)
    {
      top++;
      mx[top].i = i - 1;
      mx[top].j = jA[j];
      mx[top].data = A[j];
    }
  }
}

int main(void)
{
  int i, j, first;
  CrossList *temp, *row[3], *column[4], *p, *q;
  create_maxtrix();
  // create the head nodes
  for (i = 0; i < 3; i++)
  {
    temp = (CrossList *) malloc(sizeof(CrossList));
    temp->down = NULL;
    temp->right = NULL;
    temp->tag.next = NULL;
    row[i] = temp;
    if (i > 0)
    {
      row[i-1]->down = temp;
    }
  }
  for (j = 0; j < 4; j++)
  {
    temp = (CrossList *) malloc(sizeof(CrossList));
    temp->down = NULL;
    temp->right = NULL;
    temp->tag.next = NULL;
    column[j] = temp;
    if (j > 0)
    {
      column[j-1]->right = temp;
    }
  }
  while (top > -1)
  {
    // get the stack top element
    temp = (CrossList *) malloc(sizeof(CrossList));
    temp->i = mx[top].i;
    temp->j = mx[top].j;
    temp->tag.val = mx[top].data;
    temp->down = NULL;
    temp->right = NULL;
    //temp->tag.next = NULL;
    // find a place to store the element
    // for the row
    p = row[temp->i];
    if (p->tag.next == NULL)
    {
      p->tag.next = temp;
    }
    else
    {
      q = p;
      p = p->tag.next;
      first = 1;
      do {
        while (temp->j > p->j)
        {
          first = 0;
          q = p;
          if (p->right != NULL)
          {
            p = p->right;
          }
          else
            break;
        }
        if (first)
        {
            temp->right = q->tag.next;
            q->tag.next = temp;
        }
        else
        {
            temp->right = q->right;
            q->right = temp;
        }
      }while (0);
    }
    #if 1
    // for the column
    p = column[temp->j];
    if (p->tag.next == NULL)
    {
      p->tag.next = temp;
    }
    else
    {
      q = p;
      p = p->tag.next;
      first = 1;
      do {
        while (temp->i > p->i)
        {
          q = p;
          if (p->down != NULL)
          {
            p = p->down;
          }
          else
            break;
        }
        if (first)
        {
            temp->down = q->tag.next;
            q->tag.next = temp;
        }
        else
        {
            temp->down = q->down;
            q->down = temp;
        }
      }while (0);
    }
    #endif // 0
    top--;
  }
  printf("row!\n");
  for (i = 0; i < 3; i++)
  {
    p = row[i]->tag.next;
    while (p != NULL)
    {
      // the element of current row
      printf("(%d,%d,%d) ", p->i, p->j, p->tag.val);
      p = p->right;
    }
    printf("\n");
  }
  printf("column!\n");
  for (j = 0; j < 4; j++)
  {
      p = column[j]->tag.next;
      while (p != NULL)
      {
          printf("(%d,%d,%d) ", p->i, p->j, p->tag.val);
          p = p->down;
      }
      printf("\n");
  }
  return 0;
}
