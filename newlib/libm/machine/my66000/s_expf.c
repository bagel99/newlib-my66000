float expf(float x)
{
  float result;
  asm ("fexpf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

