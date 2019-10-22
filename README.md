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

### 22 pass
产生所有可能的，dfs之 

### 23 merge k sorted
1. pq的使用
- self defined compare function
```cpp
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val; // 是否把a往后放
        }
    };
    priority_queue<ListNode*, vector<ListNode*>, cmp > pq;
```
第二个参数是container
小顶堆。 要写：是否把第一个参数往后挪。
或者重载运算符
```cpp
 9 bool operator<(Node a, Node b){//返回true时，说明a的优先级低于b
10     //x值较大的Node优先级低（x小的Node排在队前）
11     //x相等时，y大的优先级低（y小的Node排在队前）
12     if( a.x== b.x ) return a.y> b.y;
13     return a.x> b.x; 
14 }
```
- `top()` instead of `front()` -> it is a heap
2. 有空看看堆怎么写。

### 25. Reverse Nodes in k-Group
1. 这种模拟型的，边模拟每个阶段边写。

### 30. Substring with Concatenation of All Words
1. 重点条件是长度一样。
2. 坑： 不要用tmp(f), tmp = f。用时爆炸，内存爆炸。大概这里没有释放内存？ todo
不作死
执行用时 :
28 ms
, 在所有 C++ 提交中击败了
98.47%
的用户
内存消耗 :
12.5 MB
, 在所有 C++ 提交中击败了
85.31%
的用户

作死：几百几百
### 31 next permutation
![image/31.jpg](image/31.jpg)
1. 边界判断
2. 如何构成下一个排列：最小地提高：最后可以提高的位置：改成最小的最大值，重新使之从小变大。

### 32. longest valid parenthese
1. 注意看题。
2. 括号匹配考虑栈。
3. 计算长度考虑idx

todo:还能更优

### 33 search in rotated sorted array
1. 先找split点再分别对两段二分。（咦只要看一个是不是在去区间里就行了不用搜两次= =
2. todo 两次二分可以合并。

### 34
1. `upper_bound`返回的是下一个位置。

### 39
组合就dfs pass
### 41 First Missing Positive 
和另一题一样，用正负来做哈希

### 42 trapping rain
1. 左右最大值模拟。注意更新时机 
2. todo ： 左右指针法减少空间。 https://www.cnblogs.com/qiyueliu/p/10990663.html#autoid-1-0-0

### 44 Wildcard Matching
dp
注意*的边界初始化

### 45 Jump Game2
维护当前步最远的和下一步最远的。

### 46 permutation
1. lowerbit https://www.cnblogs.com/qiyueliu/p/10990663.html#autoid-1-0-0

### 48 rotate 
1. 找规律，旋转一个值不变，只变位置
### 49
水题

### 51 N Queens
dfs + 剪枝
### 52 N Queens
位运算优化

### 53 最大子串和。
常规操作

### 55 jump game
维护最远值，不要傻乎乎。

### 56 merge intervals
1.　自定义的cmp函数，需要是static的
```cpp
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
```
sort里的cmp是把谁放前面。
小序

### 57 Insert intervals
遍历一遍。。但是有点慢todo

### 61 Rotate List
变环转一转，注意长度处理

### 62 unique path
组合数学

### 64 minimum path sum
1.滚动数组小心
2. todo: 原地
### 68 	Text Justification
模拟就行 pass

### 72
1. 滚动数组 - -
2. 删除和增加本质上没有区别

### Search a 2D Matrix
裸题

### 75 sort color
1. 已经处理过的值不是0就是1

### 76 minimum window substring
1. 注意边界细节
2. todo: 还能更快？

### 78 dfs
1. dfs
2. todo: 省内存？
### 79　word search
1. 裸的dfs
2. todo: 如何更快？
### 81 search in rotated sorted array2
1. 用和最后一个元素比较来防止没有split point。
2. 和最后一个元素比，判断条件不能写nums[mid] >= last 而要写>last。因为本来就是>，和比较第一个不一样
3.　todo还能再优化到一次搜索
### 84 largest rectangle in histogram
1. 找到小于/大于某个点最近的点的时候，要想想单调栈。
2. 模拟想一下出栈条件是什么。
3. todo： 再深入学学

### 85 Maximal Rectangle
1. h很好理解。
2. l r的更新方式。
todo：again

### 87 	Scramble String 
1. 枚举分割点，爆搜

### 94 Binary Tree Inorder Traversal
1. 栈模拟dfs，进栈while
2. 想想后序

### 96 Unique Binary Search Trees
1. dp函数设置

### 97 	Interleaving String
1. 常规dp，注意边界
### 98 Validate Binary Search Tree
1. 写的极挫。
2. 研究引用

