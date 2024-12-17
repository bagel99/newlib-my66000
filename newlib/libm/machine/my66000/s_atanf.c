float atanf(float x)
{
  float result;
  asm ("fatanf\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

