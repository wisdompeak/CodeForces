### D.Kirk-and-a-Binary-String

本题是说，给出一个0/1字符串s，问是否存在另一个相同长度的字符串t，使得任何一个区间内，s和t的最长递增子序列（LIS）的长度都相等，并且要求这个t的0尽量地多。

首先我们要想到一种特殊的字符串fixed string，形如```11110000````，特点是有相同多数目的1和0，并且1在前0在后。fixed string的特点是没有其他字符串可以和它满足题意。显然，对fixed string的任何一处改动（比如说在index=i的位置），都会改变[i:i+1]或者[i-1:i]的LIS。

我们还发现，对任何若干个fixed string的串联，以及在fixed string外围包裹```11....00```，依然还是fixed string.

我们现在希望对原字符串s中的某些1改动成0.

首先，这些改动的地方不能是fixed string的范围。因为对于整个字符串s而言，它的LIS必然包括了每个fixed string的全部的1或者全部的0，（即不可能包括了某个fixed string里面的若干个1和若干个0）。因此，我们对于fixed string的任何改动，都会造成其1的个数和0的个数的同时变化。这样整个字符串s的LIS就变了。

因此，我们只能考虑修改非fixed string的地方。注意到所有的fixed strings里面的1和0的数目都是相等的，所以对于整个s的LIS而言，fixed strings的恰好一半的长度都会贡献给LIS。那样的话，我们就索性全部选0构成一个全0的LIS. 而对于非fixed string的位置，则也统统置为0.这样得到的就是最优解。

所以本题的算法就是找出所有fixed strings的位置保持不变，其他位置都置为0.
