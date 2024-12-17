float acosf(float x)
{
  float result;
  asm ("facosf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

