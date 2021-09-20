/*
 * Created by weyiua on 2021/9/13.
 */

#ifndef _SORT_H
#define _SORT_H

#include <iostream>

//插入排序就像 斗地主理牌 一样插入
void InsertSort(int* p, int len) {
    for(int i = 1; i < len; ++i) {
        int temp = p[i];
        int j = i;
        for(; j > 0 && p[j-1] > temp; --j) {
            p[j] = p[j-1];
        }
        p[j] = temp;
    }
}


//shell排序 就是多个插入排序 通过区间排序 直到array有序
//也叫缩小增量排序 增量就是区间范围
void ShellSort(int* p, int len) {
    int increment = 0;
    //划分区间
    for(int increment = len / 2; increment > 0; increment /= 2) {
        for(int i = 0; i < len; ++i) {
            int temp = p[i];
            int j = i;
            // j >= increment  防止数据越界
            for (; j >= increment; j -= increment) {
                if(p[j - increment] > temp) {
                    p[j] = p[j - increment];
                } else break; //前面的有序了 ？
            }
            //插入. 最后替换
            p[j] = temp;
        }
    }
}

//获取子节点的索引
#define LeftChild(i) (2 * (i) + 1)

//堆排序 一次遍历  即可以让堆顶最大或者最小
//就是一个树判断 比较父节点 和子节点的大小 并交换
void perUp(int* p, int left, int right) {
    int temp = p[left];
    int child = 0;
    for(temp; LeftChild(left) < right; left = child) {
        child = LeftChild(left);
        //判断是不是有两个儿子结点 取节点值大的 value
        if(child < right && p[child] < p[child + 1]) {
            ++child;
        }
        if(temp < p[child]) p[left] = p[child];
        else break;
    }
    //最后一个位置 替换当时首个位置的元素
    p[left] = temp;
}


//堆排序
void HeapSort(int* p, int len) {
    int i = 0;
    //第一次 将最大值交换到顶部
    for(int i = len / 2; i >= 0; --i) {
        perUp(p, i, len);
    }
    for(int i = len - 1; i > 0; --i) {
        //将堆顶 交换到最后一个位置
        int t = p[i];
        p[i] = p[0];
        p[0] = t;

        //堆的顺序已经改变 -> 将有序
        perUp(p, 0, i);
    }
}


//合并两个有序区间
void merge(int* p, int* temp, int lpos, int rpos, int rightEnd) {
    //俩个区间 [lpos, rpos-1] [rpos, rightEnd]
    int lEnd = rpos - 1;
    int tPos = lpos;
    int len = rightEnd - lpos + 1;

    //通过额外的空间将两个有序的合并
    while(lpos <= lEnd && rpos <= rightEnd) {
        if(p[lpos] < p[rpos]) {
            temp[tPos++] = p[lpos++];
        } else temp[tPos++] = p[rpos++];
    }
    while(lpos <= lEnd) {
        temp[tPos++] = p[lpos++];
    }
    while(rpos <= rightEnd) {
        temp[tPos++] = p[rpos++];
    }

    //将合并好的区间 复制到原数组
    for(int i = 0; i < len; ++i, --rightEnd) {
        temp[rightEnd] = p[rightEnd];
    }


}

//划分区间 然后合并
void MSort(int* p, int* temp, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        //划分区间 [left, mid] [mid + 1, right]
        MSort(p, temp, left, mid);
        MSort(p, temp, mid + 1, right);
        merge(p, temp, left, mid, right);
    }
}

//用了一个相同大小的额外空间
//先划分 然后解决 再合并 分治的思想 递归实现
void MergeSort(int* p, int len) {
    int* temp = new int[len];
    MSort(p, temp,0, len-1);
    delete temp;
}


void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

//快速排序
void quickPoint(int* p, int l, int r) {
    if(l > r) return ;
    int begin = l, end = r;
    //取中间的元素作为基准点
    int center = l + (r - l) / 2;
    //挖孔法
    swap(p[l], p[center]);
    int temp = p[l];
    while(l < r) {
        while(l < r && p[r] >= temp) --r;
        if(l < r) p[l++] = p[r];
        while(l < r && p[l] < temp) ++l;
        if(l < r) p[r--] = p[l];
    }
    p[l] = temp;
    quickPoint(p, begin, l -1);
    quickPoint(p, l + 1, end);
}



void QuickSort(int* p, int len) {
    quickPoint(p, 0, len-1);
}



#endif //_SORT_H
