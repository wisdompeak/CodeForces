### C.Crazy-Diamond

如果不考虑swap(i,j)对于两者距离的限制，那么直觉上只要n次swap就可以达到有序。也就是从第一个开始往后遍历，只要第i个元素不是i，那么就找到真正i所在的位置（比如说j），交换p[i]和p[j]就行了。

此题的问题是，对于这样的(i,j)如果距离太近了，不允许直接swap，怎么办呢？workaround的方法和简单，找到另外一对合适的(a,b)，依次做这么几步：
```
swap(p[i],p[a])
swap(p[j],p[b])
swap(p[a],p[b])
swap(p[i],p[a])
swap(p[j],p[b])
```
正好是五步，本质上就成功实现了对于(i,j)的对换，而且不影响a和b位置上的值。也就是说p[a]和p[b]仅仅是催化剂的作用。

那么如何找到这样好的(a,b)呢？很容易想到这么几个逻辑：
```
    if (j-i>=n/2)
      可以直接交换(i,j)    
    else if (i<=n/2 && j>n/2)
    {
        a=n-1 与 i 配对;
        b=1 与 j 配对;
        通过a,b实现swap(p[i],p[j])
    }
    else if (j<=n/2)
    {
        b=n-1;
        通过b实现swap(p[i],p[j])
    }
    else if (i>n/2)
    {
        b=1;
        通过b实现swap(p[i],p[j])
    }
```


