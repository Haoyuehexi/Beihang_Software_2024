//
//  main.c
//  函数调用
//
//  Created by 点点 on 2022/6/12.
//

#include <stdio.h>
#include <string.h>
struct function{
    char name[21];
    char division[11][21];
    int count;
}information[101];
int top=-1, total=0;
int main(){
    int i, j, op;
    char stack[201][21]={0}, temp[21]={0};
    for(i=0;i<101;i++)
        information[i].count=0;
    while(1){
        scanf("%d", &op);
        if(op==8){
            scanf("%s", temp);
            for(i=0;i<total;i++){
                if(strcmp(information[i].name,temp)==0)
                    break;
            }
            if(i==total)
                strcpy(information[total++].name,temp);
            if(top>=0){
                for(i=0;i<total;i++){
                    if(strcmp(information[i].name,stack[top])==0)
                        break;
                }
                for(j=0;j<information[i].count;j++){
                    if(strcmp(information[i].division[j],temp)==0)
                        break;
                }
                if(j==information[i].count){
                    strcpy(information[i].division[j],temp);
                    information[i].count++;
                }
            }
            strcpy(stack[++top],temp);
        }
        else
            top--;
        if(top==-1)
            break;
    }
    for(i=0;i<total;i++){
        if(information[i].count>0){
            printf("%s:", information[i].name);
            for(j=0;j<information[i].count-1;j++)
                printf("%s,", information[i].division[j]);
            printf("%s\n", information[i].division[j]);
        }
    }
    return 0;
}

