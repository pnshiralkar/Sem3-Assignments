/******************************************************************************

Que - Given sets A and B print set (A - B)

*******************************************************************************/

#include <stdio.h>

int main()
{
    int n1,n2,i,j;
    scanf("%d", &n1);
    int a[n1];
    for(i=0;i<n1;i++)
        scanf("%d", &a[i]);
    
    scanf("%d", &n2);
    int b[n2];
    for(j=0;j<n2;j++)
        scanf("%d", &b[j]);

    //A - B
    printf("\n{ ");
    for(i=0;i<n1;i++)
    {
        int f=1;
        for(j=0;j<n2;j++)
            if(a[i]==b[j])
            {
                f=0;
                break;
            }
        if(f)
            printf("%d ", a[i]);
    }
    printf("}");

    return 0;
}
