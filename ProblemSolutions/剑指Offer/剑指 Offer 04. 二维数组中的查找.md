### [��ָ Offer 04. ��ά�����еĲ���](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

��Ŀ����ָ Offer 04. ��ά�����еĲ���
�Ѷȣ��е�
��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������

ʾ��:
```
���о��� matrix ���£�

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
���� target = 5������ true��

���� target = 20������ false��
```

���ƣ�

0 <= n <= 1000  
0 <= m <= 1000

### Solution ��

˼·��

* ��������

˫ѭ�������������  
for����  
  for����  
    if����  

ʱ�临�Ӷȣ�O(n^2) ˫ѭ��  
�ռ临�Ӷȣ�O(1)

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

* ���Բ��� + ˫ָ��

��Ϊ���ҵ���������������

�����Ͻǿ�ʼ  
������������  
���ϵ���������  
ifС�� ���²���    
if���� �������  

ʱ�临�Ӷȣ�O(n*m)  
�ռ临�Ӷȣ�O(1)

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