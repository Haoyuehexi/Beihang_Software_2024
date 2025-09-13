//
//  main.c
//  空闲空间合并
//
//  Created by 点点 on 2022/6/7.
//

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int left;
    int right;
}space[102];
int comp(const void * p1, const void * p2){
    struct Node *a = (struct Node*)p1;
    struct Node *b = (struct Node*)p2;
    return a->left - b->left;
}
int main() {
    int i, j, n;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d %d", &space[i].left, &space[i].right);
    qsort(space,n,sizeof(struct Node),comp);
    for(i=0;i<n;){
        for(j=i+1;j<n&&space[j].left==space[j-1].right+1;j++);
        printf("%d %d\n", space[i].left, space[j-1].right);
        i=j;
    }
    return 0;
}
