double exp2(double x)
{
  double result;
  asm ("fexp2\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

