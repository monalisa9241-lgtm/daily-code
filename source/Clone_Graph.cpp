// Given a reference of a node in a connected undirected graph. Return a deep copy (clone) of the graph.
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
// Number of nodes: up to 10^4, Node values are unique, No parallel/repeated edges, No self - loops

// Edge Case: empty graph, single node graph, general case, graph with cycles

// Time Complexity: O(V+E) where V is the number of vertices (nodes) and E is the number of edges in the graph. We visit each node once to create a copy and establish neighbor relationships.
// Space Complexity: O(V) for the hash map to store the mapping of original nodes to their clones, and O(V) for the recursion stack in the worst case (if the graph is a linear chain).

// Production code: 
// - Use Iterative BFS or DFS with explicit queue or stack to avoid potential stack overflow with deep recursion in large graphs.
// Using node value as the visited/hashmap key is risky because node values are data, not identity.
// a real graph system, uniqueness is often not guaranteed.

#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//Iterative DFS with explicit stack and hashmap to avoid recursion depth issues in large graphs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr; // Edge case: empty graph
		}

        unordered_map<Node*, Node*> node_map; // Map original nodes to their clones
        stack<Node*> dfsStack; // Stack for DFS
        dfsStack.push(node);
        node_map[node] = new Node(node->val); // Clone the starting node
        while (!dfsStack.empty()) {
            Node* curr = dfsStack.top();
            dfsStack.pop();
            for (Node* neighbor : curr->neighbors) {
                if (node_map.find(neighbor) == node_map.end()) {
                    // Neighbor not cloned yet, clone it and add to stack
                    node_map[neighbor] = new Node(neighbor->val);
                    dfsStack.push(neighbor);
                }
                // Add the cloned neighbor to the current cloned node's neighbors
                node_map[curr]->neighbors.push_back(node_map[neighbor]);
            }
        }
		return node_map[node]; // Return the clone of the starting node
    }
};
