double fma(double x, double y, double z)
{
  double result;
  asm ("fmac\t%0,%1,%2,%3" : "=r" (result) : "r" (x), "r" (y), "r" (z));
  return result;
}

