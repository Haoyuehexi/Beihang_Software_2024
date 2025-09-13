//
//  main.c
//  查找同名文件
//
//  Created by 点点 on 2022/6/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node1{
    char name[22];
    int type;
    int date;
    int cnt;
    struct Node1 *list[101];
    struct Node1 *parent;
}files[10001];
struct Node1* root;
int culcu=0;
char target[22]={0};
struct Node2{
    struct Node1* find;
    int depth;
}results[2001];
void dfs(struct Node1 * a, int deep){
    int i;
    if(a->type==0){
        if(strcmp(a->name,target)==0){
            results[culcu].find = a;
            results[culcu].depth = deep;
            culcu++;
        }
        return;
    }
    else{
        for(i=0;i<a->cnt;i++)
            dfs(a->list[i],deep+1);
    }
}
int comp(const void * p1, const void * p2){
    struct Node2* a = (struct Node2*)p1;
    struct Node2* b = (struct Node2*)p2;
    if(a->find->date != b->find->date)
        return b->find->date - a->find->date;
    else
        return a->depth - b->depth;
}
void print(struct Node1 * a){
    if(a->parent!=NULL)
        print(a->parent);
    else{
        printf("%s:",a->name);
        return;
    }
    printf("\\%s",a->name);
    if(a->type==0)
        printf("\n");
    return;
}
int main() {
    FILE *in = fopen("files.txt","r");
    int i, j, n;
    for(i=0;i<10001;i++){
        files[i].parent=NULL;
        files[i].cnt=0;
    }
    char temp[22]={0};
    scanf("%d %s", &n, target);
    for(i=0;i<n;i++){
        fscanf(in,"%s %s %d %d",files[i].name,temp,&files[i].type,&files[i].date);
        if(strcmp(temp,"-")==0)
            root = &files[i];
        else{
            for(j=0;j<i;j++){
                if(strcmp(temp,files[j].name)==0){
                    files[i].parent = (struct Node1*)malloc(sizeof(struct Node1));
                    files[i].parent = &files[j];
                    files[j].list[files[j].cnt++]=&files[i];
                    break;
                }
            }
        }
    }
    dfs(root,0);
    qsort(results,culcu,sizeof(struct Node2),comp);
    for(i=0;i<culcu;i++)
        print(results[i].find);
    return 0;
}
