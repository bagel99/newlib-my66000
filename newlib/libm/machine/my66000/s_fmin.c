double fmin(double x, double y)
{
  double result;
  asm ("fmin\t%0,%1,%2" : "=r" (result) : "r" (x), "r" (y));
  return result;
}

