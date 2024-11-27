#include "Graph.h"

using namespace std;

void Graph::addEdge(int user1, int user2) {
    // Relación de amistad es bidireccional
    adjList[user1].push_back(user2);
    adjList[user2].push_back(user1); 
}

unordered_set<int> Graph::bfs(int startUser) {
    unordered_set<int> visited;
    queue<int> q;

    visited.insert(startUser);
    q.push(startUser);

    while (!q.empty()) {
        int user = q.front();
        q.pop();

        for (int friendUser : adjList[user]) {
            if (visited.find(friendUser) == visited.end()) {
                visited.insert(friendUser);
                q.push(friendUser);
            }
        }
    }

    return visited;
}