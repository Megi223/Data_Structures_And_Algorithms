#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <climits>
#include <set>
#include <cmath>
using namespace std;

unordered_map<size_t, vector<pair<size_t, size_t>>> graph;

size_t target = 0;

// holds min distances from fmi to each vertex
unordered_map<size_t, size_t> distances;

unordered_map<size_t, size_t> paths;
long long int power = pow(10, 9) + 7;

struct Comparator {
    bool operator()(pair<size_t, size_t> first, pair<size_t, size_t> second) {
        return first.first > second.first;
    }
};
void dijkstra(size_t f) {

    distances[f] = 0;
    paths[f] = 0;

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, Comparator> pq;
    pq.push({ 0,f });

    while (!pq.empty()) {

        if (pq.top().first != distances[pq.top().second]) { pq.pop(); continue; }
        size_t vertex = pq.top().second;
        pq.pop();
        for (auto e : graph[vertex])
        {

            if (distances[e.first] > distances[vertex] + e.second) {
                distances[e.first] = distances[vertex] + e.second;

                pq.push({ distances[e.first],e.first });

            }
            if (vertex == f) {
                paths[e.first]++;
                continue;
            }
            if (distances[vertex] < distances[e.first]) {

                paths[e.first] += (paths[vertex] % power);


            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    size_t V, E, start, end;
    cin >> V >> E >> start >> end;
    size_t from, to, weight;
    target = end;
    for (size_t i = 0; i < E; i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back({ to, weight });
        graph[to].push_back({ from,weight });

    }

    for (size_t i = 0; i < V; i++) {
        distances[i] = LONG_MAX;
        paths[i] = 0;
    }
    dijkstra(end);

    size_t answer = paths[start];

    cout << (answer % power);
}
