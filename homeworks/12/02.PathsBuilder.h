#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

struct Edge {
    size_t id;
    size_t from;
    size_t to;
    long long int effort;
    long long int reward;
    Edge(size_t _id, size_t _from, size_t _to, long long int _effort, long long int _reward) : id(_id), from(_from), to(_to), effort(_effort), reward(_reward) {}
};

vector<Edge> edges;
unordered_map<size_t, size_t> parents;


size_t findRoot(size_t vertex) {
    if (parents[vertex] == vertex) {
        return vertex;
    }
    return parents[vertex] = findRoot(parents[vertex]);
}

bool makeUnion(size_t f, size_t s) {
    size_t fRoot = findRoot(f);
    size_t sRoot = findRoot(s);
    if (fRoot == sRoot) { return false; }
    parents[sRoot] = fRoot;
    return true;
}

bool criteria(const Edge& first, const Edge& sec) {
    if (first.effort == sec.effort) {
        return first.reward > sec.reward;
    }
    return first.effort < sec.effort;
}

vector<size_t> ans;
size_t N;

void kruskal() {
    sort(edges.begin(), edges.end(), &criteria);
    for (size_t i = 1; i <= N; i++)
    {
        parents[i] = i;
    }
    for (Edge& edge : edges)
    {
        if (ans.size() == N - 1) { return; }

        bool success = makeUnion(edge.from, edge.to);
        if (success) {
            ans.push_back(edge.id);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    size_t M, from, to;
    long long int effort, reward;
    cin >> N >> M;
    for (size_t i = 1; i <= M; i++)
    {
        cin >> from >> to >> effort >> reward;
        Edge edge(i, from, to, effort, reward);
        edges.push_back(edge);
    }

    kruskal();
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
}
