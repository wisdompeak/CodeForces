### D.Beautiful-Array
https://codeforces.com/contest/1155/problem/D

本题一开始陷入了错误的思维，以为可以用```max{leftOrigin[i]+rightModified[i+1]}```来寻找答案。但事实上，被修改的部分可以是nums的任意中间一段，所以这个思路是错误的。

这其实是一个典型的tri-status的DP问题。设计三个状态：
1. dp[i][0]表示截止到nums[i]且nums[i]仍为原元素（未到修改区）时，能得到的max_ending_here；
2. dp[i][1]表示截止到nums[i]且nums[i]处于修改区时，能得到的max_ending_here；
3. dp[i][2]表示截止到nums[i]且nums[i]已经脱离翻转区（即原元素）时，得到的max_ending_here；

注意到以上三个状态都是非负的。根据题意，不难得到递推关系：
```
dp[i][0] = dp[i-1][0]+nums[i]; 
dp[i][1] = max(dp[i-1][0],dp[i-1][1])+nums[i]*x; 
dp[i][2] = max(dp[i-1][1],dp[i-1][2])+nums[i]; 
```
此外上面三个状态都要再额外取非负。Result就是在遍历i的过程中，以上三个状态变量的最大值！
