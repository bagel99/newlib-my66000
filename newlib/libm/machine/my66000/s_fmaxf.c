float fmaxf(float x, float y)
{
  float result;
  asm ("fmaxf\t%0,%1,%2" : "=r" (result) : "r" (x), "r" (y));
  return result;
}

