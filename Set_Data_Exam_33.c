#include<stdio.h>
#include<stdlib.h>
int set1[100],set2[100];
int lmt1,lmt2;
void set_union()
{
    int i,j,k=-1,un[10],f;
    for(i=0;i<lmt1;i++)
    {
        k++;
        un[k]=set1[i];
    }
    for(i=0;i<lmt2;i++)
    {
        f=0;
        for(j=0;j<=k;j++)
        {
            if(set2[i]==un[j])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            k++;
            un[k]=set2[i];
        }
    }
    printf("\nUnion:  ");
    for(i=0;i<=k;i++)
    {
        printf("%d  ",un[i]);
    }
}
void intersection()
{
    int i,j,in[10],k=-1;
    for(i=0;i<lmt1;i++)
    {
        for(j=0;j<lmt2;j++)
        {
            if(set1[i]==set2[j])
            {
                k++;
                in[k]=set1[i];
                break;
            }
        }
    }
    printf("\nIntersection:  ");
    for(i=0;i<=k;i++)
    {
        printf("%d ",in[i]);
    }
}
void difference_a()
{
    int i,j,f,diff[10],k=-1;
    for(i=0;i<lmt1;i++)
    {
        f=0;
        for(j=0;j<lmt2;j++)
        {
            if(set1[i]==set2[j])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            k++;
            diff[k]=set1[i];
        }
    }
    printf("\nDiffrence:  ");
    for(i=0;i<=k;i++)
    {
        printf("%d  ",diff[i]);
    }
}
void difference_b()
{
    int i,j,f,diff[10],k=-1;
    for(i=0;i<lmt2;i++)
    {
        f=0;
        for(j=0;j<lmt1;j++)
        {
            if(set2[i]==set1[j])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            k++;
            diff[k]=set2[i];
        }
    }
    printf("\nDiffrence:  ");
    for(i=0;i<=k;i++)
    {
        printf("%d  ",diff[i]);
    }
}
void main()
{
    int i,j,f,ch,ele;
    printf("Enter the number of elements for SET A:");
    scanf("%d",&lmt1);
    printf("Enter the Elements for SET A:\n");
    for(i=0;i<lmt1;i++)
    {
        scanf("%d",&ele);
        f=0;
        for(j=0;j<=i;j++)
        {
            if(set1[j]==ele)
            {
                printf("Element exist.\n");
                f=1;
                i--;
            }
        }
        if(f==0)
        {
            set1[i]=ele;
        }
    }
    printf("Enter the number of elements for SET B:");
    scanf("%d",&lmt2);
    printf("Enter 5 Elements for SET B:\n");
    for(i=0;i<lmt2;i++)
    {
        scanf("%d",&ele);
        f=0;
        for(j=0;j<=i;j++)
        {
            if(set2[j]==ele)
            {
                printf("Element exist.\n");
                f=1;
                i--;
            }
        }
        if(f==0)
        {
            set2[i]=ele;
        }
    }
    while(1)
    {
        printf("\n\n1.UNION\n2.INTERSECTION\n3.DIFFRENCE[A-B]\n4.DIFFRENCE5[B-A]\n5.EXIT\nEnter your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                set_union();
                break;
            case 2:
                intersection();
                break;
            case 3:
                difference_a();
                break;
            case 4:
                difference_b();
                break;
            case 5:
                exit(0);
            default:
                printf("Enter a valid choice.\n");
        }
    }
}
