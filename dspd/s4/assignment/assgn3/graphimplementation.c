#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
        int value;
        int weight;
        int index;
        struct node* next;
} node;

typedef struct listnode
{
        int value;
        node *child;
} listnode;

typedef struct graph
{
        int numberofvertices;
        int isdirected;
        int isweighted;
        listnode* nodes;
} graph;

void printList(struct graph* g)
{
        int i, n = g -> numberofvertices;
        node* temp;
        printf("\n\nAdjacency List\n");
        printf("NOTE:number inside parenthesis are node number and outside it are value of that node\n");
        for(i = 0 ; i < n ; ++i)
        {
                temp = g -> nodes[i] . child;
                printf("AList(%d) =", temp -> index);
                while(temp != NULL)
                {
                        printf("-> %d(%d) ", temp -> value, temp -> index);
                        temp = temp -> next;
                }
                printf("\n-------------------------\n");
        }
}

void addvertex(graph *g, int num)
{
        int i, n = g -> numberofvertices, found = 0;
        for(i = 0 ; i < n && found == 0 ; ++i)
                if(g -> nodes[i] . value == num)
                        found = 1;
        if(found == 0)
        {
                g -> numberofvertices += 1;
                if(n == 0)
                        g -> nodes = (listnode *)malloc(sizeof(listnode));
                else
                        g -> nodes = (listnode *)realloc(g -> nodes, (g -> numberofvertices) * sizeof(listnode));
                g -> nodes[n] . value = num;
                node *temp = (node *)malloc(sizeof(node));
                temp -> index = n;
                temp -> value = num;
                temp -> weight = 0;
                temp -> next = NULL;
                g -> nodes[n] . child = temp;
                printf("Vertex added successfully!");
        }
        else
                printf("Vertex already exist!");
}

void addedge(graph *g, int src, int dest, int wt)
{
        int n = g -> numberofvertices;
        if(src < n && dest < n && src != dest)
        {
                node *temp = g -> nodes[src] . child;
                while(temp != NULL && temp -> index != dest)
                        temp = temp -> next;
                if(temp == NULL)
                {
                        temp = (node *)malloc(sizeof(node));
                        temp -> index = dest;
                        temp -> value = g -> nodes[dest] . value;
                        temp -> weight = wt;
                        temp -> next = g -> nodes[src] . child -> next;
                        g -> nodes[src] . child -> next = temp;
                        if(g -> isdirected == 0)
                        {
                                temp = (node *)malloc(sizeof(node));
                                temp -> index = src;
                                temp -> value = g -> nodes[src] . value;
                                temp -> weight = wt;
                                temp -> next = g -> nodes[dest] . child -> next;
                                g -> nodes[dest] . child -> next = temp;
                        }
                        printf("Edge added successfully!");
                }
                else
                        printf("Edge already present!");
        }
        else
                printf("Invalid data!");
}

graph *creategraph(int n)
{
        int i, choice = 1, src, dest, val, wt;
        graph *g = (graph *)malloc(sizeof(graph));
        g -> numberofvertices = 0;
        g -> nodes = NULL;
        printf("\nGraph type (1 for directed and 0 for undirected) : ");
        scanf("%d", &(g -> isdirected));
        printf("Graph type (1 for weighted and 0 for unweighted) : ");
        scanf("%d", &(g -> isweighted));

        printf("\nAdding vertices");
        for(i = 0 ; i < n ; ++i)
        {
                printf("\nEnter value of node : ");
                scanf("%d", &val);
                addvertex(g, val);
        }
        
        printf("\n\nAdding edges");
        printf("\nEnter 1 to add edges, 0 to finish taking edges : ");
                scanf("%d", &choice);
        while(choice)
        {
                printf("Enter source node : ");
                scanf("%d", &src);
                printf("Enter destination node : ");
                scanf("%d", &dest);
                wt = 1;
                if(g -> isweighted == 1)
                {
                        printf("Enter weight for the edge : ");
                        scanf("%d", &wt);
                }
                addedge(g, src, dest, wt);
                printf("\nEnter 1 to add more edges, 0 to finish taking edges : ");
                scanf("%d", &choice);
        }
        return g;
}

