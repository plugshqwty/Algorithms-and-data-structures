#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstdio>

using namespace std;

struct Edge {
    int to;
    int weight;
};

class Graph {
private:
    int n;
    vector<vector<Edge>> svList;

public:
    Graph(int vertices) : n(vertices), svList(vertices + 1) {}

    void addEdge(int u, int v, int w) {
        svList[u].push_back({ v, w });
        svList[v].push_back({ u, w });
    }

    long long dijkstr(int start, int target) {
        vector<long long> dist(n + 1, numeric_limits<long long>::max());
        vector<bool> visited(n + 1, false);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({ 0, start });

        while (!pq.empty()) {
            long long curDist = pq.top().first;
            int curVertex = pq.top().second;
            pq.pop();

            if (visited[curVertex]) continue;
            visited[curVertex] = true;

            for (const auto& edge : svList[curVertex]) {
                long long newDist = curDist + edge.weight;
                if (newDist < dist[edge.to]) {
                    dist[edge.to] = newDist;
                    pq.push({ newDist, edge.to });
                }
            }
        }

        return dist[target];
    }
};

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    int n, m;
    fscanf(inputFile, "%d %d", &n, &m);

    Graph graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        fscanf(inputFile, "%d %d %d", &u, &v, &w);
        graph.addEdge(u, v, w);
    }

    long long result = graph.dijkstr(1, n);

    fprintf(outputFile, "%lld\n", result);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
