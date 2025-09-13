#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
double bianliang[26]={0};
double culculate(char s[]){
    int top=-1;
    double num[201]={0}, ans[201];
    char op[201]={0};
    int i, j=0, stacktop=-1;
    char stack[201]={0};
    for(i=0;s[i]!='\0';){
        if(isalpha(s[i])){
            num[j++] = bianliang[s[i]-'a'];
            i++;
        }
        while(isdigit(s[i])){
            num[j] = num[j]*10 + s[i++] - '0';
            if(!isdigit(s[i]))
                j++;
        }
        if(s[i]=='\0')
            break;
        if(s[i]=='(')
            stack[++stacktop]=s[i];
        else if(s[i]=='+'||s[i]=='-'){
            while(stacktop>-1){
                if(stack[stacktop]=='(')
                    break;
                else
                    op[j++]=stack[stacktop--];
            }
            stack[++stacktop]=s[i];
        }
        else if(s[i]=='*'||s[i]=='/'){
            while(stacktop>-1){
                if(stack[stacktop]=='('||stack[stacktop]=='+'||stack[stacktop]=='-')
                    break;
                else
                    op[j++]=stack[stacktop--];
            }
            stack[++stacktop]=s[i];
        }
        else if(s[i]==')'){
            while(stack[stacktop]!='(')
                op[j++]=stack[stacktop--];
            stacktop--;
        }
        i++;
    }
    while(stacktop>-1)
        op[j++]=stack[stacktop--];
        for(i=0;;i++){
            if(num[i]!=0){
                top++;
                ans[top]=num[i];
            }
            else if(op[i]!='\0'){
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
                ans[top]=0;
                top--;
            }
            if(num[i]==0&&op[i]=='\0')
                break;
        }
    return ans[top];
}
int main() {
    int i, j;
    char language[201]={0}, yunsuan[201]={0};
    while(1){
        gets(language);
        if(strcmp(language,"exit")==0)
            break;
        else{
            if(language[1]=='='){
                j=0;
                for(i=2;language[i]!='\0';i++)
                    yunsuan[j++]=language[i];
                yunsuan[j]='\0';
                bianliang[language[0]-'a']=culculate(yunsuan);
            }
            else if(language[1]=='r'){
                for(i=6;language[i]!='\0';i++){
                    if(language[i]==' ')
                        continue;
                    else
                        printf("%.3lf ", bianliang[language[i]-'a']);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
