#include <iostream>

using namespace std;


///
struct stackk{
    int info;
    stackk *next;
} *top; //pointer_global_element_varf;

int pop()
{
    stackk *b=top; //b il sterge pe top
    int g=-1;
    if (top!=NULL)
    {
        top=top->next;
        g=b->info;
        delete b;
    }
    return g;
}

void push(int x)
{
    stackk *nou= new stackk;
    nou->info=x;
    nou->next=top;
    top=nou;
}


void parcurgere(stackk *pointer)
{
    printf("%d ",pointer->info);
    if ((*pointer).next!=NULL)
        parcurgere(pointer->next);

}

int main()
{

    push(1);
   // push(2);
    pop();
    push(2);
    push(3);

    parcurgere(top);
    return 0;
}
