#include <stdio.h>
int size=0;

void insert(int,int []);
void heapify(int [],int,int);
void swap(int *,int *);
void heapsort(int [],int);

int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        insert(a[i],a);
    }
    printf("Maxheap : ");
    for(int i=0;i<n;i++)
    {
        printf("|%d|",a[i]);
    }
    heapsort(a,size);
    printf("\nHeapsort : ");
    for(int i=0;i<n;i++)
    {
        printf("|%d|",a[i]);
    }
   
   
}

void insert(int d,int a[]){
    if(size==1){
        a[size++]=d;
    }
    else{
        a[size++]=d;
    for(int i = ((size)/2) - 1;i>=0;i--){
        heapify(a,i,size);
    }
}
}

void heapify(int a[],int i,int size){
    int max=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<size && a[max]<a[l])
    max=l;
    if(r<size && a[max]<a[r])
    max=r;
    if(max!=i){
        swap(&a[max],&a[i]);
        heapify(a,max,size);
    }
}

void swap(int *x,int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}

void heapsort(int a[],int size)
{
    for (int i = size - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, 0, i);
    }
}
