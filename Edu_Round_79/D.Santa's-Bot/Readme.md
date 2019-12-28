### D.Santa's-Bot

这题是在CF第一次使用逆元(inverse element)取余数。

CF中经常会要求这样输出结果：```Let this probability be represented as an irreducible fraction x/y. You have to print x⋅y^−1 mod 998244353, where y^−1 is the inverse element of y modulo 998244353 (such integer that y⋅y−1 has remainder 1 modulo 998244353).```

这里的inverse element并不是指的倒数，而是逆元。y的逆元写作y^-1，满足这样的性质：
```
x / y = x * y^-1 (mod M), M is a prime
```
逆元的计算方法如下：
```
a^-1 = (M- [M/a] )(M%a)^-1(mod M)，其中[]是向下取整。
```
代码如下，可以作为模板记下来。
```cpp
const ll N=1e6+7,mod=998244353;
ll inv[N];
for(inv[1]=1,i=2;i<N;++i)
    inv[i]=(mod-mod/i)*inv[mod%i]%mod
```
逆元的计算有如下的性质：
```
x1/y1 + x2/y2 = x1 * y1^-1 + x2 * y2^-1 (mod M)
x1/y1/y2 = x1 * y1^-1 * y2^-1 (mod M)
```

至于本题的算法，还是比较容易想到的。假设有N个人，我们以1/N的均等概率采样到小孩xi，然后对于小孩xi喜欢的yj个玩具（假设这个孩子总共喜欢Yi个玩具）以均等概率采样。再假设这个玩具yj有对应的wj个孩子喜欢，那么对于随机得到的孩子z恰好也喜欢它的概率就是wj/N.

所以第xi个孩子能够满足条件的概率就是 ```Pi = sum 1/Yi * wj/N, for j=1,2,...Yi```

那么所有孩子x满足条件的概率就是 ``` sum Pi/N, for i=1,2,3,...,N```

