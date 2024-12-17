double sqrt(double x)
{
  double result;
  asm ("fsqrt\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

