double pow(double x, double y)
{
  double result;
  asm ("fpow\t%0,%1,%2" : "=r" (result) : "r" (x), "r" (y));
  return result;
}

