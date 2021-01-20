#include <iostream>
#define Array_Based_Queue
#include "queue.cpp"
using namespace std;


int main()
{
    Quque q ;
    CreateQuque(&q) ;
    Append(&q, 5) ;
    Append(&q, 6) ;
    Append(&q, 7) ;
    Append(&q, 8) ;
    Append(&q, 9) ;
    cout<<serve(&q)<<endl;
    traverse(&q, log) ;


}
