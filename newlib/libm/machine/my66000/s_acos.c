double acos(double x)
{
  double result;
  asm ("facos\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

