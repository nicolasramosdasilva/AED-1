//Nicolas Ramos da Silva 178197

#include <stdio.h>
#include <string.h>
int main()
{
    int a,b,i,j,ab,x=0,k=0,l=0,A,B;
    char f;
    scanf("%d%d", &a, &b);
    char image[b][a+1];

    for(i=0; i<b; i++)
        scanf("%s", image[i]);
    ab=a*b;
    for(A=1; A<=ab; )
    {
        if(image[k][l]=='>')
        {
            l++; A++; B=1;
            if(l>=a) break;
        }
        else if(image[k][l]=='v')
        {
            k++; A++; B=2;
            if(k>=b) break;
        }
        else if(image[k][l]=='<')
        {
            l--; A++; B=3;
            if(l<0) break;
        }
        else if(image[k][l]=='^')
        {
            k--; A++; B=4;
            if(k<0) break;
        }
        else if(image[k][l]=='*')
                  {
            A=1000;
            break;
        }
        else if(image[k][l]=='.')
        {
            if(B==1)
            {
                l++; A++;
                if(l>=a) break;
            }
            else if(B==2)
            {
                k++; A++;
                if(k>=b) break;
            }
            else if(B==3)
            {
                l--; A++;
                if(l<0) break;
            }
            else if(B==4)
            {
                k--; A++;
                if(k<0) break;
            }
        }
    }
    if(A==1000) printf("*\n");
    else printf("!\n");

    return 0;
}
