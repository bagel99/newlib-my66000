double atan(double x)
{
  double result;
  asm ("fatan\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

