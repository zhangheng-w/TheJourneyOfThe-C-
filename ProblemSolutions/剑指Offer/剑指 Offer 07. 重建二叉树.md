### [��ָ Offer 07. �ؽ�������](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)

��Ŀ����ָ Offer 07. �ؽ�������
�Ѷȣ��е�

����ĳ��������ǰ���������������Ľ�������ؽ��ö����������������ǰ���������������Ľ���ж������ظ������֡�

 
���磬����
```
ǰ����� preorder = [3,9,20,15,7]
������� inorder = [9,3,15,20,7]
```

�������µĶ�������

```
    3
   / \
  9  20
    /  \
   15   7
```

���ƣ�

0 <= �ڵ���� <= 5000

### Solution ��

˼·��

* �ݹ�

ǰ����� - ������
������� - �����

��ǰ������ɵ�root��Ȼ���������Ѱ��root��ͬ��ֵ���ɵ�left�ķ�Χ��right�ķ�Χ
���������ݹ鹹����
���������ݹ鹹����

ʱ�临�Ӷȣ�O(n)��n�������Ľ�����  
�ռ临�Ӷȣ�O(n)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* orderToTree(vector<int>& preorder, vector<int>& inorder, int pLeft, int pRight, int iLeft, int iRight) {
        if(pLeft > pRight) return nullptr;
        int rootValue = preorder[pLeft];
        int iTemp = iLeft;
        while(iTemp <= iRight && inorder[iTemp] != rootValue) ++iTemp;
        TreeNode* root = new TreeNode(rootValue);
        root->left = orderToTree(preorder, inorder, pLeft+1, pLeft+iTemp-iLeft, iLeft, iTemp-1);
        root->right = orderToTree(preorder, inorder, pLeft+iTemp-iLeft+1, pRight, iTemp+1, iRight);
        return root;
    }

    /*
    �ݹ�
    ǰ��[root, [left], [right]]
    ����[left, [root], [right]]
    ����ǰ��,��ȡroot, �ݹ���������������
    */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return orderToTree(preorder, inorder, 0, len-1, 0, len-1);
    }
};
```


* ����

```cpp
����
```