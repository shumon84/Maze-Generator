/* Union-Find木 */

#ifndef ___UNION_FIND
#define ___UNION_FIND

#include"Define.h"

#define UNION_FIND_MAX_N ((WIDTH)*(DEPTH))

void union_find_init(int n);        /* Union-Find木を初期化する */
int union_find_find(int x);         /* key x を含む木をfindする */
void union_find_unite(int x,int y); /* key x と key y をuniteする */
int union_find_same(int x,int y);   /* find(x)==find(y) */

#endif
