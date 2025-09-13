//
//  main.c
//  在线时间
//
//  Created by 点点 on 2022/6/8.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    char name[22];
    int id;
    int time;
}student[102];
int comp(const void * p1, const void * p2){
    struct Node* a = (struct Node*)p1;
    struct Node* b = (struct Node*)p2;
    if(a->time!=b->time)
        return a->time - b->time;
    else
        return a->id - b->id;
}
int main() {
    int i, j, k=0, n, idt, timet, flag;
    char namet[22]={0};
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%s %d %d", namet, &idt, &timet);
        flag=0;
        for(j=0;j<k;j++){
            if(student[j].id==idt){
                student[j].time += timet;
                flag=1;
                break;
            }
        }
        if(flag==0){
            student[k].time = timet;
            student[k].id = idt;
            strcpy(student[k].name,namet);
            k++;
        }
    }
    qsort(student,k,sizeof(struct Node),comp);
    for(i=0;i<k;i++)
        printf("%s %d %d\n",student[i].name,student[i].id,student[i].time);
    return 0;
}
