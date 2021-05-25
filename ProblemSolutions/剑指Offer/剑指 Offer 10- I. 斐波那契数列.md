### [��ָ Offer 10- I. 쳲���������](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)


��Ŀ����ָ Offer 10- I. 쳲���������
�Ѷȣ���

дһ������������ n ����쳲�������Fibonacci�����еĵ� n ��� F(N)����쳲��������еĶ������£�

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), ���� N > 1.
쳲����������� 0 �� 1 ��ʼ��֮���쳲�������������֮ǰ��������Ӷ��ó���

����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��

ʾ�� 1��

```
���룺n = 2
�����1
```

ʾ�� 2��
```
���룺n = 5
�����5
```

��ʾ��

0 <= n <= 100


### Solution ��

˼·��

* �ݹ�

fib��n�� = fib��n-1�� + fib(n-2);  
�ݹ����ɴ������ظ��ݹ�

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


* �ݹ�+���仯�洢

`if`�ݹ������е�ֵ���򷵻أ�����ݹ�f��n��

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

* ˫ָ��洢Ԫ��

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


* ��̬�滮��dp��

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
