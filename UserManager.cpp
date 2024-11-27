#include "UserManager.h"

// Method to add a new user by name
void UserManager::addUser(const std::string& userName, std::map<std::string, int>& categories) {
    if (userCategories.find(userName) != userCategories.end()) {
        throw std::runtime_error("User already exists.");
    }
    User user{userName}; // Create a User struct
    userCategories[user.name] = categories;
}

// Method to add or update an interest for a user
void UserManager::addInterest(const User& user, const std::string& category, int value) {
    auto it = userCategories.find(user.name);
    if (it == userCategories.end()) {
        throw std::runtime_error("User does not exist.");
    }
    it->second[category] = value;
}

// Method to get the interests of a user
const std::map<std::string, int>& UserManager::getInterests(const User& user) const {
    auto it = userCategories.find(user.name);
    if (it == userCategories.end()) {
        throw std::runtime_error("User does not exist.");
    }
    return it->second;
}