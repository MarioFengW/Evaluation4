#include "RecommendationSystem.h"

// Add a user to the system
void RecommendationSystem::addUser(const std::string& userName, const std::map<std::string, int>& categories) {
    try {
        userManager.addUser(userName, categories);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Add content to a specific category
void RecommendationSystem::addContent(const std::string& category, const std::string& content) {
    contentManager.addContent(category); // Delegate to ContentManager
    contentManager.categories[category].push_back(content); // Add content directly
}

// Add a friendship connection between two users
void RecommendationSystem::addFriend(const std::string& user1, const std::string& user2) {
    userGraph.addEdge(user1, user2); // Delegate to Graph
}

// Add interest to a user
void RecommendationSystem::addInterestToUser(const std::string& userName, const std::string& category, int value) {
    try {
        userManager.addInterest(userName, category, value);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Recommend content for a user based on friends' interests
std::vector<std::string> RecommendationSystem::recommendContent(const std::string& userId) {
    // Get all friends of the user using BFS
    std::unordered_set<std::string> friends = userGraph.bfs(userId);

    // Aggregate interests of all friends
    std::set<std::string> aggregatedInterests;
    for (const std::string& friendId : friends) {
        try {
            const auto& interests = userManager.getInterests(friendId);
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
    std::unordered_set<std::string> userContent;
    try {
        const auto& userInterests = userManager.getInterests(userId);
        for (const auto& [category, value] : userInterests) {
            if (contentManager.categories.find(category) != contentManager.categories.end()) {
                for (const std::string& content : contentManager.categories[category]) {
                    userContent.insert(content);
                }
            }
        }
    } catch (const std::runtime_error&) {
        // Ignore if user does not exist
    }

    std::unordered_set<std::string> recommendationsSet;
    for (const std::string& category : aggregatedInterests) {
        if (contentManager.categories.find(category) != contentManager.categories.end()) {
            for (const std::string& content : contentManager.categories[category]) {
                if (userContent.find(content) == userContent.end()) {
                    recommendationsSet.insert(content);
                }
            }
        }
    }

    return std::vector<std::string>(recommendationsSet.begin(), recommendationsSet.end());
}