### D.N_Problems_During_K_Days

此题是贪心法．
 
可以想到一种最保险的解法，就是尽可能的将每天的分布设计为```a+1, a+2, ... , a+k-1, a+k```的形式，其中把a尽可能地取得最大但使得总数sum依然不超过ｎ．此时如果sum小于ｎ的话，那么必然```n-sum<k```（否则```n-sum>=k```意味着a还可以继续增大）．

那么如何分配这剩下的```extra = n-sum```呢？将它从末位往前分配，给day[i]再分配的上限就是```day[i-1]*2-day[i]```．注意，如果对于i==k的时候，```day[i-1]*2-day[i]>=1```，那么意味着对于其他的day[i]，也必然可以再给其分配大于等于１的数目．于是```extra```必然可以在day[2]到day[k]这几天用完（因为```extra<k```）．如果回溯到了day[0]还是没有把```extra```发完，说明days整体都偏小(比如说1,2,3，还剩2个)，extra发不出去了，这种情况就无能为力了．
