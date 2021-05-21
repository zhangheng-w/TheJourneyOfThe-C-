### [剑指 Offer 05. 替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)

题目：剑指 Offer 05. 替换空格
难度：简单

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：
~~~
输入：s = "We are happy."
输出："We%20are%20happy."
~~~

限制：

0 <= s 的长度 <= 10000


### Solution ：

思路：

  
* 遍历字符串,把非' '添加到返回值,否则添加"%20"

时间复杂度：O(n)  遍历一遍  
空间复杂度：O(n)

~~~cpp
class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty()) return "";
        string re = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') re += "%20";
            else re += s[i];
        }
        return re;
    }
};
~~~


* 遍历整个字符串，当字符为' '时替换为"%20"
切割字符串 strsub(0 - spaceIndex-1) + "%20" + strsub(spaceIndex+1 - len)

时间复杂度：O(n)  遍历一遍  
空间复杂度：O(n)

~~~cpp
class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty()) return "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') {
                s = s.substr(0, i) + "%20" + s.substr(i+1, s.size() - i + 1);
            }
        }
        return s;
    }
};
~~~

* 双指针--->字符串原地修改，实际上就是吧字符串容量扩大，然后循环

时间复杂度：O(n)  遍历一遍  
空间复杂度：O(1) 

~~~cpp
class Solution {
public:
    string replaceSpace(string s) {
        int len = s.size();
        int count = 0;
        for(int i = 0; i < len; ++i) {
            if(s[i] == ' ') ++count;
        }
        //扩大s的容量大小
        s.resize(len + 2 * count);
        //双指针，倒序
        for(int i = len-1, j = s.size()-1; i < j; --i, --j) {
            if(s[i] != ' ') {
                s[j] = s[i];
            }else{
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};
~~~

