//
//  main.c
//  服务优化
//
//  Created by 点点 on 2022/4/30.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int name;
    struct Node *latter[3];
}Tree, *Treeptr;
Tree airport_branch[5000];
struct AirNode{
    int name;
    int liuliang;
}airport_liuliang[5000];
int after[5000], gatenumber;
int comp(const void * a, const void * b){
    struct AirNode *p1 = (struct AirNode*)a;
    struct AirNode *p2 = (struct AirNode*)b;
    if(p1->liuliang!=p2->liuliang)
        return p2->liuliang - p1->liuliang;
    else
        return p1->name - p2->name;
}
void order(Treeptr t){
    Treeptr queue[5000], p;
    int front=0, rear=0;
    queue[0] = t;
    while(front<=rear){
        p=queue[front++];
        if(p->latter[0]==NULL&&p->latter[1]==NULL&&p->latter[2]==NULL){
            after[gatenumber++] = p->name;
        }
        if(p->latter[0]!=NULL)
            queue[++rear]=p->latter[0];
        if(p->latter[1]!=NULL)
            queue[++rear]=p->latter[1];
        if(p->latter[2]!=NULL)
            queue[++rear]=p->latter[2];
    }
}
int main() {
    int i, r, s;
    while(1){
        scanf("%d", &r);
        if(r==-1)
            break;
        else{
            airport_branch[r].name=r;
            i=0;
            while(1){
                scanf("%d", &s);
                if(s==-1)
                    break;
                else{
                    airport_branch[r].latter[i]=(Tree*)malloc(sizeof(Tree));
                    airport_branch[s].name=s;
                    airport_branch[r].latter[i++]=&airport_branch[s];
                }
            }
        }
    }
    order(&airport_branch[100]);
    for(i=0;i<gatenumber;i++){
        scanf("%d %d", &airport_liuliang[i].name, &airport_liuliang[i].liuliang);
    }
    qsort(airport_liuliang,gatenumber,sizeof(struct AirNode),comp);
    for(i=0;i<gatenumber;i++)
        printf("%d->%d\n", airport_liuliang[i].name, after[i]);
    return 0;
}
