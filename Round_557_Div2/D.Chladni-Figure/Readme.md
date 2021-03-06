### D.Chladni-Figure

这道题和rotated array很相似。原题是，给你一个字符串S（或者数组），问你能否通过rotate（或者最少需要步rotate）能够得到一个和它自身相等的字符串。

对于这个原题，我们做法是将S和自身相串联得到SS，再去除掉第一个元素。我们查找此时的SS中是否存在等于S的substring。然后就是用到了典型的KMP算法。

本题换了一个样子，本质还是KMP。本题可以解读为：有一个数组，数组的每个元素都可能与其他元素有连接。问是否能通过rotate这个数组得到一个和原数组拓扑结构相同的数组。这里的“拓扑结构相同”，意思就是每个元素和它所连接元素之间相对的位置关系是一样的。怎么定义位置关系呢？只要计算每个元素i和它所有连接元素k1,k2,...,kn的位置之差d1,d2,...,dn就行了。

不难发现，我们完全可以套用KMP。只不过代码中```s[i]==p[j]```的判断，统统改为新的判断函数```same(s[i],p[j])```。其中这个same函数就是判断两个元素所存储的d1,d2,...,dn是否完全一致。
