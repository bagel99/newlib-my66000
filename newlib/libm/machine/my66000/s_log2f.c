float log2f(float x)
{
  float result;
  asm ("fln2f\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

