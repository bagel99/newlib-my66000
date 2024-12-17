float atan2f(float y, float x)
{
  float result;
  asm ("fatan2f\t%0,%1,%2" : "=r" (result) : "r" (y), "r" (x));
  return result;
}

