double log(double x)
{
  double result;
  asm ("fln\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

