//https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/

//C++ program to print DFS traversal from
//a given vertex in a given graph

#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V; //Num of vertices

    //Pointer to an array containing
    //adjacency lists
    list<int> *adj;
    //a recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);//constructor
    //function to add an edge to graph
    void addEdge(int v, int w);
    //DFS traversal of the vertices
    //reachable from v
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    //within the [ ] indicates the size for the list
    adj = new list<int>[V];
}
//v, w are indices representing vertices, not the value stored inside vertices
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]){
    //mark the current node as visited and print it
    visited[v] = true;
    cout<<v<<" "<<endl;
    //REcur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i=adj[v].begin(); i!= adj[v].end(); i++){
        if(!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
}
//DFS traversal of the vertices reachable from v
//it uses recursive DFSUtil()

//return one single traversal
void Graph::DFS(int v){
    //mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i<V; i++){
        visited[i]= false;
    }
    //call the recursive helper function to print a single DFS traversal
    DFSUtil(v, visited);
}

int main()
{
    int V = 5;
    list<int> *adj = new list<int>[V];

    adj[0].push_back(5);
    for(int val: adj[0]){
        cout<<val<<endl;
    }



    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) "<<endl;
    g.DFS(2);

    return 0;
}