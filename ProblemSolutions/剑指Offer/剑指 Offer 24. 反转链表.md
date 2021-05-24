### [��ָ Offer 24. ��ת����](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

��Ŀ����ָ Offer 24. ��ת����
�Ѷȣ���

����һ������������һ�������ͷ�ڵ㣬��ת�����������ת�������ͷ�ڵ㡣

 
ʾ��:
~~~
����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL
~~~

���ƣ�

0 <= �ڵ���� <= 5000

 
### Solution ��

˼·��

˫ָ��+ͷ�巨+����

head->null  ->  head->1->null ->  head->2->1->null

ʱ�临�Ӷȣ�O(n)  
�ռ临�Ӷȣ�O(1)

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

�ݹ�+β�巨

ʱ�临�Ӷȣ�O(n)������n������ĳ��ȡ���Ҫ�������ÿ���ڵ���з�ת������  
�ռ临�Ӷȣ�O(n)������n������ĳ��ȡ��ռ临�Ӷ���Ҫȡ���ڵݹ���õ�ջ�ռ䣬���Ϊn�㡣

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

