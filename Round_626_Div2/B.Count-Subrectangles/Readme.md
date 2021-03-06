### B.Count-Subrectangles

题意描述：给出两个0/1数组a和b，并且有一个矩形c，其中c[i][j]=a[i]*b[j]. 问矩形c中有多少个子矩形的大小为k。

将k因式分解得到所有的配对```(p,q)```。查看横向数组a里面存在多少个长度为p的全是1的subarray，即为count1；再查看纵向数组b里面存在多少个长度为q的全是1的subarray，即为count2. 显然这些横纵方向的全一子线段都可以构成一个矩形，故```ret+=count1*count2```.

那么如何高效地求“数组a里面存在多少个长度为p的全是1的subarray”呢？我们可以预处理数组a，将各段全为1的subarray的长度都放在一个数组A里。比如a=[1,1,0,0,1,1,1,0,1]，那么A就等于[2,3,1]。假设A中某一个元素（对应的是a中一个全为1的subarray的长度）是len，那么说明该段subarray里面长度为p的subarray就有```len-p+1```个。有了A数组，那么处理不同的p的时候就很高效，计算count1就很高效了。

总的时间复杂度是o(sqrt(k)*(m+n))。
