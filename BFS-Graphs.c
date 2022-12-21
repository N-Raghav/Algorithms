#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
int v,m=0;
// QUEUE
node *qu[10];
int front = -1, rear = -1, size = 10;
void push(node *a)
{
    if (front == -1 && rear == -1)
    {
        rear++;
        front++;
    }
    else if (rear == size - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    qu[rear] = a;
}
node *pop()
{
    node *a;
    if (front == rear + 1)
    {
        printf("Underflow");
        exit(1);
    }
    else if (front == size - 1)
    {
        a = qu[front];
        front = 0;
    }
    else
    {
        a = qu[front];
        front++;
    }
    return a;
}
void addedg(struct node *head[v]){
    struct node *temp;
    struct node *edge;
    for(int j=0;j<v;j++){
        int k;
        printf("Enter number of edges for %d:",head[j]->data);
        scanf("%d",&k);
        if(k>v){
            printf("Invalid vertices");
            break;
        }
        for(int i=0;i<k;i++){
            edge=malloc(sizeof(struct node));
            scanf("%d",&edge->data);
            edge->next=NULL;
            if(head[j]->next==NULL){
            head[j]->next=edge;
            temp=edge;}
            else{
                temp->next=edge;
                temp=edge;
            }
        }
    }
}
void prtgph(struct node *head[v],int v){
    for(int i=0;i<v;i++){
        struct node * trav=head[i];
        printf("%d",trav->data);
        trav=trav->next;
        while(trav!=NULL){
            printf("->%d",trav->data);
            trav=trav->next;
        }
        printf("\n");
    }
}
void bfs(struct node* head[v],int v){
    struct node *temp;
    int vis[v];
    for(int i=0;i<v;i++){
        vis[i]=-1;
    }
    push(head[0]);
    vis[m]=head[0]->data;
    m++;
    while(front!=rear+1){
        temp=pop();
        printf("%d\t",temp->data);
        while(temp!=NULL){
            int flag=0;
            for(int j=0;j<v;j++){
                //printf("(%d)",vis[j]);
                if(temp->data==vis[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                    vis[m]=temp->data;
                    m++;
                    for(int k=0;k<v;k++){
                        if(temp->data==head[k]->data){
                            push(head[k]);
                            break;
                        }
                    }
            }
            temp=temp->next;
        }
    }
}
void main(){
    printf("Enter number of vertices in graph:");
    scanf("%d",&v);
    struct node *head[v];
    printf("Enter vertices:\n");
    for(int i=0;i<v;i++){
        head[i]=malloc(sizeof(struct node));
        scanf("%d",&head[i]->data);        
        head[i]->next=NULL;
    }
    addedg(head);
    prtgph(head,v);
    bfs(head,v);
}