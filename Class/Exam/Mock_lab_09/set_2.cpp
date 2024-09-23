/* 
/////////////////////////////////////////////////////////////////

Source:- 

https://ms.ntub.edu.tw/~spade/teaching/x-DS2006-1/DS-03-22a.pdf 

////////////////////////////////////////////////////////////////
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

//template <typename ElementType>

using namespace std;

typedef int ElementType;

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

typedef struct StackRecord *Stack;

struct ExtendedRecord
{
    Stack S;
    Stack M;
};

typedef struct ExtendedRecord *ExtendedStack;

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == -1;
}

ElementType Top(Stack M)
{
    if ( !IsEmpty(M) ){
        return M->Array[M->TopOfStack];
    }
    return -1; // return a maximum integer to avoid warning
}
void Push(ElementType X, ExtendedStack E) //Push(X,E)
{
    if ( IsFull(E->S) ){
        printf( "Full stack" );
    }
    else
        {
            E->S->Array[++E->S->TopOfStack] = X; //Push(X,S)
            if ( X <= Top(E->M) ){
                E->M->Array[++E->M->TopOfStack] = X; //Push(X,M)
            }
        }
}
ElementType Pop(ExtendedStack E) //Pop(E)
{
    ElementType temp;
    if ( IsEmpty(E->S) ){
        printf( "Empty stack");
    }
    else
    {
        temp = E->S->Array[E->S->TopOfStack]; //Pop(S)
        E->S->TopOfStack--;
        if (Top(E->M) == temp){
                E->M->TopOfStack--; //Pop(M)
        }
        return temp;
    }
}
ElementType FindMin(ExtendedStack E)
{
    if ( IsEmpty(E->M) ){
        printf( "Empty stack" );
    }
    else{
        return Top(E->M);
    }
}
