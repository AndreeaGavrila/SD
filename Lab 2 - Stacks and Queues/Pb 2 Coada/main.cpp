#include <iostream>
using namespace std;

struct dequee
{
    int info;
    dequee *prev, *next;
} *prim, *ultim;
// *pointer_global_prim_element
// *pointer_global_ultim_element;

void push_left(int x)
{
    dequee *nou= new dequee;
    nou->info=x;
    nou->next=prim;
    nou->prev=NULL;
    if( prim!= NULL)
        prim->prev=nou;
    else
        ultim=nou;
    prim=nou;
}

void push_right(int x)
{
    dequee *q=new dequee;
    q->info=x;
    q->next=NULL;
    q->prev=ultim;

    if(ultim!=NULL)
          ultim->next=q;
    else  prim=q;

    ultim=q;
}

int pop_left()
{
    dequee *b =prim; //b il sterge pe prim
    int val=-1;
    if (prim!=NULL)
    {
        val=prim->info;
        if(prim->next==NULL)
            prim=ultim=NULL;
        else
        {
            prim->next->prev=NULL;
            prim=prim->next;
        }
    }
    delete b;
    return val;
}

int pop_right()
{
    dequee *b=ultim;
    int val=-1;
    if (ultim!=NULL)
    {
        val=ultim->info;
        if(ultim->prev==NULL)
            prim=ultim=NULL;
        else
        {
            ultim->prev->next=NULL;
            ultim=ultim->prev;
        }
    }
    delete b;
    return val;
}

void parcurgere()
{
     while(prim!=NULL)
     {
         printf("%d ",prim->info);
         prim=prim->next;
     }
}

int main()
{
    push_left(1);
    push_right(2);
   cout<<"Pop_Right: "<<pop_right()<<endl;
   cout<<"Pop_Left: "<<pop_left()<<endl;
    push_right(3);
    parcurgere();

    return 0;
}
