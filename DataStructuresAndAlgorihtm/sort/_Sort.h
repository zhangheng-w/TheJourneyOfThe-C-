/*
 * Created by weyiua on 2021/9/13.
 */

#ifndef _SORT_H
#define _SORT_H

#include <iostream>

//����������� ���������� һ������
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


//shell���� ���Ƕ���������� ͨ���������� ֱ��array����
//Ҳ����С�������� �����������䷶Χ
void ShellSort(int* p, int len) {
    int increment = 0;
    //��������
    for(int increment = len / 2; increment > 0; increment /= 2) {
        for(int i = 0; i < len; ++i) {
            int temp = p[i];
            int j = i;
            // j >= increment  ��ֹ����Խ��
            for (; j >= increment; j -= increment) {
                if(p[j - increment] > temp) {
                    p[j] = p[j - increment];
                } else break; //ǰ��������� ��
            }
            //����. ����滻
            p[j] = temp;
        }
    }
}

//��ȡ�ӽڵ������
#define LeftChild(i) (2 * (i) + 1)

//������ һ�α���  �������öѶ���������С
//����һ�����ж� �Ƚϸ��ڵ� ���ӽڵ�Ĵ�С ������
void perUp(int* p, int left, int right) {
    int temp = p[left];
    int child = 0;
    for(temp; LeftChild(left) < right; left = child) {
        child = LeftChild(left);
        //�ж��ǲ������������ӽ�� ȡ�ڵ�ֵ��� value
        if(child < right && p[child] < p[child + 1]) {
            ++child;
        }
        if(temp < p[child]) p[left] = p[child];
        else break;
    }
    //���һ��λ�� �滻��ʱ�׸�λ�õ�Ԫ��
    p[left] = temp;
}


//������
void HeapSort(int* p, int len) {
    int i = 0;
    //��һ�� �����ֵ����������
    for(int i = len / 2; i >= 0; --i) {
        perUp(p, i, len);
    }
    for(int i = len - 1; i > 0; --i) {
        //���Ѷ� ���������һ��λ��
        int t = p[i];
        p[i] = p[0];
        p[0] = t;

        //�ѵ�˳���Ѿ��ı� -> ������
        perUp(p, 0, i);
    }
}


//�ϲ�������������
void merge(int* p, int* temp, int lpos, int rpos, int rightEnd) {
    //�������� [lpos, rpos-1] [rpos, rightEnd]
    int lEnd = rpos - 1;
    int tPos = lpos;
    int len = rightEnd - lpos + 1;

    //ͨ������Ŀռ佫��������ĺϲ�
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

    //���ϲ��õ����� ���Ƶ�ԭ����
    for(int i = 0; i < len; ++i, --rightEnd) {
        temp[rightEnd] = p[rightEnd];
    }


}

//�������� Ȼ��ϲ�
void MSort(int* p, int* temp, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        //�������� [left, mid] [mid + 1, right]
        MSort(p, temp, left, mid);
        MSort(p, temp, mid + 1, right);
        merge(p, temp, left, mid, right);
    }
}

//����һ����ͬ��С�Ķ���ռ�
//�Ȼ��� Ȼ���� �ٺϲ� ���ε�˼�� �ݹ�ʵ��
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

//��������
void quickPoint(int* p, int l, int r) {
    if(l > r) return ;
    int begin = l, end = r;
    //ȡ�м��Ԫ����Ϊ��׼��
    int center = l + (r - l) / 2;
    //�ڿ׷�
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