### 99 Recover Binary Search Tree    
BST的中序遍历是升序的。
第一个不对的和最后一个不对的，交换

### 101 Symmetric Tree
递归，左右右左检查是否一致。

### 102 Binary Tree Level Order Traversal
1. 什么是深度优先遍历？

### 105 Construct Binary Tree from Preorder and Inorder Traversal
1. 使用index map
2. 左右分
3. todo 有空106

### 114 Flatten Binary Tree to Linked List
### 121 Best Time to Buy and Sell Stock
### 123 Best Time to Buy and Sell Stock III    
啊= = 就状态转移
### 124 Binary Tree Maximum Path Sum
1. 树上dp，对每个节点来说，最长的是尝试用自己把左右的最长路径连起来。返回给上一层，就是自己，自己+左边，自己+右边。

### 128 Longest Consecutive Sequence
1. 不insert的话count 比 find好，不加东西。
2. 避免重复查找的方法

### 139 Word Break
1. 可达性的使用和如何查一个word在dict里，不就set咩。
2. 构造trie树
```cpp
    struct TrieNode{
        bool flag;
        map<char, TrieNode*> next;
        TrieNode(): flag(false){}
    };
    void struct_trie(vector<string>& wordDict){
        root = new TrieNode();
        for(auto word: wordDict){
            TrieNode* now = root;
            for(auto c: word){
                if(now->next.find(c) == now->next.end()){
                    now->next[c] = new TrieNode();
                }
                now = now->next[c];
            }
            now->flag = true;
        }
    }
```
3. 记忆化搜索。从前往后搜全部，所以要记录vis{i}表示i后面有没有被搜索过。