void freelist(node *head)
{
        if(head -> next != NULL)
                freelist(head -> next);
        free(head);
}

void deletevertex(graph *g, int num)
{
        int n = g -> numberofvertices, i;
        node *temp, *temp1;
        if(num < n)
        {
                --n;
                g -> nodes[num] . value = g -> nodes[n] . value;
                freelist(g -> nodes[num] . child);
                g -> nodes[num] . child = g -> nodes[n] . child;
                g -> nodes[num] . child -> index = num;
                g -> numberofvertices = n;
                g -> nodes = (listnode *)realloc(g -> nodes, n * sizeof(listnode));
                for(i = 0 ; i < n ; ++i)
                {
                        temp = g -> nodes[i] . child;
                        while(temp -> next != NULL)
                        {
                                if(temp -> next -> index == num)
                                {
                                        temp1 = temp -> next;
                                        temp -> next = temp1 -> next;
                                        free(temp1);
                                }
                                else
                                {
                                        if(temp -> next -> index == n)
                                                temp -> next -> index = num;
                                        temp = temp -> next;
                                }
                        }
                }
                printf("Node deleted successfully!");
        }
        else
                printf("Invalid data!");
}

void deleteedge(graph *g, int src, int dest)
{
        int n = g -> numberofvertices;
        if(src < n && dest < n && src != dest)
        {
                node *temp = g -> nodes[src] . child;
                while(temp -> next != NULL && temp -> next -> index != dest)
                        temp = temp -> next;
                if(temp -> next != NULL)
                {
                        node *temp1 = temp -> next;
                        temp -> next = temp1 -> next;
                        free(temp1);
                        if(g -> isdirected == 0)
                        {
                                node *temp = g -> nodes[dest] . child;
                                while(temp -> next -> index != src)
                                        temp = temp -> next;
                                temp1 = temp -> next;
                                temp -> next = temp1 -> next;
                                free(temp1);
                        }
                }
                else
                        printf("Edge not found!");
        }
        else
                printf("Invalid data!");
}

void BreadthFirstTraversal(graph *g)
{
        int i, n = g -> numberofvertices;
        int q[n], front = 0, rear = 0, visited[n];
        node *temp;
        for(i = 0 ; i < n ; ++i)
                visited[i] = 0;
        printf("\nBreadth First Traversal : ");
        for(i = 0 ; i < n ; ++i)
        {
                if(visited[i] == 0)
                {
                        q[rear] = i;
                        visited[i] = 1;
                        ++rear;
                        while(front != rear)
                        {
                                temp = g -> nodes[front] . child -> next;
                                while(temp != NULL)
                                {
                                        if(visited[temp -> index] == 0)
                                        {
                                                q[rear] = temp -> index;
                                                visited[q[rear]] = 1;
                                                ++rear;
                                        }
                                        temp = temp -> next;
                                }
                                printf("%d ", g -> nodes[q[front]] . value);
                                ++front;
                        }
                }
        }
}

void DFTVisit(graph *g, int visited[], int i)
{
        printf("%d ", g -> nodes[i] . value);
        visited[i] = 1;
        node *temp = g -> nodes[i] . child -> next;
        while(temp != NULL)
        {
                if(visited[temp -> index] == 0)
                        DFTVisit(g, visited, temp -> index);
                temp = temp -> next;
        }
}

void DepthFirstTraversal(graph *g)
{
        int i, n = g -> numberofvertices;
        int visited[n];
        for(i = 0 ; i < n ; ++i)
                visited[i] = 0;
        printf("\nDepth First Traversal : ");
        for(i = 0 ; i < n ; ++i)
                if(visited[i] == 0)
                        DFTVisit(g, visited, i);
}

