#include "query_system.h"
#include <iostream>
#include <sstream>

using namespace std;

void askQuestion(map<string, string>& definitions, stack<string>& history) {
    cin.ignore();
    string question;
    cout << "Ask a question: ";
    getline(cin, question);

    history.push(question);

    stringstream ss(question);
    string word, key;
    while (ss >> word) {
        key = word;
    }

    for (char& c : key) {
        c = tolower(c);
    }

    // remove '?'
    if (!key.empty() && key.back() == '?') {
        key.pop_back();
    }

    if (definitions.find(key) != definitions.end()) {
        cout << key << " is " << definitions[key] << endl;
    } else {
        cout << "Definition not found." << endl;
    }
}

void showHistory(stack<string> history) {
    cout << "\nQuestion History:\n";
    while (!history.empty()) {
        cout << "- " << history.top() << endl;
        history.pop();
    }
}
