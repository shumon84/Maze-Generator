/* 乱数生成器(xorshift法) */

#ifndef ___RANDOM
#define ___RANDOM

#include"Templet.h"
#include<ctime>

ui random_xorshift(void);	/* 乱数生成器 */
ui random_nm(ui n,ui m);	/* n以上m未満の乱数を生成 */

#endif
