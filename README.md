# write_more_code

## two sum
1. init vector
- `vector<int> x = vector<int>(size)`
2. 注意key和value
3. 注意放入dict的时机。

## add two numbers
1. new sth.
`pre->next = new ListNode(1);`
2. use existing`ListNode *x = l1;`


## Longest Substring Without Repeating Characters 
1. add item to set
`set.insert()`
2. remove
`set.erase()`
3. 左右指针维护

## 重写。寻找两个有序数组的中位数
奇数中位数，分界线左边有n/2个值，取右边，偶数中位数，分界线左边有n/2个值，取两边的平均。
此处二分分界线的右边。可计算出另一个数组的值为n/2-mid。

1. 为什么不二分左边
- 因为二分左边的话，要从-1 到n-1，-1作为二分值易越界。 
2. 成功条件。

3. 边界！！！
a.　其实是L的初始值，但是写着太难了。于是此处要判断n/2-mid是否为负数。是的话则mid要往小了走。
b. 边界的另外一边可能没有值，此处处理的还算优雅。OK
c.　何时往小往大。拿真实的值模拟一下。

## Longest Palindromic Substring
1. 回文，要思考中心。
2. 多画图
3. 有空重写
4. 马拉车算法


### 6. Z string
找规律题，要更快更准一点。
减少乘除运算

### 7. 
1. 初始化一个char 
       char tmp[12] = {'\0'};
2. `ans = ans * 10 + tmp[i] - '0';`会溢出, `ans = ans * 10 + (tmp[i] - '0'); ` 不会
3.　string的size不会因为'\0'被截断

### 10. reg match 
1. 转移方程还是要谨慎再谨慎啊。

### 11. container with most water
1. 左右指针的使用还不够机智。

### 15. 3sum
1. 依然是左右指针。 注意去重的方法。
2. vector的size是一个无符号数，注意不要做减法。

### 17. letter comb
1. 注意初始化。过。


### 19
1. 注意头指针被删除

### 20 pass

### 21
1. 空头指针有时候会简化问题。（todo 回顾19）
2. 只剩一个的时候不用while 直接连就好了。