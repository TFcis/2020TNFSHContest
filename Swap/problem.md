---
problemLabel: E
problemName: 序列交換次數
problemId: Swap
---

#

給定一個長度為 N 的序列，序列初始為 $1, 2, 3 ... N$
進行 Q 次操作，操作有兩種：
 - swap a b：交換位置 $a$ 與位置 $b$ 的元素
 - recover l r：依序將元素 $l$ 與位置 $l$ 的元素交換、將元素 $l+1$ 與 位置 $l+1$ 的元素交換 ... 將元素 $r$ 與 位置 $r$ 的元素交換，然後輸出本次操作的有效交換次數（若交換的兩元素相異，此交換為有效交換）

\clearpage

## 輸入
第一行有兩個整數 $N, Q$，表示序列長度和操作次數。
接下來有 $Q$ 行，每行有一個字串和兩個整數，swap $a$ $b$ 或 recover $l$ $r$。

## 輸出
輸出一行為方法數。

## 輸入限制
 - $1 \leq N \leq 500000$
 - $1 \leq Q \leq 500000$
 - $1 \leq a, b, l, r \leq N$

## 子任務
TODO: 未提供

| 編號 | 分數 |    限制    |
| --- | --- | ---------- |
|  1  | 100 | 無額外限制 |

\clearpage

## 範例輸入
```
6 3
swap 1 2
swap 2 3
swap 5 6
recover 1 4
recover 4 4
recover 3 6
```

## 範例輸出
```
2
0
1
```
