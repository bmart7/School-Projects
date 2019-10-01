#include "/user/cse320/Projects/project05.support.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
  char val[] = {'1','2', '3','4','5'};
  int base = 10;
  int c = toInt(val, base);
  bool s = validBase(val, base);
  int f = 0;
  convert(val, base, &f);
  for (int i = 0; i < 5; i++)
  {
    printf("%c, ", val[i]);
  }
  printf("\nBase: %d", base);
  printf("%c", '\n');
  printf("toInt(): %d\n", c);
  printf("validBase(): %d\n", s);
  printf("convert(): %d\n", f);

  val[0] = 'A';
  val[1] = 'B';
  base = 16;
  c = toInt(val, base);
  s = validBase(val, base);
  convert(val, base, &f);
  for (int i = 0; i < 5; i++)
  {
    printf("%c, ", val[i]);
  }
  printf("\nBase: %d", base);
  printf("%c", '\n');
  printf("toInt(): %d\n", c);
  printf("validBase(): %d\n", s);
  printf("convert(): %d\n", f);

  val[0] = ' ';
  val[1] = ' ';
  base = 10;
  c = toInt(val, base);
  s = validBase(val, base);
  convert(val, base, &f);
  for (int i = 0; i < 5; i++)
  {
    printf("%c, ", val[i]);
  }
  printf("\nBase: %d", base);
  printf("%c", '\n');
  printf("toInt(): %d\n", c);
  printf("validBase(): %d\n", s);
  printf("convert(): %d\n", f);

  val[2] = ' ';
  val[3] = ' ';
  val[4] = ' ';
  s = validBase(val,base);
  convert(val, base, &f);
  for (int i = 0; i < 5; i++)
  {
    printf("%c, ", val[i]);
  }
  printf("\nBase: %d", base);
  printf("%c", '\n');
  printf("validBase(): %d\n", s);
  printf("convert(): %d\n", f);
}
