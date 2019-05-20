### E.The-LCMs-Must-be-Large

这本质上考察的是数学。

我们假设第i天，A采购的商店编号所构成的集合是Di，那么对应B采购的商店编号所构成的集合是Si.根据题意要求```LCM(Di)>LCM(Si)```(1)。

如果在第j天，Dj与Di互斥的话，说明Dj就是Si的子集！根据子集的性质，```LCM(Dj)<LCM(Si)```(2)。同理，Di就是Sj的子集，我们也有```LCM(Di)<LCM(Sj)```(3)。

于是我们就有了```LCM(Di)>LCM(Si)>LCM(Dj)>LCM(Sj)>LCM(Di)```最终导致了矛盾。其中第一个大于号来自不等式(1)（题意），第二个不等号来自于不等式(2)，第三个不等号来自于题意，第四个不等号来自于不等式(3).

所以要满足题意的话，就要求任何两天i和j，Di和Dj都不能互斥！

所以我们利用一个bitset数组，```vector<bitset<10000>>A(m)```，其中A[i]就表示第i天的Si，每一个bit表示是否在此商店购物。所以我们就判断任意两个A[i]和A[j]的位与结果是否是0，是的话说明没有交集部分，Di和Dj互斥，直接返回impossible.

在C++里我们可以直接用(A[i]&A[j]).any()这个函数来判断一个bitset是否都为0。