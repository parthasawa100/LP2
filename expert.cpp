#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

unordered_map<string, vector<string>> languageFeatures = {
    {"Python", {"Easy to Learn", "Readable Code", "Wide Range of Libraries"}},
    {"Java", {"Platform Independence", "Strong Community Support", "Object-Oriented Programming"}},
    {"C++", {"High Performance", "Memory Management Control", "Strongly Typed"}},
    {"JavaScript", {"Client-Side Scripting", "Asynchronous Programming", "Web Development"}},
    {"Ruby", {"Simple Syntax", "Meta-programming Capabilities", "Web Development"}},
    {"C#", {"Integration with .NET Framework", "Object-Oriented Programming", "Windows Development"}}
};

vector<string> getUserRequirements() {
    vector<string> userRequirements;
    cout << "Please answer 'yes' or 'no' for each requirement:" << endl;
    for (const auto& feature : languageFeatures.begin()->second) {
        string response;
        cout << "Do you need " << feature << "? (yes/no): ";
        cin >> response;
        if (response == "yes" || response == "Yes" || response == "y" || response == "Y") {
            userRequirements.push_back(feature);
        }
    }
    return userRequirements;
}

void suggestLanguage() {
    vector<string> userRequirements = getUserRequirements();
    set<string> possibleLanguages;

    for (auto& lang : languageFeatures) {
        string language = lang.first;
        vector<string> features = lang.second;
        bool satisfiesRequirements = all_of(features.begin(), features.end(), [&](const string& req) {
            return find(userRequirements.begin(), userRequirements.end(), req) != userRequirements.end();
        });
        if (satisfiesRequirements) {
            possibleLanguages.insert(language);
        }
    }

    if (!possibleLanguages.empty()) {
        cout << "Possible programming languages:" << endl;
        for (const string& language : possibleLanguages) {
            cout << "- " << language << endl;
        }
    } else {
        cout << "No matching programming languages found." << endl;
    }
}

int main() {
    suggestLanguage();
    return 0;
}
