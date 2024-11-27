#include "Graph.h"

using namespace std;

void Graph::addEdge(const string& user1, const string& user2) {
    adjList[user1].push_back(user2);
    adjList[user2].push_back(user1); // La relación de amistad es bidireccional
}

unordered_set<string> Graph::bfs(const string& startUser) {
    unordered_set<string> visited;
    queue<string> q;

    visited.insert(startUser);
    q.push(startUser);

    while (!q.empty()) {
        string user = q.front();
        q.pop();

        for (const string& friendUser : adjList[user]) {
            if (visited.find(friendUser) == visited.end()) {
                visited.insert(friendUser);
                q.push(friendUser);
            }
        }
    }

    return visited;
}