#include<stdio.h>
int main()
{   int n;
    printf("1. FOR CONJUNCTION\n2. FOR DISJUNCTION\n3. FOR IMPLICATION\n4. FOR DOUBLE IMPLICATION\nEnter your choice(1-4):");
    scanf("%d",&n);
    switch(n)
    {
    case 1: printf("TRUTH TABLE OF CONJUNCTION: \n");
            printf("P\tQ\tP^Q\n");
            printf("0\t0\t0\n");
            printf("0\t1\t0\n");
            printf("1\t0\t0\n");
            printf("1\t1\t1\n");
            break;
    
    case 2: printf("TRUTH TABLE OF DISJUNCTION: \n");
            printf("P\tQ\tPvQ\n");
            printf("0\t0\t0\n");
            printf("0\t1\t1\n");
            printf("1\t0\t1\n");
            printf("1\t1\t1\n");
            break;
    
    case 3: printf("TRUTH TABLE OF IMPLICATION: \n");
            printf("P\tQ\tP->Q\n");
            printf("0\t0\t1\n");
            printf("0\t1\t1\n");
            printf("1\t0\t0\n");
            printf("1\t1\t1\n");
            break;
    
    case 4: printf("TRUTH TABLE OF DOUBLE IMPLICATION: \n");
            printf("P\tQ\tP<->Q\n");
            printf("0\t0\t1\n");
            printf("0\t1\t0\n");
            printf("1\t0\t0\n");
            printf("1\t1\t1\n");
            break;
        
    default: 
            printf("Invalid Input....");
    
    }
    return 0;
}