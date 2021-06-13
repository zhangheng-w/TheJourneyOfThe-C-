### [剑指 Offer 03. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

题目：剑指 Offer 03. 数组中重复的数字
难度：简单

找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

```
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
```

限制：

2 <= n <= 100000

### Solution ：

思路：

* 哈希+遍历

使用undered_set存放元素，`if`不能插入，即表示容器中已有元素，即重复元素返回`true`

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> setnums;
        int re = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(setnums.insert(nums[i]).second == false ) {
                re = nums[i];
                break;
            }
        }
        return re;
    }
};
```

* 排序+遍历

`sort`数组，遍历的同时查找相同元素nums[i] = nums[i+1] `return true;`

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; ++i) {
            if(nums[i] == nums[i+1]) {
                return nums[i];
            }
        }
        return 0;
    }
};
```