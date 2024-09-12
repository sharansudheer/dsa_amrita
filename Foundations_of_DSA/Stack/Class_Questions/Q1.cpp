struct StackRecord
{
int Capacity;
int TopOfStack;
ElementType *Array;
}
typedef struct StackRecord *Stack;
struct ExtendedRecord
{
Stack S;
Stack M;
}
typedef struct ExtendedRecord *ExtendedStack
int IsFull(Stack S)
{
return S->TopOfStack == S->Capacity - 1;
}
int IsEmpty(Stack S)
{
return S->TopOfStack == -1;
}
ElementType Top(stack M)
{
if ( !IsEmpty(M) )
return M->Array[M->TopOfStack];
retuen MaxValue; // return a maximum integer to avoid warning
}
void Push(ElementType X, ExtendedStack E) //Push(X,E)
{
if ( IsFull(E->S) )
Error( "Full stack" );
else
{
E->S->Array[++E->S->TopOfStack] = X; //Push(X,S)
if ( X <= Top(E->M) )
E->M->Array[++E->M->TopOfStack] = X; //Push(X,M)
}
}
ElementType Pop(ExtendedStack E) //Pop(E)
{
ElementType temp;
if ( IsEmpty(E->S) )
Error( "Empty stack" );
else
{
temp = E->S->Array[E->S->TopOfStack]; //Pop(S)
E->S->TopOfStack--;
if (Top(E->M) == temp)
E->M->TopOfStack-- //Pop(M)
return temp;
}
}
ElementType FindMin(ExtendedStack E)
{
if ( IsEmpty(E->M) )
Error( "Empty stack" );
else
return Top(E->M);
}