#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H

#include "UserManager.h"
#include "ContentManager.h"
#include "Graph.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

class RecommendationSystem {
public:
    void addUser(const std::string& userName, const std::map<std::string, int>& categories);
    void addContent(const std::string& category, const std::string& content);
    void addFriend(const std::string& user1, const std::string& user2);
    void addInterestToUser(const std::string& userName, const std::string& category, int value);
    std::vector<std::string> recommendContent(const std::string& userId);

private:
    UserManager userManager;
    ContentManager contentManager;
    Graph userGraph;
};

#endif // RECOMMENDATIONSYSTEM_H