### 141 142 Linked List Cycle
复杂度计算
1. 证明相遇时慢的没有走过一圈。
- 设起点离交点为x，相遇点走z步到x，x点走y步到相遇点。则圈长度K = y+z
- 设x走到交点时，y离交点还有t步。因为y的速度是x的两倍，所以此时y已经走了2x，在圈里走了x步。其中有k-(x-x//k*k)。这个值必然< k。因此再过k-(x-x//k*k)个时间单位相遇。 这个值一定小于k，所以相遇时慢的没走一圈
2. 复杂度
所以复杂度为O(X+K)
3. 寻找交点
- 根据上述设定，有`x+y = (x + y + C(y+z)) / 2`
`x + y = C(y+z)`
`x = (C-1)(y+z) + z`
所以让指针从起点，相交点往前走，相遇即是环开始的点。（此时从相遇点开始走的指针可能已经走了N圈，但这不重要）

### 146 LRU Cache
1. 在list中查找的，用map
2. 实时维护一个要取出插入最后面的，用双向链表）

### 148 Sort List
1. 用快慢指针查找链表的中点。
2. 非递归方法：从1,2，4,8的长度合并

### 152 Maximum Product Subarray
1. 因为乘积可以变号，所以要维护最大最小值。
2. 因为负数交叉相乘，所以要用中间变量存结果。

### 153 Find Minimum in Rotated Sorted Array
1. define a new array, the corresponding position means that if the element is larger than this last element


### 154 Find Minimum in Rotated Sorted Array 2
similar.
but there is a more elegant solution! todo:
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/154-find-minimum-in-rotated-sorted-array-ii-by-jyd/
学习高级二分

### 155 Min Stack
1. vec.size() 记录的是当前有多少个值，而非空间。
```
    f.push_back(0);
    f.push_back(1);
    cout<<f.size() << endl;
    f.pop_back();
    cout<<f.size() <<endl;
```
的结果为2,1
2. 单调性->栈
3. todo 单调队列

### 160 Intersection of Two Linked Lists
1. 搞笑法，把B的结尾接到A上，就成了找链表找环入口的问题。
2. 消除长度法。
### 167 Two sum 2
pass

### 169 Majority Element
1. sum ( == major ? 1 : -1) > 0。所以维护和，同归于尽

### 174 dungeon-game
1. 重点是如何构造无后效性的性质。
2. 从最后一个点到第一个点。
3. 定义dp为进入这个点，可以到达终点的最小生命。这使得当一个点为正时，可以更新到起点开始的地方。
4. 当一个点的dp值为负数，说明这个点只要进来的时候还活着，就能继续活下去。
5. todo 好题

### 198 House Robber
水dp

### 200 Number of Islands
水bfs

### 206 Reverse Linked List
水链表- -

### 207 Course Schedule
cont
### 208 Implement Trie (Prefix Tree)
###209 minimum-size-subarray-sum
水题

### 215 Kth Largest Element in an Array
```
    int partition(vector<int>& nums, int s, int e){
        if(s == e) return s;
        int now = nums[s];
        while(s < e){
            while(s < e && nums[e] <= now) --e;
            nums[s] = nums[e];
            while(s < e && nums[s] >= now) ++s;
            nums[e] = nums[s];
        }
        nums[s] = now;
        return s;
    }
```
partition写法

### 221 Maximal Square
1. dp　转移方法
### 222 count-complete-tree-nodes
1. binary search the number of tree nodes, we could find the node from root node with bin-representation.
2. height of right / left . todo

### 226 Invert Binary Tree
ok
### 234 Palindrome Linked List
1. 快慢指针找中点。
2. 反转。

### 238 Product of Array Except Self
easy

### 236 Lowest Common Ancestor of a Binary Tree
1. ok
2. other methods

### 239 Sliding Window Maximum
1. 双端队列 deque
- `push_back(), push_front()`
- `pop_back()` ...
2. 单调队列实现 ok

### 240 Search a 2D Matrix II
1. 每次删掉一行或者一列。
2. 重点是开始的位置。 某行最大某列最小。

### 279 Perfect Squares
1. dp，变成无穷背包，复杂度O(n * sqrt(n)) 
2. dp　记忆化搜索

### 283 Move Zeroes
1. todo swap idea

### 300 Longest Increasing Subsequence
1. dp[i]表示长度为i的最后一个的最小值。
2. 二分搜大于某个的小值。
```cpp
                int l = 1, r = len;
                while(l <= r){
                    int mid = (l + r) >> 1;
                    if(dp[mid] >= nums[i]) r = mid - 1;
                    else l = mid + 1;
                }
                dp[l] = nums[i];
```

### 309 Best Time to Buy and Sell Stock with Cooldown
1. 状态机的提取和转移

### 312 Burst Balloons
1. 复杂dp。
2. 因为区间会改变，所以dp状态定义为一个区间。

### 322 Coin Change
1. 背包

### 337 House Robber III
1. 典型树形dp

### 338 Counting Bits
1. 左移一位，所以用1/2推出当前

### 347 Top K Frequent Elements
1. 注意pq的写法

### 394 Decode String 
栈模拟，码力细节

### 399 除法求值
bfs模拟加更新

### 406 Queue Reconstruction by Height
1. 按照身高升序，前面有几个人降序，找第几个空格插进去。（这样前面略过的空格就是站更高的（或者是同样身高更靠前的））
2. 按照身高降序，前面有几个人升序，从第一个位置往后走（有几个人），插进去。

重点：
vector的cmp函数
```
static bool cmp(v1, v2)
是否把a放前面
```

### 416 Partition Equal Subset Sum
1. 01背包，外循环什么东西，内循环从大到小。
推一下会不会用到自己

### 437 Path Sum III
维护当前到根节点所有sum值。 有x-y = sum 查y=x-sum
### 438 Find All Anagrams in a String
滑动窗口

### 448 Find All Numbers Disappeared in an Array
1. 非常巧妙的思想，用是否把某个位置置为负数标记对应的值是否出现过。
2. 用绝对值保证数值本身的含义可以被复原。

### 461 Hamming Distance
1. lowerbit返回的是最后一位是1的10000。减之

### 494 Target Sum
1. 首先有S的正负不影响，全部取正/负就可以了。为了避免爆到负数指标，先对S取abs
2. 把等式里的负数挪到S那边，变成了把一个数组平均分成两份的问题。
3. 变成了01背包的策略数量问题。dp[j] += dp[j-i]
4. 最后dp除了个2，因为S的正负（或者说算在哪一边）都算进去了，但只要一种。
可能有点复杂。可能不把S加进数组直接求和会好理解。

### 538 Convert BST to Greater Tree
dfs 顺序问题

### 543 Diameter of Binary Tree
easy dfs

### 560 Subarray Sum Equals K
和之前树上和一个道理

### 581 Shortest Unsorted Continuous Subarray
逻辑有点复杂。。。
先走过所有的递增数，在非递增开始的地方找到最小值。
然后在前面的递增序列里找到第一个大于他的值。这里就是左端点。
找大于可以二分，还没写，tooto
同理右端点

### 617 Merge Two Binary Trees
easy dfs

### 621 Task Scheduler
idea!
最多的是瓶颈

### 647 Palindromic Substrings
1. dp，注意这种往里面缩的dp外层应该是长度啊啊啊
2. 反正都N2了不如直接干

### 739 
单调栈