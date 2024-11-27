#include "UserManager.h"

// Method to add a new user by name
void UserManager::addUser(const std::string& userName, const std::map<std::string, int>& categories) {
    if (userCategories.find(userName) != userCategories.end()) {
        throw std::runtime_error("User already exists.");
    }
    userCategories[userName] = categories;
}

// Method to add or update an interest for a user
void UserManager::addInterest(const std::string& userName, const std::string& category, int value) {
    auto it = userCategories.find(userName);
    if (it == userCategories.end()) {
        throw std::runtime_error("User does not exist.");
    }
    it->second[category] = value;
}

// Method to get the interests of a user
const std::map<std::string, int>& UserManager::getInterests(const std::string& userName) const {
    auto it = userCategories.find(userName);
    if (it == userCategories.end()) {
        throw std::runtime_error("User does not exist.");
    }
    return it->second;
}