void TopologicalSort(graph *g)
{
        int n = g -> numberofvertices;
        int i, indegree[n], q[n], front = 0, rear = 0;
        node *temp;
        for(i = 0 ; i < n ; ++i)
                indegree[i] = 0;
        for(i = 0 ; i < n ; ++i)
        {
                temp = g -> nodes[i] . child -> next;
                while(temp != NULL)
                {
                        indegree[temp -> index] += 1;
                        temp = temp -> next;
                }
        }
        for(i = 0 ; i < n ; ++i)
                if(indegree[i] == 0)
                {
                        q[rear] = i;
                        ++rear;
                }
        while(front != rear)
        {
                temp = g -> nodes[q[front]] . child -> next;
                --(indegree[q[front]]);
                while(temp != NULL)
                {
                        indegree[temp -> index] -= 1;
                        if(indegree[temp -> index] == 0)
                        {
                                q[rear] = temp -> index;
                                ++rear;
                        }
                        temp = temp -> next;
                }
                ++front;
        }
        if(rear == n)
        {
                printf("\nTopological Sort : ");
                for(i = 0 ; i < n ; ++i)
                        printf("%d ", g -> nodes[q[i]] . value);
        }
        else
                printf("\nGraph is not a Directly Acyclic Graph(DAG)!");
}

void DFSforisconnected(graph *g1, graph* g2, int visit1[], int visit2[], int i)
{
        visit1[i] = 1;
        node *temp = g1 -> nodes[i] . child -> next;
        while(temp != NULL)
        {
                if(visit1[temp -> index] == 0)
                {
                        DFSforisconnected(g1, g2, visit1, visit2, temp -> index);
                        DFSforisconnected(g2, g1, visit2, visit1, temp -> index);
                }
                temp = temp -> next;
        }
}

void isconnected(graph *g)
{
        int n = g -> numberofvertices;
        int visit1[n], visit2[n], i, f = 1;
        for(i = 0 ; i < n ; ++i)
        {
                visit1[i] = 0;
                visit2[i] = 0;
        }
        graph *g1 = (graph *)malloc(sizeof(graph));
        node *temp, *temp1;
        g1 -> nodes = (listnode *)malloc(n * sizeof(listnode));
        for(i = 0 ; i < n ; ++i)
        {
                temp = (node *)malloc(sizeof(node));
                temp -> index = i;
                temp -> next = NULL;
                g1 -> nodes[i] . child = temp;
        }
        for(i = 0 ; i < n ; ++i)
        {
                temp = g -> nodes[i] . child -> next;
                while(temp != NULL)
                {
                        temp1 = (node *)malloc(sizeof(node));
                        temp1 -> index = i;
                        temp1 -> next = g1 -> nodes[temp -> index] . child -> next;
                        g1 -> nodes[temp -> index] . child -> next = temp1;
                        temp = temp -> next;
                }
        }
        DFSforisconnected(g, g1, visit1, visit2, 0);
        DFSforisconnected(g1, g, visit2, visit2, 0);
        for(i = 0 ; i < n && f ; ++i)
                if(visit1[i] == 0 && visit2[i] == 0)
                        f = 0;
        if(f)
                printf("\nGraph is connected");
        else
                printf("\nGraph is disconnected");
}

void printpath(int parent[], int s, int u)
{
        if(u == s)
                printf(" %d", s);
        else
        {
                printpath(parent, s, parent[u]);
                printf(" -> %d", u);
        }
}

void ShortestPath(graph *g, int s)
{
        int n = g -> numberofvertices;
        int dist[n], found[n], cost[n][n], parent[n], i, j, k, min;
        node *temp;
        for(i = 0 ; i < n ; ++i)
                for(j = 0 ; j < n ; ++j)
                        cost[i][j] = INT_MAX;
        for(i = 0 ; i < n ; ++i)
        {
                temp = g -> nodes[i] . child;
                while(temp != NULL)
                {
                        cost[i][temp -> index] = temp -> weight;
                        temp = temp -> next;
                }
        }
        for(i = 0 ; i < n ; ++i)
        {
                found[i] = 0;
                dist[i] = cost[s][i];
                parent[i] = s;
        }
        found[s] = 1;
        for(i = 0 ; i < n - 2 ; ++i)
        {
                min = INT_MAX;
                for(j = 0 ; j < n ; ++j)
                        if(found[j] == 0 && dist[j] < min)
                        {
                                min = dist[j];
                                k = j;
                        }
                found[k] = 1;
                for(j = 0 ; j < n ; ++j)
                        if(found[j] == 0 && (dist[k] + cost[k][j]) > 0 && (dist[k] + cost[k][j] < dist[j]))
                        {
                                dist[j] = dist[k] + cost[k][j];
                                parent[j] = k;
                        }
        }
        printf("Shortest distance to other nodes from source %d(%d) :", g -> nodes[s] . value, s);
        for(i = 0 ; i < n ; ++i)
        {
                printf("\n%d(%d) = ", g -> nodes[i] . value, i);
                if(dist[i] != INT_MAX)
                {
                        printf("%d, Path : ", dist[i]);
                        printpath(parent, s, i);
                }
                else
                        printf("Not Reachable");
        }
}

