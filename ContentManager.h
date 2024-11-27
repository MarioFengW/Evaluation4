#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//nodes represent users
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int value);
};

class ContentManager {
public:
    unordered_map<string, vector<string>> categories;
    //vector<string> adultContent;
private:
    void addContent(const string& category);
    void getContentByCategory(const string& category);
};

#endif