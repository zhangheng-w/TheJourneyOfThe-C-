/*
 * Created by weyiua on 2021/9/16.
 * ͼ�� graph
 */

#ifndef _GRAPH_H
#define _GRAPH_H

#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;


//�������� topsort �ж��Ƿ���ڻ�·
//ͼ ʹ���ڽӱ�洢
//int[h][w]
//h = w;
//����Ѱ�����Ϊ0�ĵ� ֱ���������
//����������Ψһ�� �кܶ�������Ľ��
void topSortGraph(int* p, int h) {
    //������� �жϸýڵ��ǲ����Ѿ�������˵ģ�
    int visited[h];
    memset(visited, 0, sizeof(visited));
    int sumInDegree[h];
    memset(sumInDegree, 0, sizeof(sumInDegree));
    //������������ ͳ��ÿ�����ĳ������ i -> j
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < h; ++j) {
            if(i == j) continue;
            if(*(p + i * h + j) == 1) ++sumInDegree[j];
        }
    }

    /*for(int i : sumInDegree) cout << i << " ";
    cout << endl;*/
    queue<int> iqueue;
    for(int i = 0; i < h; ++i) {
        if(sumInDegree[i] == 0) {
            iqueue.push(i);
            visited[i] == 1;
        }
    }

    while(!iqueue.empty()) {
        int temp = iqueue.front();
        iqueue.pop();
        visited[temp] = 1;
        for(int i = 0; i < h; ++i) {
            if(*(p + temp * h + i) == 1 && visited[i] == 0) {
                --sumInDegree[i];
                if(sumInDegree[i] < 1) {
                    iqueue.push(i);
                    visited[i] = 1;
                }
            }
        }
        cout << temp + 1 << " ";
    }
}

//·����
struct graphTable {
    int p; //��
    int len; //����
    string s; //ǰ��һ���ڵ� ������һ���ڵ�
    graphTable() : p(0), len(0), s("-1") {}

};

/*
 * Dijkstra�㷨 ���·���㷨
 * ���ǹ�ȱ��� + ̰��
 * ÿ�ζ�ѡ�����·��
 */

//��Ȩ����ͼ ����Ȩͼһ�����Ͱ����е�ȨΪ1
//ÿ�ζ�Ѱ�ҵ�ǰ��С��Ȩ�ͣ����ǵ��Ǹ�������·��
void unweightedShortPath(int* p, int h, int begin) {
    --begin;
    if(begin < 0 || begin >= h) return ; //û������㣬 ������Ϊ���
    graphTable table[h];
    table[begin].p = 1;
    table[begin].len = 0;
    table[begin].s = "0";
    queue<int> ique;
    ique.push(begin);

    while(!ique.empty()) {
        int t = ique.front();
        ique.pop();
        for(int i = 0; i < h; ++i) {
            if(table[i].p != 1 && *(p + h * t + i) != 0 && i != t) {
                //�����·����ԭ�ȵ�·���� ����
                if(table[i].len != 0 && table[t].len + 1 > table[i].len) continue;
                table[i].len = table[t].len + 1;
                table[i].s = "->" + to_string(t + 1);
            }
        }
        int temp = 0x3f3f3f3f;
        int index = -0x3f3f3f3f;
        //Ѱ�ҵ�ǰ���·���ĵ�
        for(int i = 0; i < h; ++i) {
            if(temp > table[i].len && table[i].p != 1 && table[i].len != 0) {
                index = i;
                temp = table[i].len;
            }
        }
        if(index >= 0 && index < h) {
            table[index].p = 1;
            ique.push(index);
        }

    }
    for(int i = 0; i < h; ++i) {
        cout << "p" << i + 1 << ": " << table[i].p << " " << "len: " << table[i].len << " " << table[i].s << endl;
    }
}

//��Ȩֵ�����·���㷨 Dijkstra
void weightedShortPath(int* p, int h, int begin) {
    --begin;
    if(begin < 0 || begin >= h) return ; //û������㣬 ������Ϊ���
    graphTable table[h];
    table[begin].p = 1;
    table[begin].len = 0;
    table[begin].s = "0";
    queue<int> ique;
    ique.push(begin);

    while(!ique.empty()) {
        int t = ique.front();
        ique.pop();
        for(int i = 0; i < h; ++i) {
            //��ǰȨֵ t -> i;
            int value = *(p + h * t + i);
            if(table[i].p != 1 && value != 0 && i != t) {
                if(table[i].len != 0 && table[t].len + value > table[i].len) continue;
                table[i].len = table[t].len + value;
                table[i].s = "->" + to_string(t + 1);
            }
        }

        int index = -0x3f3f3f3f;
        int temp = 0x3f3f3f3f;
        for(int i = 0; i < h; ++i) {
            if(temp > table[i].len && table[i].p != 1 && table[i].len != 0) {
                index = i;
                temp = table[i].len;
            }
        }
        if(index >= 0 && index < h) {
            table[index].p = 1;
            ique.push(index);
        }
    }
    for(int i = 0; i < h; ++i) {
        cout << "p" << i + 1 << ": " << table[i].p << " " << "len: " << table[i].len << " " << table[i].s << endl;
    }
}


//��С�������㷨 ����ͼ
//prim�㷨
//����ͼ�� �ж�ÿ���������ڵ� ȡ��СȨֵ���Ǹ��ߣ���ʾ����ڵ�������
void graphPrim(int* p, int h, int begin) {
    --begin;
    if(begin < 0 || begin >= h) return ; //û������㣬 ������Ϊ���
    graphTable table[h];
    table[begin].p = 1;
    table[begin].len = 0;
    table[begin].s = "0";
    queue<int> ique;
    ique.push(begin);

    while(!ique.empty()) {

        int t = ique.front();
        ique.pop();
        for(int i = 0; i < h; ++i) {
            //Ȩֵ
            int value = *(p + h * t + i);
            if(table[i].p != 1 && value != 0 && i != t) {
                if(table[i].len != 0 && value > table[i].len) continue;
                table[i].len = value;
                table[i].s = "->" + to_string(t + 1);
            }
        }

        int index = -0x3f3f3f3f;
        int temp = 0x3f3f3f3f;
        for(int i = 0; i < h; ++i) {
            if(temp > table[i].len && table[i].p != 1 && table[i].len != 0) {
                index = i;
                temp = table[i].len;
            }
        }

        if(index >= 0 && index < h) {
            table[index].p = 1;
            ique.push(index);
        }
    }
    for(int i = 0; i < h; ++i) {
        cout << "p" << i + 1 << ": " << table[i].p << " " << "len: " << table[i].len << " " << table[i].s << endl;
    }
}

//Kruskal�㷨Ҳ��������С����
void kruskal(int* p, int h) { //err ????
    vector<pair<int, pair<int, int> > > ivec;
    for(int i = 0; i < h; ++i) {
        for(int j = i + 1; j < h; ++j){
            if(*(p + i * h + j) != 0) {
                ivec.emplace_back(make_pair(*(p + i * h + j), make_pair(i, j)));
            }
        }
    }
    sort(ivec.begin(), ivec.end());
    set<int> iset;
    for(auto p : ivec) {
        auto& [f, s] = p.second;
        //if(iset.count(f) && iset.count(s)) continue;
        cout << f + 1 << "-" << s + 1 << "ȨֵΪ:" << p.first << endl;
        iset.emplace(f);
        iset.emplace(s);

    }

}



#endif //_GRAPH_H
