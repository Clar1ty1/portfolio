#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph{
    vector< vector<int> > adjacencyMatrix;

    public:
    Graph(int n){
        adjacencyMatrix = vector< vector<int> >(n, vector<int>(n, 0));
    }

    void print(){
        // Get the number of vertices
        cout << "Adjacency Matrix for the Graph: " << endl;
        int n = adjacencyMatrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int u, int v){
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

    void BFS(int start){
        queue<int> queue;

        vector<bool> visited(adjacencyMatrix.size(), false);

        visited[start] = true;
        queue.push(start);

        while( !queue.empty() ){
            int current = queue.front();
            queue.pop();

            cout << current << " ";

            for( int x = 0; x < adjacencyMatrix[current].size(); x++ ){
                if( !visited[x] && adjacencyMatrix[current][x] == 1 ){
                    visited[x] = true;
                    queue.push(x);
                }
            }
        }
    }

    void DFS(int start){
        stack<int> stack;

        vector<bool> visited(adjacencyMatrix.size(), false);

        visited[start] = true;
        stack.push(start);

        while( !stack.empty() ){
            int current = stack.top();
            stack.pop();

            cout << current << " ";

            for( int x = 0; x < adjacencyMatrix[current].size(); x++ ){
                
                if( !visited[x] && adjacencyMatrix[current][x] == 1 ){
                    visited[x] = true;
                    stack.push(x);
                }
            }
        }
    }


};



int main(){
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 4);
    graph.addEdge(1, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);  
    graph.addEdge(3, 5);   
    graph.BFS(0);
    cout << endl;
    graph.DFS(0);

    cout << endl;

    graph.print();
    return 0;
}