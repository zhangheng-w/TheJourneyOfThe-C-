### [剑指 Offer 24. 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

题目：剑指 Offer 24. 反转链表
难度：简单

定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 
示例:
~~~
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
~~~

限制：

0 <= 节点个数 <= 5000

 
### Solution ：

思路：

双指针+头插法+迭代

head->null  ->  head->1->null ->  head->2->1->null

时间复杂度：O(n)  
空间复杂度：O(1)

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
    ListNode* reverseList(ListNode* head) {
        ListNode *re = new ListNode(-1);
        ListNode *temp = nullptr;
        while(head) {
            temp = head;
            head = head->next;
            temp->next = re->next;
            re->next = temp;
        }
        return re->next;
    }
};
~~~

递归+尾插法

时间复杂度：O(n)，其中n是链表的长度。需要对链表的每个节点进行反转操作。  
空间复杂度：O(n)，其中n是链表的长度。空间复杂度主要取决于递归调用的栈空间，最多为n层。

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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode *re =  reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return re;
    }
};
~~~

