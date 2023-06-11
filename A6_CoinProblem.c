#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cost, count = 0, i;
    int inr_count;
    printf("Enter the array size : ");
    scanf("%d",&inr_count);
    int inr[inr_count];
    for(i=0;i<inr_count;i++){
        scanf("%d",&inr[i]);
    }
   

    printf("Enter the amount: ");
    scanf("%d", &cost);

    for (i = 0; i < inr_count; i++, count = 0) {
        while (inr[i] <= cost) {
            cost = cost - inr[i];
            count++;
        }
        printf("INR:\t%d\t\tNos:\t%d\n", inr[i], count);
    }

    return 0;
}
