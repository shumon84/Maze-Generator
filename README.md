# Maze-Generator
迷路を自動で生成できます

# Unity上での使い方
Edge* maze_MST(void)またはint(* maze_generator(void))[DEPTH][WIDTH]のいずれかを呼び出すと迷路が生成されます。　　　

maze_MSTを呼び出した場合、生成される迷路は辺集合で表現されます。　　　

maze_generatorを呼び出した場合、生成される迷路はxyz座標がmaze[z][y][x]のように対応した三次元配列で表現され、通路部分を1、壁部分を0としています。　　　

# 迷路の設定について
include/Define.hに設定を書き込んでください。

## WIDTH
WIDTHには迷路の横幅を指定してください。　　　

必ず1以上の奇数でなければいけません。

## DEPTH
DEPTHには迷路の奥行を指定してください。　　　

必ず1以上の奇数でなければいけません。

## HEIGHT
HEIGHTには迷路の高さを指定してください。　　　

必ず1以上の整数でなければいけません。

## START_X
START_Xにはスタート地点のX座標を指定してください。　　　

必ず0以上WIDTH未満の奇数でなければいけません。

## START_Y
START_Yにはスタート地点のY座標を指定してください。　　　

必ず0以上DEPTH未満の奇数でなければいけません。

## START_Z
START_Zにはスタート地点のZ座標を指定してください。　　　

必ず0以上HEIGHT未満の整数でなければいけません。

## GOSL_X
GOAL_Xにはゴール地点のX座標を指定してください。　　　

必ず0以上WIDTH未満の奇数でなければいけません。

## GOAL_Y
GOAL_Yにはゴール地点のY座標を指定してください。　　　

必ず0以上DEPTH未満の奇数でなければいけません。

## GOAL_Z
GOAL_Zにはゴール地点のZ座標を指定してください。　　　

必ず0以上HEIGHT未満の整数でなければいけません。

## SPLIT_RATIO
SPLIT_RATIOには階段を配置率を百分率で指定してください。　　　

必ず0以上100以下の実数でなければいけません。　　　

## その他について
VW,VD,VH,START,GOALの値は変更しないでください。

# ソースコードの機能について
## Define.cpp
include/Define.hで設定した値が正しいか判定します。　　　

void define_check(void)　・・・　include/Define.hで設定した値が不正であった場合、プログラムを強制終了させます。

## Kruskal.cpp
クラスカル法で最小全域木を構築します。　　　

Edge* kruskal(Edge *es) ・・・　辺集合esから最小全域木を構築し、構築した最小全域木の辺集合を返します。

## Union-Find.cpp
Union-Find木を実装しています。　　　

void union_find_init(int n) ・・・　要素数nのUnion-Find木を初期化します。Union-Find木を使用する場合必ず呼び出さなければなりません。　　　

int union_find_find(int x)　・・・　要素xの属する木を返します。　　　

void union_find_unite(int x,int y) ・・・　要素xと要素yをクラスタリングします。　　　

int union_find_same(int x,int y) ・・・　要素xと要素yがクラスタリングされている場合はtrueを、されていない場合はfalseを返します。　　　

## Radom.cpp
xor-shift法を使った乱数生成器です。　　　

unsigned int random_xorshift(void) ・・・　xor-shift法を使った乱数生成器で、unsigned intで表現される乱数を返します。　　　

unsigned int random_nm(unsigned int n,unsigned int m) ・・・　n以上m以下のunsigned intで表現される乱数を返します。m<nとなる値が与えられた場合mを返します。

## Maze.cpp
迷路を自動生成します。　　　

int vertex_x(int vertex) ・・・　与えられた頂点vertexのx座標を返します。　　　

int vertex_y(int vertex) ・・・　与えられた頂点vertexのy座標を返します。　　　

int vertex_z(int vertex) ・・・　与えられた頂点vertexのz座標を返します。　　　

int edge_x(Edge edge) ・・・　与えられた辺edgeのx座標を返します。　　　

int edge_y(Edge edge) ・・・　与えられた辺edgeのy座標を返します。　　　

int edge_z(Edge edge) ・・・　与えられた辺edgeのz座標を返します。　　　

Edge* maze_cost_init() ・・・　ランダムなコストと適切な頂点を与えられた辺集合edgeを返します。　　　

Edge* maze_MST(void) ・・・　迷路を自動生成します。生成した迷路の辺集合edgeを返します。　　　

int(* maze_generator(void))[DEPTH][WIDTH]　・・・　迷路を自動生成します。生成した迷路のうち通路部分を1、壁部分を0とした3次元配列mazeを返します。　　　
