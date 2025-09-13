#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    char name[17];
    int count;
}word[17];
int comp(const void *p1, const void * p2){
    struct Node *a = (struct Node*)p1;
    struct Node *b = (struct Node*)p2;
    if(a->count != b->count)
        return b->count - a->count;
    else
        return strcmp(a->name,b->name);
}
int main() {
    int i, j, len, n;
    char basic[17]={0};
    for(i=0;i<17;i++)
        word[i].count=0;
    scanf("%d", &n);
    scanf("%s", basic);
    len = (int)strlen(basic);
    for(i=0;i<n-1;i++){
        scanf("%s", word[i].name);
        for(j=0;j<len;j++){
            if(word[i].name[j]!=basic[j])
                word[i].count++;
        }
    }
    qsort(word,n-1,sizeof(struct Node),comp);
    for(i=0;i<n-1;i++)
        printf("%s %s %d\n", basic, word[i].name, word[i].count);
    return 0;
}
