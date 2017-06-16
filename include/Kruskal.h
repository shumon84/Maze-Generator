/* クラスカル法 */

#ifndef ___KRUSKAL
#define ___KRUSKAL

#include"Templet.h"
#include"Define.h"
#include"Union-Find.h"

#define KRUSKAL_V ((WIDTH/2)*(DEPTH/2)*HEIGHT) /* 頂点数 */
#define KRUSKAL_E (KRUSKAL_V*3-(WIDTH/2)*HEIGHT-(DEPTH/2)*HEIGHT-(DEPTH/2)*(WIDTH/2)) /* 辺の数 */

bool kruskal_comp(const Edge& e1,const Edge& e2); /* 辺のコストを比較 */
Edge* kruskal(Edge *es);		  /* 最小全域木を構築する */
void kruskal_free(Edge *es);

#endif

