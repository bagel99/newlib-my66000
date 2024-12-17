double exp10(double x)
{
  double result;
  asm ("fexp10\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

