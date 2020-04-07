#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("date.in");

struct coordonate{ int x,y; };

struct dequee
{
    coordonate info;
    dequee *prev, *next;
} *prim, *ultim;
// *pointer_global_prim_element
// *pointer_global_ultim_element;

void push_left(coordonate x)
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

void push_right(coordonate x)
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

void pop_left()
{
    dequee *b =prim; //b il sterge pe prim
    int val=-1;
    if (prim!=NULL)
    {
//        val=prim->info;
        if(prim->next==NULL)
            prim=ultim=NULL;
        else
        {
            prim->next->prev=NULL;
            prim=prim->next;
        }
    }
    delete b;
//    return val;
}

int pop_right()
{
    dequee *b=ultim;
    int val=-1;
    if (ultim!=NULL)
    {
      //  val=ultim->info;
        if(ultim->prev==NULL)
            prim=ultim=NULL;
        else
        {
            ultim->prev->next=NULL;
            ultim=ultim->prev;
        }
    }
    delete b;
 //   return val;
}

void parcurgere()
{
     while(prim!=NULL)
     {
         cout<<prim->info.x<<' '<<prim->info.y<<' ';
         prim=prim->next;
     }
}

int main()
{
    int n,a[100][100], i,j,k;
    coordonate coord;

    fin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          fin>>a[i][j];
    k=2;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]==1)
        {
            coord.x=i;
            coord.y=j;
            a[i][j]=k;

            push_right(coord);

            while(prim!=NULL)
            {
                int ci, cj;
                ci=prim->info.x;
                cj=prim->info.y;

                pop_left();

                a[ci][cj]=k;

                if(a[ci-1][cj]==1 && ci>=1)
                {
                    coord.x=ci-1;
                    coord.y=cj;
                    push_right(coord);
                }
                if(a[ci][cj-1]==1 && cj>=1)
                {
                    coord.x=ci;
                    coord.y=cj-1;
                    push_right(coord);
                }
                if(a[ci+1][cj]==1 && ci<=n-1)
                {
                    coord.x=ci+1;
                    coord.y=cj;
                    push_right(coord);
                }
                if(a[ci][cj+1]==1 && cj<=n-1)
                {
                    coord.x=ci;
                    coord.y=cj+1;
                    push_right(coord);
                }

            }
            k++;
        }
    for(i=0;i<n;i++)
        {for(j=0;j<n;j++)
          cout<<a[i][j]<<' ';
        cout<<endl;}

    return 0;
}
