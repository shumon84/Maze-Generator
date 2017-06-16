/* Union-Find木の実装 */

#include"include/Union-Find.h"

int union_find_par[UNION_FIND_MAX_N];
int union_find_rank[UNION_FIND_MAX_N];

void union_find_init(int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      union_find_par[i]=i;
      union_find_rank[i]=0;
    }
}

int union_find_find(int x)
{
  if(union_find_par[x]==x)
    return x;
  else
    return union_find_par[x]=union_find_find(union_find_par[x]);
}

void union_find_unite(int x,int y)
{
  x=union_find_find(x);
  y=union_find_find(y);
  if(x==y)
    return;
  if(union_find_rank[x]<union_find_rank[y])
    union_find_par[x]=y;
  else
    union_find_par[y]=x;
  if(union_find_rank[x]==union_find_rank[y])
    union_find_rank[x]++;
}

int union_find_same(int x,int y)
{
  return union_find_find(x)==union_find_find(y);
}
