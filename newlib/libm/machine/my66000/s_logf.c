float logf(float x)
{
  float result;
  asm ("flnf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

