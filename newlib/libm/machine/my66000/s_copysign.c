double copysign(double x, double y)
{
  double result;
  asm ("csgn\t%0,%1,%2" : "=r" (result) : "r" (x), "r" (y));
  return result;
}

