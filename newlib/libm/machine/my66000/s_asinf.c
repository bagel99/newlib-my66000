float asinf(float x)
{
  float result;
  asm ("fasinf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

