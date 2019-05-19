## 思路1 直接处理

先记录正负号，直接用切片反转，然后用`int(str())`的方法去掉0。最后返回时判断一下有没有越界。

在`python3`中可以利用`(a > b) - (a < b)`来实现2中的`cmp`方法。

注意在输入-8463847412会出现-2**31，但是-8463847412本身是不合法的输入，所以在越界判断时不用考虑等于-2**31的情况。