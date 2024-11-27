#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    void addEdge(int user1, int user2);
    unordered_set<int> bfs(int startUser);

private:
    unordered_map<int, vector<int>> adjList;
};

#endif // GRAPH_H