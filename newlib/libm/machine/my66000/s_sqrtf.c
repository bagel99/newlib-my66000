float sqrtf(float x)
{
  float result;
  asm ("fsqrtf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

