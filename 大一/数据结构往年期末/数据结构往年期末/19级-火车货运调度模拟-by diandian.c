//
//  main.c
//  货运调度
//
//  Created by 点点 on 2022/6/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node1{
    char pos[22];
    int distance;
}destination[52];
struct Node2{
    char id[5];
    char disname[22];
}carA[52], carB[52], carC[52];
struct Node3{
    char name[22];
    int dis;
}further[52];
int comp(const void * p1, const void * p2){
    struct Node3 *a = (struct Node3*)p1;
    struct Node3 *b = (struct Node3*)p2;
    return b->dis - a->dis;
}
int topA=0, topB=0, topC=0, cnt=0, order=0;
int main() {
    int i, j, des_num, car_num;
    scanf("%d", &des_num);
    for(i=0;i<des_num;i++)
        scanf("%s %d", destination[i].pos, &destination[i].distance);
    scanf("%d", &car_num);
    for(i=0;i<car_num;i++){
        scanf("%s %s", carA[i].id, carA[i].disname);
        for(j=0;j<des_num;j++){
            if(!strcmp(carA[i].disname,destination[j].pos)){
                strcpy(further[i].name,destination[j].pos);
                further[i].dis = destination[j].distance;
                break;
            }
        }
    }
    qsort(further,car_num,sizeof(struct Node3),comp);
    for(i=0;i<car_num;i++)
        printf("%s ", further[i].name);
    printf("\n");
    topA = car_num - 1;
    while(topA>=0)
        carB[topB++] = carA[topA--];
    topA++;
    topB--;
    while(order != car_num){
        while(topB>=0&&strcmp(carB[topB].disname,further[order].name)!=0){
            carA[topA++]=carB[topB--];
            cnt++;
        }
        carA[topA++]=carB[topB--];
        cnt++;
        topA--;
        topB++;
        if(topA==order){
            topA++;
            topB--;
        }
        else{
            carC[topC]=carA[topA--];
            while(topA>=order)
                carB[topB++]=carA[topA--];
            topA++;
            topB--;
            carA[topA++]=carC[topC];
            cnt++;
        }
            order++;
    }
    for(i=0;i<car_num;i++)
        printf("%s ", carA[i].id);
    printf("\n%d\n", cnt);
    return 0;
}
