struct edge{
    int u,v,w;
};
int infi=99999;
struct graph{
    int E,V;
    struct edge *ed;
};
void BellmendFord(struct graph *,int);

void main(){
    struct graph *g;
    g = (struct graph *)malloc(sizeof(struct graph));
    printf("Enter the number of edges and vertices : \n");
    printf("No. of edges=");
    scanf("%d",&(g->E));
    printf("No. of vertices=");
    scanf("%d",&(g->V));
    g->ed=(struct edge *)malloc((g->E)*(sizeof(struct edge)));
   
printf("\nInitialise the edges : \n");
    for(int i=0;i<g->E;i++){
        printf("Edge %d : ",i);
        scanf("%d",&(g->ed[i].u));
        scanf("%d",&(g->ed[i].v));
        scanf("%d",&(g->ed[i].w));
        printf("\n");
    }
    printf("Edges : \n");
    printf("____________________________________________________\n");
    printf("  | Edge no.|\t\t    |u |\t\t|v |\t\t|w |\n ");
    for(int i=0;i<g->E;i++){
            printf("____________________________________________________\n");
        printf("  |   %d     |\t\t\t|%d |\t\t|%d |\t\t|%d |",i,g->ed[i].u,g->ed[i].v,g->ed[i].w);
        printf("\n");
    }
    printf("____________________________________________________\n");
    BellmenFord(g,0);
}

void BellmenFord(struct graph *g,int s){
    int i,j,u,v,w;
    int tV,tE;
    tV = g->V;
    tE = g->E;
    int d[tV];
    for(i=0;i<tV;i++){
        d[i]=infi;
    }
    d[s]=0;
    for(i=0;i<tV-1;i++){
        for(j=0;j<tE;j++){
            u = g->ed[j].u;
            v = g->ed[j].v;
            w = g->ed[j].w;
           
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
            }
        }
        printf("Iteration no. : %d :",i);
        for(int k=0;k<tV;k++){
            printf(" %d",d[k]);
        }
        printf("\n");
    }
}
