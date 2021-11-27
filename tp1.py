def algo_Euclide_etendu(a,b):
    r1,u1,v1,r2,u2,v2 = a, 1, 0, b, 0, 1
    print("----------->"+str(r1)+"=("+str(u1)+")*"+str(a)+"+("+str(u2)+")*"+str(b))
    while(r2!=0 ):
        q=int(r1/r2)
        r1,u1,v1,r2,u2,v2=r2,u2,v2,r1%r2,u1-q*u2,v1-q*v2
        print("----------->"+str(r1)+"=("+str(u1)+")*"+str(a)+"+("+str(v1)+")*"+str(b))
    return u1,v1


def algo_Euclide(a,b):
    R=a%b
    while(R!=0):
        a=b
        b=R
        R=a%b
    return b
def algo_Euclide_rec(a,b):
    if(a%b==0):
         return b; 
    else:
        if(a>b):
           return algo_Euclide_rec(a,a%b)
        else:
           return algo_Euclide_rec(b, b%a)
       
a=int(input("donner une valeur de a :"))
b=int(input("donner une valeur de b :"))

pgcd=algo_Euclide_rec(a,b)
print("PGCD("+str(a)+","+str(b)+")="+str(pgcd))
u,v=algo_Euclide_etendu(a,b)
#pgcd=algo_Euclide_rec(a,b)

print("PGCD="+str(pgcd)+"= u*"+str(a)+"v*"+str(b)+"  =======>  u="+str(u)+" v="+str(v))
         

        