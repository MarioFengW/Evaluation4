#include "ContentManager.h"

void ContentManager::addContent(const string& category) {
    string contentToStore = ""; string adultValidation = "";
    if(categories.find(category) == categories.end()) {
        //create a new category if it doesn't exist
        cout << "Category " << category << " created.\n";
        categories[category] = vector<string>(); //initialize empty content vector
    }
    categories[category].push_back(contentToStore);
    /*cout << "Is this adult content? (Y/N): ";
        cin >> adultValidation;
        if(adultValidation == "Y" || adultValidation == "y") {
            adultContent.push_back(contentToStore);
        }*/
}

void ContentManager::getContentByCategory(const string& category) {
    if(categories.find(category) == categories.end()) {
        cout << "Category " << category << " does not exist.";
        return;
    }
    cout << "Content in category " << category << ":\n";
    for(const auto& element : categories) {
        for(const string& content : element.second) {
            cout << content << "\n";
        }
    }
}