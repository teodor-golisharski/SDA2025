#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class WeightedEdge {
	int f, t, w; 
public:
    WeightedEdge(int from, int to, int weight)
        : f(from), t(to), w(weight) {
    }
	int from() const { return f; }
	int to() const { return t; }
	int weight() const { return w; }
};

class Graph {
	int numVertices;
	vector<vector<WeightedEdge>> adjList;
	bool directed;

public:
	Graph(int V, bool directed) 
		: numVertices(V), adjList(V), directed(directed) {}

	void addEdge(int from, int to, int weight) {
		adjList[from].push_back(WeightedEdge(from, to, weight));
		if (!directed) {
			adjList[to].push_back(WeightedEdge(from, to, weight));
		}
	}

	const vector<WeightedEdge>& adj(int v) const {
		return adjList[v];
	}

	int vertices() const {
		return numVertices;
	}
};

class Dijkstra {
    static const int INF = 1e9;

    const Graph& graph;
    vector<int> distTo;
    vector<int> edgeTo;

public:
    Dijkstra(const Graph& g) : graph(g) {
        distTo.assign(graph.vertices(), INF);
        edgeTo.assign(graph.vertices(), -1);
    }

    bool relax(const WeightedEdge& e) {
        int v = e.from();
        int u = e.to();

        if (distTo[v] == INF) return false;

        int candidate = distTo[v] + e.weight();
        if (distTo[u] > candidate) {
            distTo[u] = candidate;
            edgeTo[u] = v;
            return true;
        }
        return false;
    }

    void shortestPath(int from) {
        vector<bool> visited(graph.vertices(), false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

        distTo[from] = 0;
        pq.push({ 0, from });

        while (!pq.empty()) {
            int v = pq.top().second;
            pq.pop();

            if (visited[v]) continue;
            visited[v] = true;

            for (const WeightedEdge& e : graph.adj(v)) {
                if (relax(e)) {
                    pq.push({ distTo[e.to()], e.to() });
                }
            }
        }
    }

    int distanceTo(int v) const {
        return distTo[v];
    }
};


int main() {
    // Създаваме граф с 5 върха, ненасочен
    Graph g(5, false);

    // Добавяме ребра (u, v, weight)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    // Пускаме Дийкстра от връх 0
    Dijkstra d(g);
    d.shortestPath(0);

    // Печатаме най-късите разстояния
    for (int v = 0; v < g.vertices(); v++) {
        cout << "Distance from 0 to " << v << " = "
            << d.distanceTo(v) << "\n";
    }

    return 0;
}
