#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Graph {
public:
    void addEdge(const string& user1, const string& user2);
    unordered_set<string> bfs(const string& startUser);

private:
    unordered_map<string, vector<string>> adjList;
};

#endif // GRAPH_H