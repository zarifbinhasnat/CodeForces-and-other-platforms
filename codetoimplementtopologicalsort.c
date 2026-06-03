#include<stdio.h>
#define MAX 10
int n,adj[MAX][MAX];
int front =-1,rear = -1,queue[MAX];
void create graph(void);
void display();
void insert_queue(int);
int delete_queue(void);
int find_indegree(int);
void main()
{
    int node ,j=0,del_node,I;
    int topsort[MAX],indeg[MAX];
    create_graph();
    printf("\n The adjacency matrix is:");
    display();
    for(node =1;node<=n;node++)
    {
        indeg[node]=find_indegree(node);
        if(indeg[node]==0)
        insert_queue(node);
    }
    while(front<=rear  )
    //continue the loop until the queue is empty
    {
        del_node= delete_queue();
        topsort[j]=del_node;
        j++;
        //delete the del_edges 
        for(node=1;node<=n;node++)
        {
            if(adj[del_node][node]=1)
            {
                adj[del_node][node]=0;
                indeg[node]= indeg[node]-1;
                if(indeg[node]==0)
                insert_queue(node);
            }
        }
    }
    printf("The topological sort can be given as:\n");
    for(node=0;i<j;node++)
    printf("")
    }
}

