/*
 * Created by weyiua on 2021/9/16.
 * 图论 graph
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


//拓扑排序 topsort 判断是否存在环路
//图 使用邻接表存储
//int[h][w]
//h = w;
//不断寻找入度为0的点 直到排序完成
//拓扑排序不是唯一的 有很多种排序的结果
void topSortGraph(int* p, int h) {
    //标记数组 判断该节点是不是已经排序过了的？
    int visited[h];
    memset(visited, 0, sizeof(visited));
    int sumInDegree[h];
    memset(sumInDegree, 0, sizeof(sumInDegree));
    //遍历整个数组 统计每个结点的出度入度 i -> j
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

//路径表
struct graphTable {
    int p; //点
    int len; //长度
    string s; //前面一个节点 就是上一个节点
    graphTable() : p(0), len(0), s("-1") {}

};

/*
 * Dijkstra算法 最短路径算法
 * 就是广度遍历 + 贪心
 * 每次都选择最短路径
 */

//无权有向图 和有权图一样，就把所有的权为1
//每次都寻找当前最小的权和，就是到那个点的最短路径
void unweightedShortPath(int* p, int h, int begin) {
    --begin;
    if(begin < 0 || begin >= h) return ; //没有这个点， 不可能为起点
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
                //另外的路径比原先的路径长 跳过
                if(table[i].len != 0 && table[t].len + 1 > table[i].len) continue;
                table[i].len = table[t].len + 1;
                table[i].s = "->" + to_string(t + 1);
            }
        }
        int temp = 0x3f3f3f3f;
        int index = -0x3f3f3f3f;
        //寻找当前最短路径的点
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

//带权值的最短路径算法 Dijkstra
void weightedShortPath(int* p, int h, int begin) {
    --begin;
    if(begin < 0 || begin >= h) return ; //没有这个点， 不可能为起点
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
            //当前权值 t -> i;
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


//最小生成树算法 无向图
//prim算法
//无向图中 判断每个结点的相邻的 取最小权值的那个边，表示这个节点连接了
void graphPrim(int* p, int h, int begin) {
    --begin;
    if(begin < 0 || begin >= h) return ; //没有这个点， 不可能为起点
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
            //权值
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

//Kruskal算法也是生成最小树的
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
        cout << f + 1 << "-" << s + 1 << "权值为:" << p.first << endl;
        iset.emplace(f);
        iset.emplace(s);

    }

}



#endif //_GRAPH_H
