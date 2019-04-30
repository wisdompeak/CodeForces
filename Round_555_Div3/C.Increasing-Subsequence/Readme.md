### C.Increasing-Subsequence

这道题虽然难度不大，但是要考虑的细节很多。

基本的思想不难想到，就是双指针。左指针右移，右指针左移。那么需要考虑什么情况下对应什么样的移动呢？我们需要设置一个变量now，来记录当前已经加入序列的最近的一个数，这个值初始量为INT_MIN.

1. 如果nums[i]和num[j]都不大于now，那么根据题意需要一个严格递增的序列，说明两个指针都无法移动了，退出程序。

2. 如果nums[i]或nums[j]中只有一个大于now，说明以后肯定就只能选择那一侧前进，于是i递增或者j递减，直到不满足递增序列的要求位置。

3. 如果nums[i]或nums[j]都大于now: 并且 (a) 如果nums[i]和num[j]不相等，那么选择较小的一个加入答案并更新now为那个数；(b) 如果nums[i]和nums[j]相等，同样说明以后肯定就只能选择某一条边前进. 选择哪一个呢？分别尝试一下就知道了，选择那个能使得前进步数最多的那一侧就行了。