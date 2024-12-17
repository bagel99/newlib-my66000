float cosf(float x)
{
  float result;
  asm ("fcosf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

