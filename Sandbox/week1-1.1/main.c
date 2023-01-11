#include <stdio.h>

int main()
{

  int myint = 9;
  float myFloat = 8.1;
  double myDouble = 9.3;
  char myChar = 'x';

  printf("Welcome to IPC144 review\n");
  printf("First Session of OPP244\n");
  printf("My int %d\n", myint);

  printf("Please enter a decimal: ");
  scanf("%lf", &myDouble);
  printf("the value of my double is %lf", myDouble);

  printf("Please enter a whole number between 0 and 100: ");
  scanf("%d", &myint);
  if (myint % 2 == 0)
  {
    printf("EVEN\n");
  }
  else
  {
    printf("ODD\n");
  }

  for (int i = 0; i <= 10; i++)
  {
    printf("%d\n", i);
  }

  return 0;
}