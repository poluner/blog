#只对升序序列有效：  
lower_bound 指向 **>=key 的第一个元素**  
upper_bound 指向 **>key 的第一个元素**  

如同sort一样，可以传入比较函数

#升序如果所有元素都小于key，则两者都返回首地址
因此查询小于key的最大元素下标用upper_bound()-1而不是lower_bound
```
int a[]={1};
cout<<lower_bound(a,a+1,0)-a<<endl;//输出0就错了，1不比0小
cout<<upper_bound(a,a+1,0)-a-1<<endl;//输出-1是正确的，表示不存在元素小于0
```
