float fabsf(float x)
{
  float result;
  asm ("fabsf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

