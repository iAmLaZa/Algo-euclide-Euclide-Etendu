#include <stdio.h>
#include <stdlib.h>

int algo_Euclide(int a , int b){
    int R,temp;
    //le cas ou b=>a
    if(a<b){
           temp=a;
           a=b;b=temp;
        }
    //debut algo
    R=a%b;
    while(R!=0){
        a=b;
        b=R;
        R=a%b;
    }
    return b;
}
void algo_Euclide_etendu(int a , int b,int *u,int *v){
    int temp1,temp2;
    int  r=1,q=0, up=0, vp=1;
    *u=1, *v=0;
    if(a<b){
           temp1=a;
           a=b;b=temp1;
        }
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
   }
    *u=*u;
    *v=up;


}

int main()
{   int a,b,u,v;
    printf("donner une valeur de a :");
    scanf("%d",&a);
    printf("donner une valeur de b :");
    scanf("%d",&b);

    int pgcd=algo_Euclide(a,b);

    printf("pgcd(%d,%d) = %d\n",a,b,pgcd);
    algo_Euclide_etendu(b,a,&u,&v);
    printf(" %d=  u*%d +v*%d => u=%d && v=%d",pgcd,a,b,u,v);

    return 0;
}
