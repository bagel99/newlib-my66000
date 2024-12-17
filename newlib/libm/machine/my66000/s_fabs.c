double fabs(double x)
{
  double result;
  asm ("fabs\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

