#include"include/Random.h"

ui random_xorshift(void)
{
  static ui seed=time(NULL);
  seed=seed^(seed<<13);
  seed=seed^(seed>>17);
  return seed=seed^(seed<<5);
}

ui random_nm(ui n,ui m)
{
  if(m<n)
    return m;
  return random_xorshift()%(m-n)+n;
}
