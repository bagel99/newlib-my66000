float pow10f(float x)
{
  float result;
  asm ("fpowf\t%0,#10,%1" : "=r" (result) : "r" (x));
  return result;
}

