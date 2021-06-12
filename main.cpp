#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool dfs(int curr, int goal, unordered_map< int, vector<int> >& graph, unordered_set<int>& visited) {
    // base case
    if (curr == goal) return true;
    
    // Add current node to the visited list
    visited.insert(curr);
    
    if (!graph.count(curr) || !graph.count(goal)) return false;
    
    // Search through each neighbors of current node
    for (auto next:graph[curr]) {
        // Skip any node that was visited
        if (visited.count(next)) continue;
        
        if (dfs(next, goal, graph, visited)) return true;
    }
    return false;
}

vector<int> findRedundantConnection(vector< vector<int> >& edges) {
    unordered_map< int, vector<int> > graph;
    
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        unordered_set<int> visited;
        // Search if current nodes has any path to each other
        if (dfs(u, v, graph, visited))
            return edges[i];
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return {};
}

int main() {
	vector< vector<int> > input;

    input.push_back({1, 2});
    input.push_back({2, 3});
    input.push_back({1, 4});
    input.push_back({2, 5});
    input.push_back({4, 5});

	vector<int> ans = findRedundantConnection(input);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
    cout << endl;

	return 0;
}
