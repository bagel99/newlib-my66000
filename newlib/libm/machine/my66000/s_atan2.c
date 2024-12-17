double atan2(double y, double x)
{
  double result;
  asm ("fatan2\t%0,%1,%2" : "=r" (result) : "r" (y), "r" (x));
  return result;
}

