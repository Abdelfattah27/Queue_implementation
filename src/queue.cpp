#ifdef Array_Based_Queue

#include "../include/Queue.h"
void CreateQuque(Quque *quque)
{
    quque->front = 0 ;
    quque->rear = -1 ;
    quque->size = 0 ;
}
bool Quque_Is_Impty(Quque *quque)
{
    return quque->size == 0 ;
}
bool Quque_Is_Full(Quque *quque)
{
    return quque->size == (MAXSIZE -1) ;
}
int QuqueSize(Quque *quque)
{
    return quque->size ;
}
void Append ( Quque *quque, ququetype value )
{
    if(quque->rear == (MAXSIZE -1))
    {
        quque->elements[0] = value ;
        quque->rear = 0 ;
    }
    else
    {
        quque->elements[++quque->rear] = value ;

    }
    quque->size++ ;
}
ququetype serve(Quque *quque)
{
    quque->size-- ;
    if(quque->front == (MAXSIZE -1 ))
    {
        quque->front = 0 ;
        return quque->elements[MAXSIZE -1] ;
    }
    else
    {
        quque->front++ ;
        return quque->elements[quque->front-1] ;
    }

}
void ClearQuque(Quque *quque)
{
    quque->front = 0 ;
    quque->rear = -1 ;
    quque->size = 0 ;
}
void traverse(Quque *quque, void (*function)(ququetype element))
{
    int First_Pos = quque->front;
    for(int i = 0 ; i < quque->size ; i++)
    {
        (*function)(quque->elements[First_Pos]);
        First_Pos = (First_Pos+1)%MAXSIZE ;
    }
}
void log (ququetype value )
{
    std::cout<<value<<std::endl;
}


#else
#include "../include/Queue.h"
void CreateQuque(Quque *quque)
{
    quque->front = nullptr ;
    quque->rear = nullptr;
    quque->size = 0;
}
bool Quque_Is_Impty(Quque *quque)
{
    return quque->size == 0 ;
}
bool Quque_Is_Full(Quque *quque)
{
    return false ;
}
int QuqueSize(Quque *quque)
{
    return quque->size ;
}
void Append ( Quque *quque, ququetype Value )
{
    QuqueNode* NewNode = new QuqueNode;
    NewNode->value = Value;
    NewNode->Next = nullptr;
    if (!quque->front)
    {
        quque->front = NewNode;
        quque->rear = NewNode;
    }
    // pn->ptr = back ;
    else
    {
        quque->rear->Next = NewNode;
        quque->rear = NewNode;
    }
    quque->size++ ;
}
ququetype serve(Quque *quque)
{
    quque->size-- ;
    QuqueNode* PopedNode = new QuqueNode;
    PopedNode = quque->front;
    quque->front = quque->front->Next;
    ququetype tempvariable =PopedNode->value ;
    delete PopedNode;
    if (!quque->front)
        quque->rear = nullptr;
    return tempvariable ;
}
void ClearQuque(Quque *quque)
{
    QuqueNode *traversepointer =  quque->front ;
    while(traversepointer)
    {
        QuqueNode *temppointer = traversepointer->Next ;
        delete traversepointer ;
        traversepointer = temppointer ;
    }
    quque->front = nullptr ;
    quque->rear = nullptr;
    quque->size = 0;
}
void traverse(Quque *quque, void (*function)(ququetype element))
{
    QuqueNode* traverseptr =  quque->front;
    while (traverseptr)
    {
        (*function)(traverseptr->value);
        traverseptr = traverseptr->Next;
    }
}
void log (ququetype value )
{
    std::cout<<value<<std::endl;
}

#endif
