/* クラスカル法 */

#ifndef ___KRUSKAL
#define ___KRUSKAL

#include"Templet.h"
#include"Define.h"
#include"Union-Find.h"

#define KRUSKAL_V ((WIDTH/2)*(DEPTH/2)*HEIGHT) /* 頂点数 */
#define KRUSKAL_E (KRUSKAL_V*3-(WIDTH/2)*HEIGHT-(DEPTH/2)*HEIGHT-(DEPTH/2)*(WIDTH/2)) /* 辺の数 */

Edge* kruskal(Edge *es);	/* 最小全域木を構築する */

#endif

