#include "analysis_tools.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void searchWord(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    string target;
    cout << "Enter word to search: ";
    cin >> target;

    for (char& c : target) {
        c = tolower(c);
    }

    int count = 0;
    string line, word;

    while (getline(file, line)) {
        stringstream ss(line);
        while (ss >> word) {
            for (char& c : word) {
                c = tolower(c);
            }
            if (word == target) {
                count++;
            }
        }
    }

    file.close();
    cout << "Word found " << count << " time(s)." << endl;
}


#include <iostream>

void displayConceptGraph(map<string, ConceptNode*>& graph) {
    cout << "\nConcept Dependency Graph:\n";

    for (auto& pair : graph) {
        cout << pair.first << " -> ";
        ConceptNode* temp = pair.second;

        while (temp != nullptr) {
            cout << temp->concept << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
