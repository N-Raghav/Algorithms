#include <stdio.h>
#include <stdlib.h>
void addedg(int v,int mat[v][v]){
    for(int l=0;l<v;l++){
        for(int m=0;m<v;m++){
            mat[l][m]=-1;
        }
    }
    int j;
    
    for(j=0;j<v;j++){
        int k;
        printf("Enter number of edges for %d:",j);
        scanf("%d",&k);
        if(k>v){
            printf("Invalid vertices");
            exit(1);
        }
        for(int q=0;q<k;q++){
            int z;
            scanf("%d",&z);
            mat[j][z]=1;
                //mat[z][j]=1;
        }
    }
}
void prtmat(int v,int mat[v][v]){
    for(int t=0;t<v;t++){
        for(int u=0;u<v;u++){
            printf("%d\t",mat[t][u]);
        }
        printf("\n");
    }
}
void dfs(int v,int mat[v][v],int vis[v],int a){
    
    vis[a]=1;
    printf("%d\t",a);
    for(int i=0;i<v;i++){
        if(mat[a][i]==1 && vis[i]==-1){
            //printf("%d\t",a);
            dfs(v,mat,vis,i);
        }
    }
}
void main(){
    int v;
    printf("Enter number of vertices: ");
    scanf("%d",&v);
    int mat[v][v];
    addedg(v,mat);
    prtmat(v,mat);
    int vis[v];
    for(int i=0;i<v;i++){
        vis[i]=-1;
    }
    printf("\nDFS:\n");
    dfs(v,mat,vis,0);
}