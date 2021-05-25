### [剑指 Offer 10- I. 斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)


题目：剑指 Offer 10- I. 斐波那契数列
难度：简单

写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

```
输入：n = 2
输出：1
```

示例 2：
```
输入：n = 5
输出：5
```

提示：

0 <= n <= 100


### Solution ：

思路：

* 递归

fib（n） = fib（n-1） + fib(n-2);  
递归会造成大量的重复递归

```cpp
class Solution {
public:
    const int MODT = 1000000007;
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        return (fib(n-1) + fib(n-2)) % MODT;
    }
};
```


* 递归+记忆化存储

`if`递归数组中的值有则返回，否则递归f（n）

```cpp
class Solution {
public:
    const int MODT = 1000000007;

    int fibv(vector<int> &nums, int n) {
        if(n-1 >= 0 && nums[n-1] == 0) nums[n-1] = fibv(nums, n-1);
        if(n-2 >= 0 && nums[n-2] == 0) nums[n-2] = fibv(nums, n-2);
        if(n > 1 && nums[n] == 0) nums[n] = (nums[n-1] + nums[n-2]) % MODT;
        return nums[n];
    }


    int fib(int n) {
        vector<int> nums(101, 0);
        nums[1] = 1;
        fibv(nums, n);

        for(int i : nums) cout << i << endl;

        return nums[n];
    }
}; 
```

* 双指针存储元素

```cpp
class Solution {
public:
    const int MODT = 1000000007;

    int fib(int n) {
        if(n < 2) return n;
        int first = 0, second = 1;
        int temp = 0;
        for(int i = 2; i <= n; ++i) {
            temp = (first + second) % MODT;
            first = second;
            second = temp;
        }
        return second;
    }
};
```


* 动态规划（dp）

```cpp
class Solution {
public:
    const int MODT = 1000000007;

    int fib(int n) {
        if(n < 2) return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i-2] ) % MODT;
        }
        return dp[n];
    }
};
```
