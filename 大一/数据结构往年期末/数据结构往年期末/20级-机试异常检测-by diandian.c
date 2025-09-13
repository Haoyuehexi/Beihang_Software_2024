//
//  main.c
//  异常检测
//
//  Created by 点点 on 2022/6/7.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    int id;
    char name[16];
    int machine;
    char time[7];
}loginfo[205];
int comp(const void * p1, const void * p2){
    struct Node *a = (struct Node*)p1;
    struct Node *b = (struct Node*)p2;
    if(a->id!=b->id)
        return a->id - b->id;
    else
        return strcmp(a->time,b->time);
}
int main() {
    int i, j, n, flag;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d %s %d %s", &loginfo[i].id, loginfo[i].name, &loginfo[i].machine, loginfo[i].time);
    qsort(loginfo,n,sizeof(struct Node),comp);
    for(i=0;i<n;){
        flag=0;
        for(j=i+1;j<n&&loginfo[j].id==loginfo[i].id;j++){
            if(loginfo[j].machine!=loginfo[i].machine){
                if(flag==0){
                    printf("%d %s\n", loginfo[i].id, loginfo[i].name);
                    flag=1;
                }
            }
        }
        i=j;
    }
    return 0;
}
