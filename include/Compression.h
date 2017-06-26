/* 迷路情報の圧縮&展開 */

#ifndef ___COMPRESSION
#define ___COMPRESSION

#include"Define.h"
#include"Kruskal.h"
#include"Templet.h"

#define DIRECT_NOTHING (0x00000000) /* 道なし */
#define DIRECT_FRONT   (0x00000001) /* 前 */
#define DIRECT_LEFT    (0x00000002) /* 左 */
#define DIRECT_BACK    (0x00000004) /* 後 */
#define DIRECT_RIGHT   (0x00000008) /* 右 */
#define DIRECT_UP      (0x00000010) /* 上 */
#define DIRECT_DOWN    (0x00000020) /* 下 */

#define ROAD_UNITE     (1)	    /* 1マスあたりの1辺の長さ */
#define ROTATE_UNITE   (90)	    /* 単位回転量 */

#define ROAD_NOTHING   (0x00000000) /* 道でない(空洞) */
#define ROAD_STREIGHT  (0x00000001) /* 直進 */
#define ROAD_CORNER    (0x00000002) /* 曲がり角 */
#define ROAD_BRANCH    (0x00000003) /* 三叉路 */
#define ROAD_CROSS     (0x00000004) /* 十字路 */
#define ROAD_STOP      (0x00000005) /* 行き止まり */
#define ROAD_START     (0x00000006) /* スタート */
#define ROAD_GOAL      (0x00000007) /* ゴール */

#define SPLIT_NOTHING  (0x00000000) /* 階段なし */
#define SPLIT_UP       (0x00000001) /* 上り階段あり */
#define SPLIT_DOWN     (0x00000002) /* 下り階段あり */
#define SPLIT_DOUBLE   (0x00000003) /* 上り下り階段あり */

#define VW (WIDTH/2) /* 頂点のx座標の最大値 */
#define VD (DEPTH/2) /* 頂点のy座標の最大値 */
#define VH (HEIGHT)  /* 頂点のz座標の最大値 */

#define popcount(n) (0x0000ffff&((0x00ff00ff&((0x0f0f0f0f&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))+((0xf0f0f0f0&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))>>4)))+((0xff00ff00&((0x0f0f0f0f&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))+((0xf0f0f0f0&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))>>4)))>>8)))+((0xffff0000&((0x00ff00ff&((0x0f0f0f0f&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))+((0xf0f0f0f0&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))>>4)))+((0xff00ff00&((0x0f0f0f0f&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))+((0xf0f0f0f0&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))>>4)))>>8)))>>16)

#define compress_road(n)      ((n)<< 0) /* 通路タイプを指定して圧縮 */
#define compress_split(n)     ((n)<< 3) /* 階段の有無を指定して圧縮 */
#define compress_rotate(n)    ((n/ROTATE_UNITE)<<5) /* 回転量を指定して圧縮 */
#define compress_x(n)         ((n)<< 8) /* x座標を指定して圧縮 */
#define compress_y(n)         ((n)<<16) /* y座標を指定して圧縮 */
#define compress_z(n)         ((n)<<24) /* z座標を指定して圧縮 */
#define compress_xyz(x,y,z)   (compress_x(x)|compress_y(y)|compress_z(z))	/* 座標のみを指定して圧縮 */
#define compress(r,s,d,x,y,z) (compress_road(r)|compress_split(s)|compress_rotate(d)|compress_x(x)|compress_y(y)|compress_z(z)) /* 全ての要素を指定して圧縮 */

#define extract_road(n)     ( ((n)>> 0)&0x7)               /* 通路の形を展開 */
#define extract_split(n)    ( ((n)>> 3)&0x3)
#define extract_rotate(n)   ((((n)>> 5)&0x7)*ROTATE_UNITE) /* 回転量を展開 */
#define extract_x(n)        ((((n)>> 8)&0xff)*ROAD_UNITE)  /* x座標を展開 */
#define extract_y(n)        ((((n)>>16)&0xff)*ROAD_UNITE)  /* y座標を展開 */
#define extract_z(n)        ((((n)>>24)&0xff)*ROAD_UNITE)  /* z座標を展開 */

int vertex_x(int vertex);
int vertex_y(int vertex);
int vertex_z(int vertex);

int edge_x(Edge edge);
int edge_y(Edge edge);
int edge_z(Edge edge);

void extract(int n);

void compression_init(Edge *edge);
int compression_direct(int x,int y,int z);
int compression_stairway(int x,int y,int z);
int compression_road(int direct);
int compression_split(int stairway);
int compression_stop(int direct);
int compression_streight(int direct);
int compression_corner(int direct);
int compression_branch(int direct);
int compression_rotate(int direct,int road);
int compression_maze(int x,int y,int z);
void compression(int maze[HEIGHT][DEPTH][WIDTH],Edge *edge);

#endif
