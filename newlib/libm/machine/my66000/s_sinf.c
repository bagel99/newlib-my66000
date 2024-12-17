float sinf(float x)
{
  float result;
  asm ("fsinf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

