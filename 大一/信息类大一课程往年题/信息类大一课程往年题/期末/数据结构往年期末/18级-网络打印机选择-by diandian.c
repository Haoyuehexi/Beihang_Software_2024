//
//  main.c
//  网络打印机选择
//
//  Created by 点点 on 2022/6/9.
//

#include <stdio.h>
struct Node{
    int name;
    int judge;
    int flag;
    struct Node *latter[8];
    struct Node *parent;
}devices[301];
int print[301]={0}, print_flag=0, find[301][301]={0,0}, aim[301]={0};
void pre_order(struct Node * t){
    int i;
    if(t!=NULL){
        if(t->judge==2)
            print[print_flag++]=t->name;
        for(i=0;i<8;i++){
            if(t->latter[i]!=NULL)
                pre_order(t->latter[i]);
        }
    }
}
int main() {
    FILE *in = fopen("in.txt","r");
    int i, j=0, k, p, q=0, n, target, id, pid, type, cid, flag, path[301]={0}, min=302;
    for(i=0;i<301;i++)
        devices[i].flag=0;
    scanf("%d %d", &n, &target);
    fscanf(in,"%d %d %d %d",&id,&pid,&type,&cid);
    devices[id].name=id;
    devices[id].judge=type;
    for(i=0;i<n-1;i++){
        fscanf(in,"%d %d %d %d",&id,&pid,&type,&cid);
        devices[id].name=id;
        devices[id].judge=type;
        devices[id].parent=&devices[pid];
        devices[pid].latter[cid]=&devices[id];
    }
    pre_order(&devices[0]);
    aim[0]=(devices[target].parent)->name;
    while(1){
        j++;
        aim[j]=(devices[aim[j-1]].parent)->name;
        if(aim[j]==0){
            k=j;
            break;
        }
    }
    for(i=0;i<301;i++){
        if(print[i]!=0){
            j=0;
            while(1){
                flag=0;
                if(j==0)
                    find[i][j]=(devices[print[i]].parent)->name;
                else
                    find[i][j]=(devices[find[i][j-1]].parent)->name;
                for(p=0;p<k+1;p++){
                    if(find[i][j]==aim[p]){
                        flag=1;
                        for(q=p-1;q>=0;q--){
                            find[i][++j]=aim[q];
                        }
                        path[i]=j+1;
                        break;
                    }
                }
                if(flag==1)
                    break;
                j++;
            }
        }
        else
            break;
    }
    for(i=0;i<301;i++){
        if(print[i]!=0){
            if(path[i]<min){
                min=path[i];
                q=i;
            }
        }
    }
    printf("%d ",print[q]);
    for(i=path[q]-1;i>0;i--)
        printf("%d ", find[q][i]);
    printf("%d\n", find[q][0]);
    return 0;
}
