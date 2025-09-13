#include <stdio.h>
#include <stdlib.h>
struct Node{
    int number;
    int count;
    struct Node *left, *right;
    struct Node *parent;
};
int total=0, max=0;
struct Node *find;
struct Node *q=NULL;
struct Node* insert(struct Node * p, int item){
    if(p==NULL){
        p = (struct Node*)malloc(sizeof(struct Node));
        p->parent = q;
        p->number = item;
        p->count = 1;
        p->left = p->right = NULL;
        q=p;
    }
    else if(item < p->number){
        total++;
        p->left = insert(p->left,item);
    }
    else if(item > p->number){
        total++;
        p->right = insert(p->right,item);
    }
    else{
        total++;
        p->count++;
    }
    return p;
}
void post_order(struct Node * p){
    if(p!=NULL){
        post_order(p->left);
        post_order(p->right);
        if(p->count > max){
            max = p->count;
            find = p;
        }
    }
}
void print(struct Node * p){
    printf("%d ",p->number);
    if(p->number > find->number)
        print(p->left);
    else if(p->number < find->number)
        print(p->right);
    else
        return ;
}
int main() {
    int i, n, num;
    struct Node *root=NULL;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &num);
        root = insert(root,num);
    }
    post_order(root);
    printf("%d\n", total);
    print(root);
    printf("\n");
    return 0;
}
