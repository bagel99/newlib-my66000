double log1p(double x)
{
  double result;
  asm ("flnp1\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

