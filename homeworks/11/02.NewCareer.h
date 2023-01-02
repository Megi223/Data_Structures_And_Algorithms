#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <climits>
#include <set>
using namespace std;

unordered_map<size_t, vector<pair<size_t, size_t>>> graph;
unordered_map<size_t, vector<size_t>> distances;
void dijkstra(size_t start, size_t V) {


    distances[start][start] = 0;

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;
    //set<pair<size_t, size_t>> s;
    //s.insert({ 0,start });
    pq.push({ 0,start });
    while (!pq.empty()) {
        //size_t vertex = s.begin()->second;
        //s.erase(s.begin());
        if (pq.top().first != distances[start][pq.top().second]) { pq.pop(); continue; }
        size_t vertex = pq.top().second;
        pq.pop();
        for (auto e : graph[vertex])
        {

            if (distances[start][e.first] > distances[start][vertex] + e.second) {
                //s.erase({ distances[start][e.first],e.first });
                distances[start][e.first] = distances[start][vertex] + e.second;

                //s.insert({ distances[start][e.first],e.first });
                pq.push({ distances[start][e.first],e.first });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    size_t V, E, Q;
    cin >> V >> E >> Q;
    size_t from, to, weight;

    for (size_t i = 0; i < E; i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back({ to, weight });
    }

    for (size_t i = 0; i < V; i++) {
        distances[i] = vector<size_t>(V, LONG_MAX);
    }
    vector<long long int> ans;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> from >> to;
        if (distances[from][from] == LONG_MAX) {
            dijkstra(from, V);
        }
        if (distances[from][to] == LONG_MAX) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(distances[from][to]);
        }

    }
    for (size_t i = 0; i < Q; i++)
    {
        cout << ans[i] << '\n';

    }

}
