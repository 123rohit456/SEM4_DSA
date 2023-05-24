#include <stdio.h>
#define n 4

int a[n][n],visited[n],stack[10],queue[10];
int top=-1;
int front=-1;
int rear=-1;

void DFS(int);
void BFS(int);

void main()
{
    int v;
    printf("Enter the matrix : ");
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    scanf("%d",&a[i][j]);
    }
    }
   
    for(int i=0;i<n;i++)
    {visited[i]=0;}
   
    printf("Enter start vertex : ");
    scanf("%d",&v);
   
    printf("DFS TRAVERSAL");
    DFS(v);
    printf("\n");
    for(int i=0;i<n;i++)
    {visited[i]=0;}
    printf("BFS TRAVERSAL");
    queue[++rear]=v;
    BFS(queue[++front]);
}

void DFS(int v)
{
    visited[v]=1;
    printf(" %d ",v);
    stack[++top]=v;
    for(int i=0;i<n;i++)
    {
        if(a[v][i]==1 && !visited[i])
        {
            DFS(i);
        }
    }
   
    int i,e;
    while(top!=-1)
    {
        int f=0;
        e=stack[top];
        for(int i=0;i<n;i++)
        {
            if(a[e][i]==1 && !visited[i])
            {
                DFS(i);
                f=1;
            }
        }
        if(f==0)
        {
            top--;
        }
    }
}

void BFS(int v)
{
    visited[v]=1;
    printf(" %d ",v);
   
    for(int i=0;i<n;i++)
    {
        if(a[v][i]==1 && !visited[i])
        {
            queue[++rear]=i;
            visited[i]=1;
        }
    }
   
    if(front<rear)
    {
        BFS(queue[++front]);
    }
}
