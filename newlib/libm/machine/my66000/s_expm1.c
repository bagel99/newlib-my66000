double expm1(double x)
{
  double result;
  asm ("fexpm1\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

