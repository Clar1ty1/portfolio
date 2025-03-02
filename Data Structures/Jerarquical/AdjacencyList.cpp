#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Graph{

    vector< vector<int> > adjList;

    public:

        Graph(int n){
            adjList = vector< vector<int> >(n);
        }

        void addEdge(int origin, int destination){
            adjList[origin].push_back(destination);

            // This makes it an undirected graph
            adjList[destination].push_back(origin);
        }

        void BFS(int start){
            queue<int> queue;

            vector<bool> visited(adjList.size(), false);

            visited[start] = true;
            queue.push(start);

            while( !queue.empty() ){
                int current = queue.front();
                queue.pop();

                cout << current << " ";

                for( int x : adjList[current] ){
                    if( !visited[x] ){
                        visited[x] = true;
                        queue.push(x);
                    }
                }
            }
        }

        void DFS(int start){
            stack<int> stack;

            vector<bool> visited(adjList.size(), false);

            visited[start] = true;
            stack.push(start);

            while( !stack.empty() ){
                int current = stack.top();
                stack.pop();

                cout << current << " ";

                for( int x : adjList[current] ){
                    if( !visited[x] ){
                        visited[x] = true;
                        stack.push(x);
                    }
                }
            }
        }

};


int main() 
{

    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);  
    graph.BFS(0);
    cout << endl;
    graph.DFS(0);

    return 0;
}
