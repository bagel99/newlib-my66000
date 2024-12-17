float exp2f(float x)
{
  float result;
  asm ("fexp2f\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

