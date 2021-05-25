### [剑指 Offer 04. 二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

题目：剑指 Offer 04. 二维数组中的查找
难度：中等
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:
```
现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。
```

限制：

0 <= n <= 1000  
0 <= m <= 1000

### Solution ：

思路：

* 暴力查找

双循环遍历数组查找  
for（）  
  for（）  
    if（）  

时间复杂度：O(n^2) 双循环  
空间复杂度：O(1)

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int len = matrix.size(), wight = matrix[0].size();
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < wight; ++j) {
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};
```

* 线性查找 + 双指针

因为查找的数组是相对有序的

从右上角开始  
从左到右是正序  
从上到下是正序  
if小于 向下查找    
if大于 向左查找  

时间复杂度：O(n*m)  
空间复杂度：O(1)

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int len = matrix.size()-1, wight = matrix[0].size()-1;
        int index = 0;
        while(index <= len && 0 <= wight) {
            if(matrix[index][wight] == target) return true;
            else if(matrix[index][wight] > target) --wight;
            else ++index;
        }
        return false;
    }
};
```