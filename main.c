#include <stdio.h>
#include <stdlib.h>

int algo_Euclide(int a , int b){
    int R;
    //debut algo
    R=a%b;
    while(R!=0){
        a=b;
        b=R;
        R=a%b;
    }
    return b;
}
int algo_Euclide_rec(int a, int b)
{
    if(a%b==0)
    {
            return b;
    }
    else
    {
        if(a>b)
           return algo_Euclide_rec(a,a%b);
        else
           return algo_Euclide_rec(b, b%a);
    }
}


void algo_Euclide_etendu(int a , int b,int *u,int *v){
    int temp1,temp2;
    int  r=1,q=0, up=0, vp=1;
    
    
    *u=1, *v=0;

    int temp3=a,temp4=b;
    
    printf("----> %d = (%d)*%d +(%d)*%d\n",b,up,a,vp,b);
    while(r!=0){
        q=a/b;
        r=a%b;
        a=b;
        b=r;
        temp1=*v;
        temp2=vp;
        (*v)=(*u)-q*(*v);
        vp=up-q*vp;
        *u=temp1;
        up=temp2;
        printf("----> %d = (%d)*%d +(%d)*%d\n",r,*v,temp3,vp,temp4);
   }
    *u=*u;
    *v=up;


}

int main()
{   int a,b,u,v,temp;

    printf("donner une valeur de a :");
    scanf("%d",&a);
    printf("donner une valeur de b :");
    scanf("%d",&b);
    if(a<b){

            temp=a;
            a=b;
            b=temp;
        }
    int pgcd=algo_Euclide_rec(a,b);

    printf("pgcd(%d,%d) = %d\n",a,b,pgcd);
    algo_Euclide_etendu(b,a,&u,&v);
    if(a<b)
        printf("PGCD= %d=  u*%d +v*%d => u=%d && v=%d",pgcd,a,b,u,v);
    else
        printf("PGCD= %d=  u*%d +v*%d => u=%d && v=%d",pgcd,b,a,u,v);

    return 0;
}
