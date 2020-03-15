### F.Maximum-White-Subtree
题意描述：给你一棵树（不一定是二叉树）。每个节点的数值是0或者1. 对每一个节点求问：在包含该节点的所有联通子图里，节点0的数目比节点1的数目多的最大值是多少。

首先，假设我们确定节点1是整棵树的根，问对于根节点的答案是多少？这就是一个dfs问题。仿照题意，假设dp[node]表示包含节点node的所有联通子图里，节点0的数目比节点1的数目多的最大值。那么
```
dp[node] = node->val==0?1:-1 + sum of { max(0, dp[next]) } over all next nodes.
```
其中的道理是，如果next的贡献为负的话，对于cur而言最理想的联通子图肯定不会涉及到next（及其通过它而外延的任何节点）。所以对于节点1的答案就是dp[1]。

然后对于其他节点的答案，不需要重复上面的步骤。我们采用"rerooting"的技巧。考虑我们将root从cur到next进行转移，则在新的根的视角下，会有如下的变化：
```
dp[cur] = dp[cur] - max(0, dp[next])
dp[next] = dp[next] + max(0, dp[cur])
```
因此在新的根（也就是next）的视角下，ret[next] = max(0, dp[next])。
