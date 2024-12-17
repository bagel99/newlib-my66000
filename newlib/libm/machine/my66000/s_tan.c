double tan(double x)
{
  double result;
  asm ("ftan\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

