#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool dfs(int curr, int goal, vector<vector<int>>& nums, unordered_set<int> visited) {
	// Base case
	if (curr == goal) 
		return true;

	// Add current node to the visited list
	visited.insert(curr);

	if (!graph.count(curr) || !graph.count(goal)) 
		return false;
	
	// Search through each neighbors of current node
	for (const int next:graph[curr]) {
		// Skip any node that was visited
		if (visited.count(next))
			continue;
		
		if (dfs(next, goal, nums, visited))
			return true;
	}
	return false;
}

vector<int> findRedundantConnection(vector<vector<int>>& nums) {
	unordered_map<int, vector<int>> graph;
	for (const auto& num:nums) {
		int node1 = num[0];
		int node2 = num[1];
		
		unordered_set<int> visited;
		// Search if current nodes have any path to each other
		if (dfs(node1, node2, nums, visited)}
			return num;

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	return {};
}

int main() {
	vector<vector<int>> input;

	input.push_back({1, 2});
	input.push_back({2, 3});
	input.push_back({1, 4});
	input.push_back({2, 5});
	input.push_back({4, 5});

	vector<int> ans = findRedundantConnection(input);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
