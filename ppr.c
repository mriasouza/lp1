#include <stdio.h>
float f2c (int);
int main ()
{
  int f;
  for (f=-10; f<=50; f+=10){
    printf("%d f%\n", f, f2c(f));
  }
}
float f2c (int)
{
  return 5.0/9 * (f-32)
}

