[51nod1225余数之和](http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1225)  
题意：求
<img src="http://latex.codecogs.com/svg.latex?\sum_{i=1}^{n}{n\%i}=?">  


先来求解一个不等式：<img src="http://latex.codecogs.com/svg.latex?\frac{n}{a+1}<x\leqslant\frac{n}{a}">，n,a,x都是正数，n和a已知，求x。  
用n除以不等式，得到
<img src="http://latex.codecogs.com/svg.latex?a\leqslant%20\frac{n}{x}%3Ca+1">
。  
将此结论用于int类型，除法也是取整数部分可得到新的结论：
<img src="http://latex.codecogs.com/svg.latex?\forall%20x\epsilon%20(\frac{n}{a+1},\frac{n}{a}]">
都有
<img src="http://latex.codecogs.com/svg.latex?\frac{n}{x}\equiv%20a">  

现在回到题目，题意等价于求
<img src="http://latex.codecogs.com/svg.latex?\sum_{i=1}^{n}{n-\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor%20*i}=n^2-\sum_{i=1}^{n}{\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor%20*i}">

由于向下取整，那么
<img src="http://latex.codecogs.com/svg.latex?\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor">
必然在某一连续区间是相同的值，由于
<img src="http://latex.codecogs.com/svg.latex?\frac{n}{\sqrt{n}}=\sqrt{n}">
所以
<img src="http://latex.codecogs.com/svg.latex?\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor">
最多有
<img src="http://latex.codecogs.com/svg.latex?2\sqrt{n}">
个不同的值，
i和
<img src="http://latex.codecogs.com/svg.latex?\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor">
处于对称的状态，就像因子一样。  
因此只需考虑区间
<img src="http://latex.codecogs.com/svg.latex?[1,\sqrt{n}]">
即可，
<img src="http://latex.codecogs.com/svg.latex?\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor">
在区间
<img src="http://latex.codecogs.com/svg.latex?[1,\sqrt{n}]">
中的值都不相同，而区间
<img src="http://latex.codecogs.com/svg.latex?[\sqrt{n},n]">
中有连续相同的情况，根据上面得到的结论可知：  
对于任意一个数i，在区间
<img src="http://latex.codecogs.com/svg.latex?[\frac{n}{i+1}+1,\frac{n}{i}]">
上的值都等于
<img src="http://latex.codecogs.com/svg.latex?\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor">
，总共有
<img src="http://latex.codecogs.com/svg.latex?\frac{n}{i}-\frac{n}{i+1}">
个，那么这一段区间的
<img src="http://latex.codecogs.com/svg.latex?\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor%20*i">
求和便是i的等差数列，首项是
<img src="http://latex.codecogs.com/svg.latex?\left%20\lfloor%20\frac{n}{i+1}%20\right%20\rfloor%20+1">
末项是
<img src="http://latex.codecogs.com/svg.latex?\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor">
，总数是
<img src="http://latex.codecogs.com/svg.latex?\frac{n}{i}-\frac{n}{i+1}">，
等差数列求和之后乘上
<img src="http://latex.codecogs.com/svg.latex?\left%20\lfloor%20\frac{n}{i}%20\right%20\rfloor">
即可。



