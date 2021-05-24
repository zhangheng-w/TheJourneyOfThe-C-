### [剑指 Offer 06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

题目：剑指 Offer 06. 从尾到头打印链表  
难度：简单

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

~~~
输入：head = [1,3,2]
输出：[2,3,1]
~~~

限制：
0 <= 链表长度 <= 10000


### Solution ：

思路：

遍历一遍链表，反转数组

时间复杂度：O(n)  
空间复杂度：O(n)

~~~cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* Index = head;
        vector<int> re;
        while(Index) {
            re.push_back(Index->val);
            Index = Index->next;
        }
        reverse(re.begin(), re.end());
        return re;
    }
};
~~~