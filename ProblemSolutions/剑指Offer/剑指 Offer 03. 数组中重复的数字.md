### [��ָ Offer 03. �������ظ�������](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

��Ŀ����ָ Offer 03. �������ظ�������
�Ѷȣ���

�ҳ��������ظ������֡�

��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�

ʾ�� 1��

```
���룺
[2, 3, 1, 0, 2, 5, 3]
�����2 �� 3 
```

���ƣ�

2 <= n <= 100000

### Solution ��

˼·��

* ��ϣ+����

ʹ��undered_set���Ԫ�أ�`if`���ܲ��룬����ʾ����������Ԫ�أ����ظ�Ԫ�ط���`true`

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

* ����+����

`sort`���飬������ͬʱ������ͬԪ��nums[i] = nums[i+1] `return true;`

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