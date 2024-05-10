#include <iostream>
#include <string>
#include <map>
int flag = 0;
using namespace std;

// Function to get response from the chatbot
string getResponse(const string& userQuery) {
    // Define some basic responses
    map<string, string> responses = {
        {"hi", "Hello! How can I assist you today?"},
        {"how are you", "I'm just a chatbot, but thanks for asking! How can I help you?"},
        {"bye", "Goodbye! Have a great day!"},
        {"brand", "BMW\nMercedes\nAudi"},
        {"BMW", "What do you want to learn about BMW"},
        {"Mercedes", "What do you want to learn about Mercedes"},
        {"Audi", "What do you want to learn about Audi"},
    };
    map<string, string> responses_bmw = {
        {"hi", "Hello! How can I assist you today?"},
        {"how are you", "I'm just a chatbot, but thanks for asking! How can I help you?"},
        {"bye", "Goodbye! Have a great day!"},
        {"colour", "The colour of the car is Red"},
        {"engine", "The engine is 2000cc"},
        {"tires", "The tires are of michellin"},
        {"fuel", "Diesel"},
        {"brand", "BMW"}};
    map<string, string> responses_merc = {
        {"hi", "Hello! How can I assist you today?"},
        {"how are you", "I'm just a chatbot, but thanks for asking! How can I help you?"},
        {"bye", "Goodbye! Have a great day!"},
        {"colour", "The colour of the car is Blue"},
        {"engine", "The engine is 3000cc"},
        {"tires", "The tires are of pirelli"},
        {"fuel", "Diesel"},
        {"brand", "Mercedes"}};
    map<string, string> responses_audi = {
        {"hi", "Hello! How can I assist you today?"},
        {"how are you", "I'm just a chatbot, but thanks for asking! How can I help you?"},
        {"bye", "Goodbye! Have a great day!"},
        {"colour", "The colour of the car is black"},
        {"engine", "The engine is 1800cc"},
        {"tires", "The tires are of michellin"},
        {"fuel", "Diesel"},
        {"brand", "Audi"}};

        if(flag==0)
        {
        if (userQuery.find("hi") != string::npos) {
            return "Hello! How can I assist you today?";
        } else if (userQuery.find("how are you") != string::npos) {
            return "I'm just a chatbot, but thanks for asking! How can I help you?";
        } else if (userQuery.find("brand") != string::npos) {
            return "BMW\nMercedes\nAudi";   
        }
        else if (userQuery.find("BMW") != string::npos)
        {
            flag = 1;
            return "What do you want to learn about BMW";
        }
        else if (userQuery.find("Mercedes") != string::npos)
        {
            flag = 2;
            return "What do you want to learn about Mercedes";
        }
        else if (userQuery.find("Audi") != string::npos)
        {
            flag = 3;
            return "What do you want to learn about Audi";
        }
        else
        {
            return "Sorry, I didn't understand your query. Could you please rephrase?";
        }
        }
        else if(flag==1)
        {
            if (userQuery.find("colour") != string::npos)
            {
                return responses_bmw["colour"];
            }
            else if (userQuery.find("engine") != string::npos)
            {
                return responses_bmw["engine"];
            }
            else if (userQuery.find("fuel") != string::npos)
            {
                return responses_bmw["fuel"];
            }
            else if (userQuery.find("tires") != string::npos)
            {
                return responses_bmw["tires"];
            }
        }
        else if (flag == 2)
        {
            if (userQuery.find("colour") != string::npos)
            {
                return responses_merc["colour"];
            }
            else if (userQuery.find("engine") != string::npos)
            {
                return responses_merc["engine"];
            }
            else if (userQuery.find("fuel") != string::npos)
            {
                return responses_merc["fuel"];
            }
            else if (userQuery.find("tires") != string::npos)
            {
                return responses_merc["tires"];
            }
        }
        else if (flag == 3)
        {
            if (userQuery.find("colour") != string::npos)
            {
                return responses_audi["colour"];
            }
            else if (userQuery.find("engine") != string::npos)
            {
                return responses_audi["engine"];
            }
            else if (userQuery.find("fuel") != string::npos)
            {
                return responses_audi["fuel"];
            }
            else if (userQuery.find("tires") != string::npos)
            {
                return responses_audi["tires"];
            }
        }
}

int main() {
    cout << "Welcome to Car Customer Care Chatbot" << endl;
    cout << "You can start chatting. Type 'bye' to exit." << endl;

    string userQuery;
    while (true) {
        cout << "User: ";
        getline(cin,userQuery);
        if (userQuery == "bye") {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
            break;
        }

        string response = getResponse(userQuery);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}