/*
 * Created by weyiua on 2021/9/16.
 */

#include "_Graph.h"

void test() {
    //有向图
    int p[7][7] = {
            1, 1, 1, 1, 0, 0, 0,
            0, 1, 0, 1, 1, 0, 0,
            0, 0, 1, 0, 0, 1, 0,
            0, 0, 1, 1, 0, 1, 1,
            0, 0, 0, 1, 1, 0, 1,
            0, 0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1, 1
    };
    topSortGraph(&p[0][0], 7);
    cout << endl;

    //有向图
    int t[7][7] = {
            1, 1, 0, 1, 0, 0, 0,
            0, 1, 0, 1, 1, 0, 0,
            1, 0, 1, 0, 0, 1, 0,
            0, 0, 1, 1, 1, 1, 1,
            0, 0, 0, 0, 1, 0, 1,
            0, 0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1, 1
    };
    unweightedShortPath(&t[0][0], 7, 3);
    cout << endl;

    //有向图
    int weightedP[7][7] = {
            1, 2, 0, 1, 0, 0, 0,
            0, 1, 0, 3, 10, 0, 0,
            4, 0, 1, 0, 0, 5, 0,
            0, 0, 2, 1, 2, 8, 4,
            0, 0, 0, 0, 1, 0, 6,
            0, 0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1, 1
    };
    weightedShortPath(&weightedP[0][0], 7, 1);
    cout << endl;


    //无向图 邻接表存储
    //对称的
    // a -> b == b -> a
    int primP[7][7] = {
            1, 2,  4, 1, 0,  0, 0,
            2, 1,  0, 3, 10, 0, 0,
            4, 0,  1, 2, 0,  5, 0,
            1, 3,  2, 1, 7,  8, 4,
            0, 10, 0, 7, 1,  0, 6,
            0, 0,  5, 8, 0,  1, 1,
            0, 0,  0, 4, 6,  1, 1
    };
    graphPrim(&primP[0][0], 7, 1);
    kruskal(&primP[0][0], 7);
}

int main(int agrc, const char *agrv[]) {
    test();

    return 0;
}

