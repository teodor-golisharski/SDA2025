#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph {
    int numVertices;
    vector<vector<int>> adjList;
    bool directed;

public:
    Graph(int V, bool directed)
        : numVertices(V), adjList(V), directed(directed) {
    }

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        if (!directed) {
            adjList[w].push_back(v);
        }
    }

    const vector<int>& adj(int v) const {
        return adjList[v];
    }

    int vertices() const {
        return numVertices;
    }
};

class GraphTraversal {
    Graph& g;
    vector<bool> visited;

public:
    GraphTraversal(Graph& g) : g(g), visited(g.vertices(), false) {}

    // Recursive DFS
    void dfs(int v) {
        visited[v] = true;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                dfs(w);
            }
        }
    }

    // Iterative DFS
    void dfsIterative(int start) {
        stack<int> st;
        st.push(start);

        while (!st.empty()) {
            int v = st.top();
            st.pop();

            if (visited[v]) continue;

            visited[v] = true;
            for (int w : g.adj(v)) {
                if (!visited[w]) {
                    st.push(w);
                }
            }
        }
    }

    // BFS
    void bfs(int start) {
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int w : g.adj(v)) {
                if (!visited[w]) {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
    }
};

class Solution {
public:
    void dfs(vector<vector<int>>& graph, 
        int target, 
        vector<vector<int>>& allPaths, 
        vector<int>& currentPath, 
        int currentNode) {
	    
		currentPath.push_back(currentNode);

        if (currentNode == target) {
			allPaths.push_back(currentPath);
        }
        else {
            for (int& nextNode : graph[currentNode]) {
				dfs(graph, target, allPaths, currentPath, nextNode);
            }
        }

		currentPath.pop_back();
    }



    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> allPaths;
		vector<int> currentPath;

        int source = 0;
		int target = graph.size() - 1;

        dfs(graph, target, allPaths, currentPath, source);

        return allPaths;
    }
};

int main()
{
    
}