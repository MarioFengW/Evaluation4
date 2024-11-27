#pragma once

#include "UserManager.h"
#include "ContentManager.h"
#include "Graph.h"
#include <set>
#include <vector>
#include <string>

class RecommendationSystem {
private:
    UserManager userManager;
    ContentManager contentManager;
    Graph userGraph;

public:
    // Add a user to the system
    void addUser(const std::string& userName, std::map<std::string, int>& categories);

    // Add content to a specific category
    void addContent(const std::string& category, const std::string& content);

    // Add a friendship connection between two users
    void addFriend(int user1, int user2);

    // Recommend content for a user based on friends' interests
    std::vector<std::string> recommendContent(int userId);
};
