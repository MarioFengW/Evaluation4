#pragma once

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <unordered_map>
#include <map>
#include <stdexcept>

class UserManager {
public:
    void addUser(const std::string& userName, const std::map<std::string, int>& categories);
    void addInterest(const std::string& userName, const std::string& category, int value);
    const std::map<std::string, int>& getInterests(const std::string& userName) const;

private:
    std::unordered_map<std::string, std::map<std::string, int>> userCategories;
};

#endif // USERMANAGER_H