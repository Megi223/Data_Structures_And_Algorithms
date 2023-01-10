#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    size_t from;
    size_t to;
    size_t weight;
    Edge(size_t _from = 0, size_t _to = 0, size_t _weight = 0) : from(_from), to(_to), weight(_weight) {}
    bool operator<(const Edge& f) const {
        return this->weight < f.weight;
    }
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

struct Comparator {
    bool operator()(const Edge& first, const Edge& sec) {
        return first.weight > sec.weight;
    }
};
bool criteria(const Edge& first, const Edge& sec) {
    return first.weight < sec.weight;
}

size_t N;


pair<size_t, size_t> finalAnswer = { 0,INT_MAX };
void kruskal() {
    sort(edges.begin(), edges.end(), &criteria);

    size_t counter = 0;

    for (size_t i = 0; i < edges.size(); i++)
    {
        Edge currentEdge = edges[i];
        counter = 0;
        map<size_t, pair<size_t, size_t>> solutions;
        for (size_t k = 1; k <= N; k++)
        {
            parents[k] = k;
        }
        for (size_t j = i; j < edges.size(); j++)
        {

            bool success = makeUnion(edges[j].from, edges[j].to);
            if (success) { counter++; }
            if (counter >= N - 1) {
                size_t diff = edges[j].weight - currentEdge.weight;
                solutions[diff] = { currentEdge.weight,edges[j].weight };
                break;

            }
        }
        if (solutions.size() > 0 && finalAnswer.second - finalAnswer.first > solutions.begin()->first) {
            finalAnswer = solutions.begin()->second;

        }
        else if (solutions.size() == 0) {
            break;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    size_t M, from, to, weight;
    cin >> N >> M;
    for (size_t i = 1; i <= M; i++)
    {
        cin >> from >> to >> weight;
        Edge edge(from, to, weight);
        edges.push_back(edge);
    }

    kruskal();

    cout << finalAnswer.first << ' ' << finalAnswer.second;

}
