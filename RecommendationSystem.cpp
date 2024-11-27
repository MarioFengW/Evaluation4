#include "RecommendationSystem.h"

// Add a user to the system
void RecommendationSystem::addUser(const std::string& userName, std::map<std::string, int>& categories) {
    userManager.addUser(userName, categories);
}

// Add content to a specific category
void RecommendationSystem::addContent(const std::string& category, const std::string& content) {
    contentManager.addContent(category); // Delegate to ContentManager
    contentManager.categories[category].push_back(content); // Add content directly
}

// Add a friendship connection between two users
void RecommendationSystem::addFriend(int user1, int user2) {
    userGraph.addEdge(user1, user2); // Delegate to Graph
}

// Recommend content for a user based on friends' interests
std::vector<std::string> RecommendationSystem::recommendContent(int userId) {
    // Get all friends of the user using BFS
    std::unordered_set<int> friends = userGraph.bfs(userId);

    // Aggregate interests of all friends
    std::set<std::string> aggregatedInterests;
    for (int friendId : friends) {
        User friendUser = {std::to_string(friendId)};
        try {
            const auto& interests = userManager.getInterests(friendUser);
            for (const auto& [category, value] : interests) {
                if (value > 0) { // Consider interests with positive values
                    aggregatedInterests.insert(category);
                }
            }
        } catch (const std::runtime_error&) {
            continue; // Ignore users that don't exist
        }
    }

    // Gather recommended content based on friends' interests
    std::vector<std::string> recommendations;
    for (const std::string& category : aggregatedInterests) {
        if (contentManager.categories.find(category) != contentManager.categories.end()) {
            for (const std::string& content : contentManager.categories[category]) {
                recommendations.push_back(content);
            }
        }
    }

    return recommendations;
}
