float expm1f(float x)
{
  float result;
  asm ("fexpm1f\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

