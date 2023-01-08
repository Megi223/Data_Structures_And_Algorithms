#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

const size_t MAX = 100000;

unordered_map<size_t, vector<size_t>> graph;

size_t parents[MAX];

size_t findRoot(size_t vertex) {
	if (parents[vertex] == vertex) {
		return vertex;
	}
	return findRoot(parents[vertex]);
}

void unite(size_t first, size_t sec) {
	size_t rootU = findRoot(first);
	size_t rootV = findRoot(sec);
	parents[rootV] = rootU;
}


int main() {
	size_t N, M, from, to, Q, type;
	cin >> N >> M;
	for (size_t i = 1; i <= N; i++)
	{
		parents[i] = i;
	}
	for (size_t i = 0; i < M; i++)
	{
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
		unite(from, to);
	}
	cin >> Q;
	vector<size_t> ans;
	for (size_t i = 0; i < Q; i++)
	{
		cin >> type >> from >> to;
		if (type == 1) {
			bool isPath = findRoot(from) == findRoot(to);
			ans.push_back(isPath);
		}
		else if (type == 2) {
			graph[from].push_back(to);
			graph[to].push_back(from);
			unite(from, to);
		}
	}
	for (size_t i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
	}
}
