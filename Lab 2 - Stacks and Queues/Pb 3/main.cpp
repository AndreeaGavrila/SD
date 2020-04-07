#include <iostream>

using namespace std;

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
    nou->next=NULL;
    if(top==NULL)
        top=nou;
    else
      {
       nou->next=top;
       top=nou;
      }
}

int main()
{
    int n,val;
    cin>>n;
    cin>>val;
    push(val);
    for(int i=1;i<=n-1;i++)
    {
        cin>>val;
        if(top!=NULL)
            if(top->info==val)
               pop();
        else
            push(val);
    }

    if(top==NULL)
        cout<<"Configuratie valida";
    else
        cout<<"Configuratie invalida";

    return 0;
}
