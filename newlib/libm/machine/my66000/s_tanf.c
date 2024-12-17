float tanf(float x)
{
  float result;
  asm ("ftanf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

