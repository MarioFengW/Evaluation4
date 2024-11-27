#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include <stdexcept>

// Structure User representing a person
struct User {
    std::string name;
};

// Class UserManager to manage users' interests
class UserManager {
private:
    // Map linking a user's name to a reference to a map of categories
    std::unordered_map<std::string, std::map<std::string, int>&> userCategories;

public:
    // Add a new user by name and link to their categories map
    void addUser(const std::string& userName, std::map<std::string, int>& categories);

    // Add or update an interest for an existing user
    void addInterest(const User& user, const std::string& category, int value);

    // Get the map of interests for a specific user
    const std::map<std::string, int>& getInterests(const User& user) const;
};