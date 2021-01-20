
#ifdef Array_Based_Queue

#define ququetype int
#define MAXSIZE 10000
struct Quque
{
    ququetype elements[MAXSIZE] ;
    int front ;
    int rear ;
    int size ;
};
void CreateQuque(Quque *quque);
bool Quque_Is_Impty(Quque *quque);
bool Quque_Is_Full(Quque *quque);
int QuqueSize(Quque *quque);
void Append ( Quque *quque, ququetype Value );
ququetype serve(Quque *quque);
void ClearQuque(Quque *quque);
void traverse(Quque *quque, void (*function)(ququetype element)) ;
void log (ququetype value );


#else

#define ququetype int
#define MAXSIZE 10000
struct QuqueNode
{
    ququetype value ;
    QuqueNode* Next ;
};
struct Quque
{
    QuqueNode* front ;
    QuqueNode* rear ;
    int size ;
};
void CreateQuque(Quque *quque);
bool Quque_Is_Impty(Quque *quque);
bool Quque_Is_Full(Quque *quque);
int QuqueSize(Quque *quque);
void Append ( Quque *quque, ququetype Value );
ququetype serve(Quque *quque);
void ClearQuque(Quque *quque);
void traverse(Quque *quque, void (*function)(ququetype element)) ;
void log (ququetype value );

#endif
