/* マクロ,構造体定義 */

#ifndef ___DEFINE
#define ___DEFINE

#include"Templet.h"

#define WIDTH   (21) /* ダンジョンの横幅(X座標) */
#define DEPTH   (21) /* ダンジョンの奥行(Y座標) */
#define HEIGHT  (3)  /* ダンジョンの高さ(Z座標) */

#define VW (WIDTH/2) /* 頂点のx座標の最大値 */
#define VD (DEPTH/2) /* 頂点のy座標の最大値 */
#define VH (HEIGHT)  /* 頂点のz座標の最大値 */

#define START_X (1)  /* スタート地点のX座標 */
#define START_Y (1)  /* スタート地点のY座標 */
#define START_Z (0)  /* スタート地点のZ座標 */
#define START   (START_X/2+(START_Y/2)*VW+START_Z*VW*VD) /* スタート地点の頂点座標 */

#define GOAL_X  (19)  /* ゴール地点のX座標 */
#define GOAL_Y  (19)  /* ゴール地点のY座標 */
#define GOAL_Z  (2)  /* ゴール地点のZ座標 */
#define GOAL    (GOAL_X/2+(GOAL_Y/2)*VW+GOAL_Z*VW*VD) /* スタート地点の頂点座標 */

#define SPLIT_RATIO (25) /* 階段の配置率を設定(100分率) */

typedef struct edge
{
  int u;
  int v;
  ui cost;

  bool operator<(const edge&right)const
  {
    return cost<right.cost;
  }

  bool operator>(const edge&right)const
  {
    return cost>right.cost;
  }

  bool operator==(const edge&right)const
  {
    return (u==right.u)&&(v==right.v);
  }
}Edge;

void define_check(void); /* 定義された定数が正しいかどうか判定する */

#endif