void ShortestDistancePairOfNodes(graph *g, int src, int dest)
{
        int n = g -> numberofvertices;
        int dist[n], found[n], cost[n][n], parent[n], i, j, k, min;
        node *temp;
        for(i = 0 ; i < n ; ++i)
                for(j = 0 ; j < n ; ++j)
                        cost[i][j] = INT_MAX;
        for(i = 0 ; i < n ; ++i)
        {
                temp = g -> nodes[i] . child;
                while(temp != NULL)
                {
                        cost[i][temp -> index] = temp -> weight;
                        temp = temp -> next;
                }
        }
        for(i = 0 ; i < n ; ++i)
        {
                found[i] = 0;
                dist[i] = cost[src][i];
                parent[i] = src;
        }
        found[src] = 1;
        for(i = 0 ; i < n - 2 && found[dest] == 0 ; ++i)
        {
                min = INT_MAX;
                for(j = 0 ; j < n ; ++j)
                        if(found[j] == 0 && dist[j] < min)
                        {
                                min = dist[j];
                                k = j;
                        }
                found[k] = 1;
                for(j = 0 ; j < n ; ++j)
                        if(found[j] == 0 && (dist[k] + cost[k][j]) > 0 && (dist[k] + cost[k][j] < dist[j]))
                        {
                                dist[j] = dist[k] + cost[k][j];
                                parent[j] = k;
                        }
        }
        if(dist[dest] != INT_MAX)
        {
                printf("Shortest distance from node %d(%d) to %d(%d) = %d\nPath : ", g -> nodes[src] . value, src, g -> nodes[dest] . value, dest, dist[dest]);
                printpath(parent, src, dest);
        }
        else
                printf("Not Reachable");
}

void BreadthFirstSearch(graph *g, int num)
{
        int i, n = g -> numberofvertices;
        int q[n], front = 0, rear = 0, visited[n];
        node *temp;
        for(i = 0 ; i < n ; ++i)
                visited[i] = 0;
        for(i = 0 ; i < n && num != INT_MAX ; ++i)
        {
                if(visited[i] == 0)
                {
                        q[rear] = i;
                        visited[i] = 1;
                        ++rear;
                        while(front != rear && num != INT_MAX)
                        {
                                temp = g -> nodes[front] . child;
                                while(temp != NULL && num != INT_MAX)
                                {
                                        if(g -> nodes[temp -> index] . value == num)
                                        {
                                                printf("%d found at node number %d", num, temp -> index);
                                                num = INT_MAX;
                                        }
                                        else if(visited[temp -> index] == 0)
                                        {
                                                q[rear] = temp -> index;
                                                visited[q[rear]] = 1;
                                                ++rear;
                                        }
                                        temp = temp -> next;
                                }
                                ++front;
                        }
                }
        }
        if(num != INT_MAX)
                printf("Value not found in graph!");
}

void DFSVisit(graph *g, int visited[], int i, int *num)
{
        visited[i] = 1;
        node *temp = g -> nodes[i] . child;
        while(temp != NULL && (*num) != INT_MAX)
        {
                if(g -> nodes[temp -> index] . value == (*num))
                {
                        printf("%d found at node number %d", (*num), temp -> index);
                        (*num) = INT_MAX;
                }
                else if(visited[temp -> index] == 0)
                        DFSVisit(g, visited, temp -> index, num);
                temp = temp -> next;
        }
}

void DepthFirstSearch(graph *g, int num)
{
        int i, n = g -> numberofvertices;
        int visited[n];
        for(i = 0 ; i < n ; ++i)
                visited[i] = 0;
        for(i = 0 ; i < n && num != INT_MAX ; ++i)
                if(visited[i] == 0)
                        DFSVisit(g, visited, i, &num);
        if(num != INT_MAX)
                printf("Value not found in graph!");
}

