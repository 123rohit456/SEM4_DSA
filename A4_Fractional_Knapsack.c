#include <stdio.h>

#define n 5 //Objects//
int capacity =15;

float Basedprofit(float [],float [],float[]);
float Weightprofit(float [],float [],float[]);
float Pwprofit(float[],float[],float[]);

void main(){
    float p[10],w[10],x[10];
    printf("***********************************\n");
    printf("Enter the profits : ");
    for(int i=0;i<n;i++){
        scanf("%f",&p[i]);
    }
    printf("Enter the weights : ");
      for(int i=0;i<n;i++){
        scanf("%f",&w[i]);
    }
   
    printf("\n***********************************\n");
      for(int i=0;i<n;i++){
        x[i]=0;
    }
    float tp = Basedprofit(p,w,x);
    float tp1 = Weightprofit(p,w,x);
    float tp2 = Pwprofit(p,w,x);
    printf("\n***********************************\n");
    printf("Maximum profit based on profit : %.4f \n",tp);
    printf("Maximum profit based on weight : %.4f \n",tp1);
    printf("Maximum profit based on ratio : %.4f ",tp2);
    printf("\n***********************************\n");
}

float Basedprofit(float p[],float w[],float x[])
{
    float temp;
    float tp=0;
    float W=0;
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(p[j]<p[j+1]){
                temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                temp = w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
    }
    printf("\n***********************************\n");
    printf("According to profit\n");
    printf("Profits : ");
    for(int i=0;i<n;i++){
        printf("%.0f ",p[i]);
    }
    printf("\nWeights : ");
    for(int i=0;i<n;i++){
        printf("%.0f ",w[i]);
    }
    printf("\n***********************************\n");
   
    while(k<n){
        if(W+w[k]<=capacity){
            x[k]=1;
            W=W+w[k];
            k++;
        }
        else{
            x[k]=(capacity - W)/w[k];
            break;
        }
       
    }
    for(int i=0;i<n;i++){
        tp = tp + p[i]*x[i];
    }
    return tp;
}

float Weightprofit(float p[],float w[],float x[])
{
    float temp;
    float tp1=0;
    float W=0;
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(w[j]>w[j+1]){
                temp = w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
                temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("\n***********************************\n");
    printf("According to weight\n");
    printf("Profits : ");
    for(int i=0;i<n;i++){
        printf("%.0f ",p[i]);
    }
    printf("\nWeights : ");
    for(int i=0;i<n;i++){
        printf("%.0f ",w[i]);
    }
    printf("\n***********************************\n");
   
    while(k<n){
        if(W+w[k]<=capacity){
            x[k]=1;
            W=W+w[k];
            k++;
        }
        else{
            x[k]=(capacity - W)/w[k];
            break;
        }
       
    }
    for(int i=0;i<n;i++){
        tp1 = tp1 + p[i]*x[i];
    }
    return tp1;
}


float Pwprofit(float p[],float w[],float x[])
{
    float pw[10];
    for(int i=0;i<n;i++){
        pw[i]=p[i]/w[i];
    }
    float temp;
    float tp=0;
    float W=0;
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(pw[j]<=pw[j+1]){
                temp = pw[j];
                pw[j]=pw[j+1];
                pw[j+1]=temp;
                temp = w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
                temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("\n***********************************\n");
    printf("According to ratio\n");
    printf("Profits : ");
    for(int i=0;i<n;i++){
        printf("%.0f ",p[i]);
    }
    printf("\nWeights : ");
    for(int i=0;i<n;i++){
        printf("%.0f ",w[i]);
    }
   
     printf("\nRatio : ");
    for(int i=0;i<n;i++){
        printf("%.4f ",pw[i]);
    }
    printf("\n***********************************\n");
   
    while(k<n){
        if(W+w[k]<=capacity){
            x[k]=1;
            W=W+w[k];
            k++;
        }
        else{
            x[k]=(capacity - W)/w[k];
            break;
        }
       
    }
    for(int i=0;i<n;i++){
        tp = tp + p[i]*x[i];
    }
    return tp;
}
