#include<bits/stdc++.h>
#define Maxsize 50
using namespace std;
typedef struct{
    int data[Maxsize];
    int top; /* data */
} SqStack;
void InitStack(SqStack &S){
    S.top = -1;
}
bool StackEmpty(SqStack S){
    if(S.top==-1)
        return true;
    else
        return false;
}
