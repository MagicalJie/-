﻿#include <stdio.h>
#include "SString.h"    //**▲04 串**//
#include "GList-HT.h"   //**▲05 数组和广义表**//

// 求广义表深度（头尾链表存储表示）
int Algo_5_30_1(GList L);


int main(int argc, char* argv[]) {
    GList L;
    char* s = (char*)"((),(e),(b,c,d))";
    SString S;

    printf("创建广义表 L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGList(L);

    printf("广义表深度为： %d\n", Algo_5_30_1(L));

    return 0;
}


// 求广义表深度（头尾链表存储表示）
int Algo_5_30_1(GList L) {
    int m, n;

    if (L == NULL) {
        return 1;   // 空表深度为1
    }

    if (L->tag == Atom) {
        return 0;   // 原子深度为0
    }

    m = Algo_5_30_1(L->Node.ptr.hp) + 1;
    n = Algo_5_30_1(L->Node.ptr.tp);

    return m > n ? m : n;
}