int DFSVisitiscyclicdirected(graph *g, int visited[], int visitedtemp[], int i)
{
        visited[i] = 1;
        visitedtemp[i] = 1;
        int retval = 0;
        node *temp = g -> nodes[i] . child -> next;
        while(temp != NULL && retval != 1)
        {
                if(visited[temp -> index] == 0)
                        retval = DFSVisitiscyclicdirected(g, visited, visitedtemp, temp -> index);
                else if(visitedtemp[temp -> index] == 1)
                        retval = 1;
                temp = temp -> next;
        }
        if(retval != 1)
                visitedtemp[i] = 0;
        return retval;
}

int DFSVisitiscyclicundirected(graph *g, int visited[], int i, int parent)
{
        visited[i] = 1;
        int retval = 0;
        node *temp = g -> nodes[i] . child -> next;
        while(temp != NULL && retval != 1)
        {
                if(visited[temp -> index] == 0)
                        retval = DFSVisitiscyclicundirected(g, visited, temp -> index, i);
                else if(parent != temp -> index)
                        retval = 1;
                temp = temp -> next;
        }
        return retval;
}

void iscyclic(graph *g)
{
        int n = g -> numberofvertices;
        int visited[n], visitedtemp[n], i, cyclic = 0;
        for(i = 0 ; i < n ; ++i)
        {
                visited[i] = 0;
                visitedtemp[i] = 0;
        }
        if(g -> isdirected)
        {
                for(i = 0 ; i < n && cyclic == 0 ; ++i)
                        if(visited[i] == 0)
                                if(DFSVisitiscyclicdirected(g, visited, visitedtemp, i) == 1)
                                        cyclic = 1;
        }
        else
                for(i = 0 ; i < n && cyclic == 0 ; ++i)
                        if(visited[i] == 0)
                                if(DFSVisitiscyclicundirected(g, visited, i, -1) == 1)
                                        cyclic = 1;
        if(cyclic == 1)
                printf("\nGraph is cyclic");
        else
                printf("\nGraph is acyclic");
}

void MinSpanningTree(graph *g)
{
        int n = g -> numberofvertices, noe = 0;
        int selected[n], i, min = 1, minsrc, mindest, totalcost = 0, selectededges[n - 1][2];
        node *temp;
        if(g -> isdirected == 0)
        {
                for(i = 0 ; i < n ; ++i)
                        selected[i] = 0;
                selected[0] = 1;
                while(noe < (n - 1) && min != INT_MAX)
                {
                        min = INT_MAX;
                        for(i = 0 ; i < n ; ++i)
                        {
                                if(selected[i])
                                {
                                        temp = g -> nodes[i] . child -> next;
                                        while(temp != NULL)
                                        {
                                                if(selected[temp -> index] == 0 && temp -> weight < min)
                                                {
                                                        min = temp -> weight;
                                                        minsrc = i;
                                                        mindest = temp -> index;
                                                }
                                                temp = temp -> next;
                                        }
                                }
                        }
                        if(min < INT_MAX)
                        {
                                totalcost += min;
                                selected[mindest] = 1;
                                selectededges[noe][0] = minsrc;
                                selectededges[noe][1] = mindest;
                                ++noe;
                        }
                }
                printf("\nMinimum spanning tree edges = ");
                if(noe == (n - 1))
                        for(i = 0 ; i < n - 1 ; ++i)
                                printf(" %d(%d)--%d(%d) ", g -> nodes[selectededges[i][0]] . value, selectededges[i][0], g -> nodes[selectededges[i][1]] . value, selectededges[i][1]);
                else
                        printf("Minimum Spanning Tree does not exist!");
        }
        else
                printf("\nMinimum spanning tree not possible for directed graph");
}

void DFSVisitprintallpath(graph *g, int src, int dest, int visited[], int path[], int *pathindex)
{
        int i;
        visited[src] = 1;
        path[*pathindex] = src;
        ++(*pathindex);
        if(src == dest)
        {
                for(i = 0 ; i < *pathindex ; ++i)
                        printf("%d ", path[i]);
                printf("\n");
        }
        else
        {
                node *temp = g -> nodes[src] . child -> next;
                while(temp != NULL)
                {
                        if(visited[temp -> index] == 0)
                                DFSVisitprintallpath(g, temp -> index, dest, visited, path, pathindex);
                        temp = temp -> next;
                }
        }
        --(*pathindex);
        visited[src] = 0;
}

