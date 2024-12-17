double log10(double x)
{
  double result;
  asm ("flog\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

