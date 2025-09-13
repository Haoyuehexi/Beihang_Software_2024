//
//  main.c
//  后缀表达式计算
//
//  Created by 点点 on 2022/6/8.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node{
    int num;
    char op;
    struct Node *left, *right, *leftpa, *rightpa;
}Tree;
Tree savetree[1001];
Tree *treestack[1001], *numjudge;
char s[202]={0}, final[505]={0}, temp[20]={0};
int top=-1, top1=-1, p=0;
void middle_order(Tree * t){
    memset(temp,0,sizeof(temp));
    if(t!=NULL){
        middle_order(t->left);
        if(t->op!='\0'){
            if(t->op=='*'||t->op=='/'){
                if(t->left->op!='\0'){
                    if(t->left->op=='+'||t->left->op=='-')
                        printf(")");
                }
            }
            printf("%c", t->op);
            if(t->op=='*'||t->op=='/'){
                if(t->right->op!='\0'){
                    printf("(");
                }
            }
        }
        else{
            if(t->rightpa!=NULL){
                numjudge=t->rightpa;
                while(numjudge->rightpa!=NULL){
                    if(numjudge->rightpa->op=='*'||numjudge->rightpa->op=='/'){
                        if(numjudge->op=='+'||numjudge->op=='-')
                            printf("(");
                    }
                    numjudge=numjudge->rightpa;
                }
            }
            printf("%d", t->num);
            if(t->leftpa!=NULL){
                numjudge=t->leftpa;
                while(numjudge->leftpa!=NULL){
                    if(numjudge->leftpa->op=='*'||numjudge->leftpa->op=='/')
                            printf(")");
                    numjudge=numjudge->leftpa;
                }
            }
        }
        middle_order(t->right);
    }
}
int main() {
    int i, j=0, type;
    char op[202]={0};
    double num[202]={0}, ans[202]={0};
    gets(s);
    scanf("%d", &type);
    for(i=0;s[i]!='\0';){
        while(s[i]==' ')
            i++;
        while(isdigit(s[i])){
            num[j] = num[j]*10 + s[i++] - '0';
            if(!isdigit(s[i]))
                j++;
        }
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            op[j++]=s[i++];
    }
    for(i=0;;i++){
        if(num[i]!=0){
            top++;
            top1++;
            ans[top]=num[i];
            savetree[top1].num=num[i];
            savetree[top1].left=savetree[top1].right=NULL;
            treestack[top]=&savetree[top1];
        }
        else if(op[i]!='\0'){
            top1++;
            savetree[top1].op=op[i];
            savetree[top1].left=treestack[top-1];
            savetree[top1].right=treestack[top];
            treestack[top-1]->rightpa=&savetree[top1];
            treestack[top-1]->leftpa=NULL;
            treestack[top]->leftpa=&savetree[top1];
            treestack[top]->rightpa=NULL;
            switch(op[i]){
                case '+':
                    ans[top-1]=ans[top-1]+ans[top];
                    break;
                case '-':
                    ans[top-1]=ans[top-1]-ans[top];
                    break;
                case '*':
                    ans[top-1]=ans[top-1]*ans[top];
                    break;
                case '/':
                    ans[top-1]=ans[top-1]/ans[top];
                    break;
            }
            ans[top--]=0;
            treestack[top]=&savetree[top1];
        }
        if(num[i]==0&&op[i]=='\0')
            break;
    }
    ans[top]*=1000;
    ans[top]=(ans[top]+5)/10;
    ans[top]/=100;
    if(type==1)
        printf("%.2lf\n", ans[top]);
    else if(type==2){
        middle_order(treestack[0]);
        printf("\n");
        printf("%.2lf\n", ans[top]);
    }
    return 0;
}
