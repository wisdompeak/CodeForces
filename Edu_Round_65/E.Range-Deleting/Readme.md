### E.Range-Deleting

本题感觉难度很大。我花了整整一周的时间才AC。

首先想到一点，如果我们顺序考察nums[i]，发现在它之前有一个nums[j]比它大，这说明最后的删除区间必须包括nums[j]，否则nums[j]和nums[i]同时存留下来的话就不是有序的了。这说明此时删除区间[left,right]中的left的上界必须是nums[j]。换句话说，left可以更小（往下删除更多的数），但绝不能更大（往上保留更多的数）。于是我们依照这个算法把所有的nums[i]扫描一遍，对于每个nums[i]都找到它之前的最小的比它大的数，然后不断取最小，最后就能得到left的上界并记为a。这意味着所有小于a的数字其实我们都可以保留，它们已经保证是有序的了（前提是我们不考虑所有大于等于a的数字）

补充一下：上面这个步骤可以用有序set加上set.upper_bound(k)的方法来做，这样只需要扫一遍。不过这种NlogN在CF上会超时。可以老老实实用预处理的方法来扫两遍：第一步，建立起firstAppear[k]和lastAppearGroup[k]两个数组，其中lastAppearGroup[k]指的是 the last postion for all numbers of [1..k]。第二步：从小到大第一个```firstAppear[k]<lastAppearGroup[k-1]```的元素k，就是我们需要找的left的上界a。

OK，以上才找到了[left,right]中left的上界。这个意思是，如果left取a的话，粗暴地让right取x，就一定能满足条件。当然，这样的删除区间其实抹掉了所有大于等于a的数字，非常的保守。于是我们可以想象，如果left适当往下降的话（也就是多删除了几个较小的数字），是否允许right也适当下降，允许保留若干个顶部较大的数字，前提是仍然使得所有保留的数字是有序的。这就是本题的第二个核心。

我们尝试每一个left的取值，范围是从a到1。固定了left之后，我们考察right从最大的b=x往下尝试。如果某个b满足
```
        while (b>a && (!exist[b] || lastAppear[b]<curEarliest && firstAppear[b]>lastAppearGroup[a-1]))
        {
            // it means we could save b
            if (exist[b]) curEarliest = firstAppear[b];
            b--;
        }                
```
就说明b这个数值可以保留不被删除，也就是如果我们设定删除区间是[left,b-1]的话是OK的。上式中的curEarliest是记录之前所有尝试过的firstAppear[b]。这样的话，我们一路尝试降低b.最后循环退出的话，说明得到的b必须删除。因此在固定这个left的前提下，我们可以将right设定为[b,x]中的任何一个。所以
```
result+=x-b+1;
```
