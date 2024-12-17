double exp(double x)
{
  double result;
  asm ("fexp\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

