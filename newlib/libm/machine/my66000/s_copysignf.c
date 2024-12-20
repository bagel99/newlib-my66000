float copysignf(float x, float y)
{
  float result;
  asm ("csgnf\t%0,%1,%2" : "=r" (result) : "r" (x), "r" (y));
  return result;
}

