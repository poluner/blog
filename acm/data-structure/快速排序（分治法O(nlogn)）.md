划分问题：把数组的各个元素重排后分成左右两部分，使得左边的任意元素都小于等于右边的任意元素。

递归求解：把左右两部分分别排序。

合并问题：不用合并，因为此时数组已经完全有序。

```
void qsort(int L,int R){
    if(L>=R)return;
    int l=L,r=R;
    int key=a[l];//取a[l]为关键字

    while(l<r){
        while(l<r&&a[r]>=key)r--;
        a[l]=a[r];    //由于a[l]最初被保存在key中，所以可以被覆盖

        while(l<r&&a[l]<=key)l++;
        a[r]=a[l];    //由于先执行了第8行，所以a[r]在这里可以被覆盖
    }
    a[l]=key;

    qsort(L,l-1);//对分界点左边快排
    qsort(l+1,R);//对分界点右边快排
}
```
如果将“划分问题”单独写成一个函数，程序会清爽些：
```
int part(int l,int r){//排序并返回分界点
    int key=a[l];
    while(l<r){
        while(l<r&&a[r]>=key)r--;
        a[l]=a[r];

        while(l<r&&a[l]<=key)l++;
        a[r]=a[l];
    }
    a[l]=key;
    return l;
}

void qsort(int l,int r){
    if(l>=r)return;
    int p=part(l,r);
    qsort(l,p-1);//对分界点左边快排
    qsort(p+1,r);//对分界点右边快排
}
```
