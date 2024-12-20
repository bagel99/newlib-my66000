float fminf(float x, float y)
{
  float result;
  asm ("fminf\t%0,%1,%2" : "=r" (result) : "r" (x), "r" (y));
  return result;
}