void printallpath(graph *g, int src, int dest)
{
        int n = g -> numberofvertices;
        int visited[n], path[n], pathindex = 0, i;
        for(i = 0 ; i < n ; ++i)
                visited[i] = 0;
        DFSVisitprintallpath(g, src, dest, visited, path, &pathindex);
}

int main()
{
        int n, n1, wt, choice = 1;
        printf("Enter number of vertices : ");
        scanf("%d", &n);
        graph *g = creategraph(n);
        printList(g);
        while(choice)
        {
                printf("\n\nEnter 1 to add vertex");
                printf("\nEnter 2 to delete a vertex");
                printf("\nEnter 3 to add edge");
                printf("\nEnter 4 to delete edge");
                printf("\nEnter 5 for Depth First Traversal of graph");
                printf("\nEnter 6 for Breadth First Traversal of graph");
                printf("\nEnter 7 for Topological sort of graph");
                printf("\nEnter 8 to check whether graph is connected or disconnected");
                printf("\nEnter 9 to print shortest path and path cost between a fixed source to all other vertices");
                printf("\nEnter 10 to print shortest path and path cost between two vertices");
                printf("\nEnter 11 to search a value in graph via depth first search");
                printf("\nEnter 12 to search a value in graph via breadth first search");
                printf("\nEnter 13 to detect whether there is cycle in the graph");
                printf("\nEnter 14 to print edges of the minimum spanning tree of the graph");
                printf("\nEnter 15 to display all possible paths between a pair of vertices");
                printf("\nEnter 16 to print adjacency list of the graph");
                printf("\nEnter any other number to exit");
                printf("\nEnter choice : ");
                scanf("%d", &choice);
                switch(choice)
                {
                        case 1: printf("Enter value of the vertex : ");
                                scanf("%d", &n);
                                addvertex(g, n);
                                break;
                        case 2: printf("Enter node number of vertex to delete : ");
                                scanf("%d", &n);
                                deletevertex(g, n);
                                break;
                        case 3: printf("Enter source node number of the vertex : ");
                                scanf("%d", &n);
                                printf("Enter destination node number of the vertex : ");
                                scanf("%d", &n1);
                                wt = 1;
                                if(g -> isweighted == 1)
                                {
                                        printf("Enter weight of the edge : ");
                                        scanf("%d", &wt);
                                }
                                addedge(g, n, n1, wt);
                                break;
                        case 4: printf("Enter source node number of the vertex : ");
                                scanf("%d", &n);
                                printf("Enter destination node number of the vertex : ");
                                scanf("%d", &n1);
                                deleteedge(g, n, n1);
                                break;
                        case 5: DepthFirstTraversal(g);
                                break;
                        case 6: BreadthFirstTraversal(g);
                                break;
                        case 7: TopologicalSort(g);
                                break;
                        case 8: isconnected(g);
                                break;
                        case 9: printf("Enter source node number to search shortest distance from : ");
                                scanf("%d", &n);
                                ShortestPath(g, n);
                                break;
                        case 10: printf("Enter source node number : ");
                                scanf("%d", &n);
                                printf("Enter destination node number : ");
                                scanf("%d", &n1);
                                ShortestDistancePairOfNodes(g, n, n1);
                                break;
                        case 11: printf("Enter the value to search in graph : ");
                                scanf("%d", &n);
                                DepthFirstSearch(g, n);
                                break;
                        case 12: printf("Enter the value to search in graph : ");
                                scanf("%d", &n);
                                BreadthFirstSearch(g, n);
                                break;
                        case 13: iscyclic(g);
                                break;
                        case 14: MinSpanningTree(g);
                                break;
                        case 15: printf("Enter source node number : ");
                                scanf("%d", &n);
                                printf("Enter destination node number : ");
                                scanf("%d", &n1);
                                printallpath(g, n, n1);
                                break;
                        case 16: printList(g);
                                break;
                        default: choice = 0;
                }
        }
        return 0;
}