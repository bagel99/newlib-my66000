float powf(float x, float y)
{
  float result;
  asm ("fpowf\t%0,%1,%2" : "=r" (result) : "r" (x), "r" (y));
  return result;
}

