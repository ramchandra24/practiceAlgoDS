#include <iostream>
#include <iomanip>

using namespace std;

class Graph
{
    int numVertex;
    int ** adj;
    int * vis;
    int * ddist;

public :
    Graph(int numV);
    void addNode(int u, int v, int wt);
    void print();
    bool isVisited(int u);
    void Dijkstra(int source);
    int getNextNearNode();
    void markVisited(int u);
    bool allVisited();
};

bool Graph :: isVisited(int u)
{
    return (vis[u] == 0 ? false : true);
}

Graph :: Graph(int numV)
{
    numVertex = numV;
    adj = new int*[numVertex];
    for(int i=0; i<numVertex; i++)
    {
        adj[i] = new int[numVertex];
    }

    for(int i=0; i<numVertex; i++)
    {
        for(int j=0; j<numVertex; j++)
        {
                if(i == j)
                    adj[i][j] = 0;
                else
                    adj[i][j] = INT_MAX;
        }
    }
    vis = new int[numVertex];
    ddist = new int[numVertex];
    for(int i=0; i<numVertex; i++)
    {
        vis[i] = 0;
        ddist[i] = INT_MAX;
    }
}


void Graph :: markVisited(int u)
{
    vis[u] = 1;
}

bool Graph :: allVisited()
{
    for(int i=0; i<numVertex; i++)
    {
        if(!isVisited(i))
            return false;
    }
    return true;
}

void Graph :: Dijkstra(int source)
{
    ddist[source] = 0;
    int curr;

    do
    {
        curr = getNextNearNode();
        if(-1 == curr)
            break;
        markVisited(curr);
        for(int i=0; i<numVertex; i++)
        {
            if(curr == i)
                continue;
            if(adj[curr][i] == INT_MAX)
                continue;
            if(adj[curr][i] + ddist[curr] < ddist[i])
            {
                ddist[i] = adj[curr][i] + ddist[curr];
            }
        }
    }while(!allVisited());
}

void Graph :: print()
{
    cout << endl << "Graph adjacency matrix : ";
    for(int i=0; i<numVertex; i++)
    {
        cout << endl;
        for(int j=0; j<numVertex; j++)
        {
            cout << setw(12) << adj[i][j];
        }
    }
    cout << endl;

    cout << endl << "Shortest distance to nodes : " << endl;
    for(int i=0; i<numVertex; i++)
    {
        cout << ddist[i] << " ";
    }
    cout << endl;
}


int Graph :: getNextNearNode()
{
    int near = -1;
    int i = 0;
    while(i < numVertex)
    {
        if(isVisited(i))
        {
            i++;
            continue;
        }
        near = i;
        i++;
        break;

    }
    while(i < numVertex)
    {
        if(isVisited(i))
        {
            i++;
            continue;
        }
        if(ddist[near] >= ddist[i])
        {
            near = i;
        }
        i++;
    }
    return near;
}

void Graph :: addNode(int u, int v, int wt)
{
    adj[u][v] = adj[v][u] = wt;
}


int main()
{
    Graph G(6);
    G.addNode(0,1,1);
    G.addNode(1,2,1);
    G.addNode(0,2,2);
    G.addNode(1,4,2);
    G.addNode(2,3,3);
    G.addNode(3,5,5);
    G.addNode(4,5,8);

    G.Dijkstra(2);

    G.print();

    return 0;
}

