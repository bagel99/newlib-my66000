float fmaf(float x, float y, float z)
{
  float result;
  asm ("fmacf\t%0,%1,%2,%3" : "=r" (result) : "r" (x), "r" (y), "r" (z));
  return result;
}

