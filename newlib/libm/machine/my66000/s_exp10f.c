float exp10f(float x)
{
  float result;
  asm ("fexp10f\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

