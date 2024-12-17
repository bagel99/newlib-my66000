double log2(double x)
{
  double result;
  asm ("fln2\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

