double asin(double x)
{
  double result;
  asm ("fasin\t%0,%1" : "=r" (result) : "r" (x));
  return result;
}

