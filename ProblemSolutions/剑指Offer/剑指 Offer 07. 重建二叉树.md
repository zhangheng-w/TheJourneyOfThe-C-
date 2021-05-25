### [剑指 Offer 07. 重建二叉树](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)

题目：剑指 Offer 07. 重建二叉树
难度：中等

输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 
例如，给出
```
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
```

返回如下的二叉树：

```
    3
   / \
  9  20
    /  \
   15   7
```

限制：

0 <= 节点个数 <= 5000

### Solution ：

思路：

* 递归

前序遍历 - 根左右
中序遍历 - 左根右

以前序遍历可得root，然后遍历中序寻找root相同的值，可得left的范围和right的范围
在左子树递归构建树
在右子树递归构建树

时间复杂度：O(n)，n就是树的结点个数  
空间复杂度：O(n)

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
    递归
    前序[root, [left], [right]]
    中序[left, [root], [right]]
    根据前序,获取root, 递归左子树和右子树
    */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return orderToTree(preorder, inorder, 0, len-1, 0, len-1);
    }
};
```


* 迭代

```cpp
暂无
```