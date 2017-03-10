[题意：x轴上每隔一个单位放一根竖线，选择两根竖线与x轴形成一个桶，问最多能装多少水？](https://leetcode.com/problems/container-with-most-water)  
分析：水的最大高度取决于两条竖线中的最短的一根，我一开始的思路是枚举左边的竖线i，然后找到右边最靠右的竖线j，满足h[i]<=h[j]，为什么要这样找呢？  
 1. 当水的高度由i决定时(h[i]<=h[j])，那么j越靠右，水装的越多。  
 2. 当水的高度由j决定时(h[i]>=h[j])，那么i越靠左，水装的越多，这正是将序列逆序之后做一遍以上过程得到的。  
 
那么问题转化为：对每一个i求满足h[i]<=h[j]下的max(j)。但是这个不好实现，得想办法改进：如果i从最左边，j从最右边开始往中间逼近，那么如果满足h[i]<=h[j]那么这个i就是最左边，j时最右边的。这时候将j左移一定得不到更大解，因为高度由i决定，将j左移只会使间距变小。如果将i右移，就有可能得到更大的h[i]，使得面积更大。
 
```
class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int i=0,j=n-1;
    
        int ans=0;
        while(i<j){
            if(h[i]<h[j]){
                ans=max(ans,(j-i)*h[i]);
                i++;
            }else{
                ans=max(ans,(j-i)*h[j]);
                j--;
            }
        }
        return ans;
    }
};
```
