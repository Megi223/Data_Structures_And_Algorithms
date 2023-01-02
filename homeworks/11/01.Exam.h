#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <climits>
using namespace std;
struct Edge {
    size_t to;
    size_t weight;

    Edge() :to(0), weight(0) {}
    Edge(size_t _to, size_t _weight) :to(_to), weight(_weight) {}

};
unordered_map<size_t, size_t> timeIntervals;
unordered_map<size_t, list<Edge*>> graph;


unordered_map<size_t, size_t> distances;
long long int dijkstra(size_t start, size_t end) {
    long long int ans = -1;

    distances[start] = 0;

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;
    pq.push({ 0,start });
    while (!pq.empty()) {
        size_t vertex = pq.top().second;
        pq.pop();
        size_t currentTime = distances[vertex];
        size_t total = 0;
        size_t waitingTime = 0;
        if (currentTime != 0 && currentTime < timeIntervals[vertex]) {
            waitingTime = timeIntervals[vertex];
            total = waitingTime;
        }
        else if (currentTime % timeIntervals[vertex] == 0) {
            waitingTime = 0;
            total = currentTime;
        }
        else if (currentTime != 0) {
            waitingTime = timeIntervals[vertex] - (currentTime % timeIntervals[vertex]);
            total = currentTime + waitingTime;
        }
        for (auto e : graph[vertex])
        {
            size_t time = total + e->weight;

            if (distances[e->to] > time) {
                distances[e->to] = time;

                pq.push({ distances[e->to],e->to });
                if (e->to == end) {
                    ans = distances[end];
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    size_t V, E, start, end;
    cin >> V >> E >> start >> end;
    size_t interval, from, to, weight;
    for (size_t i = 0; i < V; i++)
    {
        cin >> interval;
        timeIntervals[i] = interval;
    }
    for (size_t i = 0; i < E; i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back(new Edge(to, weight));
    }
    for (size_t i = 0; i < V; i++) {
        distances[i] = INT_MAX;
    }
    long long int ans = dijkstra(start, end);
    cout << ans;
}