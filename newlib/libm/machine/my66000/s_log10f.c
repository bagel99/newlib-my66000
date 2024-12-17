float log10f(float x)
{
  float result;
  asm ("flogf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

