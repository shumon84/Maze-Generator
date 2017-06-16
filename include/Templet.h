/* 競プロ用テンプレなので気にしないでね */

#include<iostream>
#include<iomanip>
#include<queue>
#include<string>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<vector>
#include<functional>

using namespace std;

#define DEBUG
#ifdef DEBUG
#define dprintf      printf
#define dout(x)      printf(#x" = %d\n",(x))
#define dary(x,n)    {int i;for(i=0;i<(n);i++)printf(#x"[%d] = %d\n",i,*((x)+i));}
#define dloop(i,s,g) for((i)=(s);(i)<(g);(i)++)
#define drep(i,n)    for((i)=0;(i)<(n);(i)++)
#define dstop()      scanf("%*c")
#else
#define dprintf      (1)?0:printf
#define dout(x)
#define dary(x,n)
#define dloop(i,s,g) if(1){}else
#define drep(i,n)    if(1){}else
#define dstop()      (1)?0:0
#endif

#define F    first
#define S    second
#define pb   push_back
#define mp   make_pair

#define loop(i,s,g) for((i)=(s);(i)<(g);(i)++)
#define rep(i,n)    for((i)=0;(i)<(n);(i)++)
#define all(x)      (x.begin(),x.end())

//#define int long long;
#ifdef int
#define INF (0x7fffffffffffffff)
#else
#define INF (0x7fffffff)
#endif

typedef  long long           ll;
typedef  unsigned            ui;
typedef  unsigned long long  ull;
typedef  pair<int,int>       i_i;
typedef  pair<ll,int>        ll_i;
typedef  pair<ll,ll>         ll_ll;
typedef  pair<double,int>    d_i;
typedef  pair<double,double> d_d;
