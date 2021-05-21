### [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)


题目：剑指 Offer 09. 用两个栈实现队列
难度：简单

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：

~~~
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
~~~

示例 2：
~~~
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
~~~

提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用


### Solution ：

思路：

* 两个栈
维护两个栈，一个栈添加元素一个栈删除元素

当deleteStack == null  insertStack的所有元素进入deleteStack

~~~cpp
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        insertStack.push(value);
    }
    
    int deleteHead() {
        if(insertStack.empty() && deleteStack.empty()) return -1;
        if(deleteStack.empty()) {
            while(!insertStack.empty()) {
                deleteStack.push(insertStack.top());
                insertStack.pop();
            }
        }
        int reValue = deleteStack.top();
        deleteStack.pop();
        return reValue;
    }

private:
    stack<int> insertStack;
    stack<int> deleteStack;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
~~~
