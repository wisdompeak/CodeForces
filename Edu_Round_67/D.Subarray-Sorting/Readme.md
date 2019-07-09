### D.Subarray-Sorting

首先，我们重新定义这个题目中的“sort”，本质就是两两的“swap”，可以想象成冒泡法的过程。也就是说，题目允许对于相邻两个“左大右小”的元素进行swap操作，问是否能从a转换为b。

我们将这个数组里的元素按照从小到大的顺序看起。对于某个元素x，它在a中的位置是pa，在b中的位置pb。也就是说我们需要通过不断地swap来将x从pa挪到pb。OK，我们假设可以完成这个操作（事实上肯定可以实现这个操作，因为x是最小的，它可以通过swap任意左移），那么说明所有在a中位于pa右边、且大于等于x的元素（小于x的元素其实已经处理过了，重复操作也没关系），最多只可能swap到pb的位置，这是因为任何比x大的元素都无法通过swap逾越到x的左边来。所以我们可以标记所有在a中位于pa右边、且大于等于x的元素（记其index为i），其能swap到最左边的极限位置left[i]更新为pb（或者保持原来的值，如果pb较小的话）.

接下来我们考察下一个元素y>=x，查找到它在a中的位置是pa，在b中的位置pb。此时如果我们发现left[pa]>pb，这就表示之前的约束有了限制，使得y无论如何都不可能移动到位置pb。这样的话就返回NO，否则重复上面的操作添加新的left的约束。

以上算法的一个缺点是，将所有index大于pa的left[i]都更新为pb的时候，这是线性数量级的操作。改进的方法是设计BIT数组bitArr，用来维护前缀最大值。这是因为本题中left[i]正好符合前缀最大值的性质，也就是如果left[i]改变了，所有i之后的left也都可能会改变。所以我们可以根据模板写出
```
query(bitArr,i);            // 求left[i]的值
update(bitArr, pa, pb);     // 对于所有i>=pa，需要将left[i]都更新为pb
```
基本的算法框架是：
```cpp
    for (int i=1; i<=n; i++){
        int pa = a[i].second;
        int pb = b[i].second;

        int r = query(bitArr,i);

        if (r>pb){
            cout<<"NO"<<endl;
            return;
        }

        update(bitArr, pa, pb);
    }
```
