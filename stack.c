#include <unistd.h>
#include <stdio.h>
#include <string.h>

int top = -1;
int top_op = -1;

char stack_char[100] = {0};
char stack_op[100] = {0};

typedef struct {
  int val;
  char ch;
}OP_S;

OP_S lpri[] = {
  {0, '='},
  {1, '('},
  {3, '+'},
  {3, '-'},
  {5, '*'},
  {5, '/'},
  {6, ')'}
};

OP_S rpri[] = {
  {0, '='},
  {1, ')'},
  {2, '+'},
  {2, '-'},
  {4, '*'},
  {4, '/'},
  {6, '('}
};

int Precede(char stack_op[], char ch)
{
  char ch2;
  int val1, val2, i;
  if (top_op == -1) return (-1);
  ch2 = stack_op[top_op];
  for (i = 0; i < 7; i++)
  {
    if (lpri[i].ch == ch2)
    {
      val1 = lpri[i].val;
    }
    if (rpri[i].ch == ch)
    {
      val2 = rpri[i].val;
    }
  }
  if (val1 < val2)  return (-1);
  else if (val1 == val2)  return 0;
  else  return (1);
}

int isOp(char ch)
{
  if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
    return 1;
  else
    return 0;
}

int stack_val[100] = {0};
int top_val = -1;

int compValue(char *stack_char)
{
  int val1, val2;
  char ch;
  top_op = -1;
  while ((ch = *stack_char))
  {
    switch(ch)
    {
      case '+':
      val2 = stack_val[top_val];
      top_val--;
      val1 = stack_val[top_val];
      val1 += val2;
      stack_val[top_val] = val1;
      break;
      case '-':
      val2 = stack_val[top_val];
      top_val--;
      val1 = stack_val[top_val];
      val1 -= val2;
      stack_val[top_val] = val1;
      break;
      case '*':
      val2 = stack_val[top_val];
      top_val--;
      val1 = stack_val[top_val];
      val1 *= val2;
      stack_val[top_val] = val1;
      break;
      case '/':
      val2 = stack_val[top_val];
      top_val--;
      val1 = stack_val[top_val];
      val1 /= val2;
      stack_val[top_val] = val1;
      break;
      case '#':
      top_val++;
      stack_val[top_val] = atoi(stack_op);
      top_op = -1;
      break;
      default:
      top_op++;
      stack_op[top_op] = ch;
      stack_op[top_op+1] = 0;
      break;
    }
    stack_char++;
  }
  return stack_val[top_val];
}

int main(void)
{
  int len, i = 0;
  char inputStr[100];
  printf("enter the string: ");
  scanf("%s", inputStr);
  fflush(stdin);
  len = strlen(inputStr);
  printf("%s,%d\n", inputStr, len);
  
  
  if (!len)  return 0;
  
  while (i < len)
  {
    if (!isOp(inputStr[i]))
    {
      while (inputStr[i] >= '0' && inputStr[i] <= '9')
      {
        top++;
        stack_char[top] = inputStr[i];
        i++;
      }
      top++;
      stack_char[top] = '#';      
    }
    else
    {
      switch (Precede(stack_op, inputStr[i]))
      {
        case (-1):
        {
          top_op++;
          stack_op[top_op] = inputStr[i];
          i++;
        }
        break;
        case 0:
        {
          top_op--;
          i++;
        }
        break;
        case 1:
        {
          top++;
          stack_char[top] = stack_op[top_op];
          top_op--;
        }
        break;
      }    
    }
  }
   
  while (top_op > -1 && stack_op[top_op] != '=')
  {
    top++;
    stack_char[top] = stack_op[top_op];
    top_op--;
  }
  
  printf("%s\n", stack_char);
  
  printf("%d\n", compValue(stack_char));
  
  return 0;
}
