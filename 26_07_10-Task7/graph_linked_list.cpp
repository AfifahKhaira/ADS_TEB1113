#include <iostream>
#include <climits>
using namespace std;

// Represents an adjacent node in the adjacency list linked list
struct EdgeNode {
    int vtx;            // Destination vertex
    int weight;         // Cost/Weight of the edge
    EdgeNode* next;     // Pointer to the next edge in the list

    // Member initializer list constructor
    EdgeNode(int v, int w) : vtx(v), weight(w), next(nullptr) {}
};

class Graph {
private:
    int V;              // Total number of vertices
    EdgeNode** head;    // Pointer to an array of EdgeNode pointers (Adjacency List)

public:
    // Constructor: Allocates dynamic array for V adjacency lists
    Graph(int V) {
        this->V = V;
        head = new EdgeNode*[V];
        for (int i = 0; i < V; i++) {
            head[i] = nullptr;
        }
    }

    // Adds an undirected edge between u and vtx with the given weight
    void addEdge(int u, int vtx, int weight) {
        // Insert node at the front of u's linked list
        EdgeNode* n1 = new EdgeNode(vtx, weight);
        n1->next = head[u];
        head[u] = n1;

        // Since the graph is undirected, insert reverse direction (vtx -> u)
        EdgeNode* n2 = new EdgeNode(u, weight);
        n2->next = head[vtx];
        head[vtx] = n2;
    }

    // Helper: Finds the unvisited vertex with the minimum distance value
    int minDistance(int* dist, bool* visited) {
        int minVal = INT_MAX;
        int minIndex = -1; 

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] <= minVal) {
                minVal = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    // Computes shortest distance from source vertex to all other vertices
    int* dijkstra(int src) {
        int* dist = new int[V];
        bool* visited = new bool[V];

        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }
        
        // Distance to the source itself is always 0
        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            // Pick the minimum distance vertex from the set of unvisited vertices
            int u = minDistance(dist, visited);
            
            // If u is -1, remaining nodes are unreachable
            if (u == -1) break;
            
            visited[u] = true;

            // Update distance values of adjacent vertices of the picked vertex
            for (EdgeNode* current = head[u]; current != nullptr; current = current->next) {
                int neighbor = current->vtx;
                int weight = current->weight;

                // Relaxation step
                if (!visited[neighbor] && dist[u] != INT_MAX && dist[u] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[u] + weight;
                }
            }
        }

        delete[] visited; // Clean up temporary boolean array
        return dist;      // Caller is responsible for deleting dist[]
    }

    // Destructor: Safely deallocates linked lists and head array
    ~Graph() {
        for (int i = 0; i < V; i++) {
            EdgeNode* current = head[i];
            while (current != nullptr) {
                EdgeNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] head;
    }   
};

int main() {
    // Initialize a 6-node graph (0 to 5)
    Graph g(6);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 5);

    int sourceNode = 0;
    int* distances = g.dijkstra(sourceNode);

    cout << "Shortest distances from Source (Node " << sourceNode << "):\n";
    for (int i = 0; i < 6; i++) {
        cout << "To Node " << i << " : " << distances[i] << "\n";
    }

    delete[] distances; // Free dynamically allocated memory in dijkstra()
    return 0;
}