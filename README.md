# Maze-Generator
迷路を自動で生成できます

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
必ず0以上WIDTH未満の奇数でな
ければいけません。

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
SPRIT_RATIOを0にしても階段は0個にはならず、100にしても全てのマスが階段になるわけではありません。

## その他について
VW,VD,VH,START,GOALの値は変更しないでください。

# ソースコードの機能について
## Define.cpp
include/Define.hで設定した値が正しいか判定します。

## Kruskal.cpp
クラスカル法で最小全域木を構築します。

## Union-Find.cpp
Union-Find木を実装しています。

## Radom.cpp
xor-shift法を使った乱数生成器です。

## Maze.cpp
迷路を自動生成します。