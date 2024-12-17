double cos(double x)
{
  double result;
  asm ("fcos\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

