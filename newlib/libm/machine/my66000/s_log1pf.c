float log1pf(float x)
{
  float result;
  asm ("flnp1f\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

