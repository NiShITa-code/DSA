/*
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
*/

class Solution {
public:
    // map which stores copy of node
    unordered_map<Node*, Node*> copies;
    Node* cloneGraph(Node* node) {
        if(!node) {
            return NULL;
        }    
        //DFS
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val, {});
            for (Node* neighbor: node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
        
        /*BFS
        //creating the copy of first node
        Node* copy = new Node(node->val, {});
        //storing this copy in map 
        copies[node] = copy;
        //bfs
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (Node* neighbor: curr-> neighbors) {
                //if neighbor's copy has not already been made make a copy
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                // make a connection between current node and its neighbors
                copies[curr]-> neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;*/
    

    }
};
