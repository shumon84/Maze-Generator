#include"include/Kruskal.h"

Edge* kruskal(Edge *es)
{
  const int V=KRUSKAL_V; // 頂点数
  const int E=KRUSKAL_E; // 辺数
  int i=0,j=0;
  Edge *ret=(Edge*)calloc(sizeof(Edge),E); // 最小全域木の辺集合 

  sort(es,es+E);      // Edge.costの小さい順にソートする
  union_find_init(V); // Union-Findの初期化
  for(i=0;i<E;i++)
    if(!union_find_same(es[i].u,es[i].v))
      {
	union_find_unite(es[i].u,es[i].v);
	ret[j++]=es[i];
      }
  Edge temp={-1,-1,INF};
  for(;j<E;j++)
    ret[j]=temp;
  
  return ret;
}
