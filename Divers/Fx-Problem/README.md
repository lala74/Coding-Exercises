# F(x) Problem <!-- omit in toc -->

[Link](https://www.facebook.com/vietnamesecplusplus/photos/a.151010888414315/227676990747704/)

## Problem
Let `f(x)` be a function satisfyin `f(1) = 101` and
```
f(x+5) >= f(x) + 5
f(x+1) >= f(x) + 1
```
for all positive integers x. What are the last three digits of `f(2013)`


**Solution**  
```
f(x+1)<=f(x)+1 <=f(x+5)-4 => f(x+5)>=f(x+1)+4 hay f(x+4)>=f(x)+4 .... f(x+1)>=f(x)+1, vậy f(x+1)=f(x)+1  
f(x+1) = f(x) + 1

Then:
f(x) = f(x-1) + 1
```