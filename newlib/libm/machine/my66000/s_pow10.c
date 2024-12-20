double pow10(double x)
{
  double result;
  asm ("fpow\t%0,#10,%1" : "=r" (result) : "r" (x));
  return result;
}

