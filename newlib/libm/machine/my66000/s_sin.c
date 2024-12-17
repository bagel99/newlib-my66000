double sin(double x)
{
  double result;
  asm ("fsin\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

