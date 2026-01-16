#include "document_processor.h"
#include <fstream>
#include <iostream>

using namespace std;

void loadDocument(const string& filename, queue<string>& lines) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push(line);
        }
    }

    file.close();
    cout << "Document loaded successfully!" << endl;
}

#include <sstream>

void extractDefinitions(queue<string>& lines, map<string, string>& definitions) {
    queue<string> temp = lines; // preserve original queue

    while (!temp.empty()) {
        string line = temp.front();
        temp.pop();

        size_t pos = line.find(" is ");
        if (pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 4);

            // normalize key (lowercase)
            for (char& c : key) {
                c = tolower(c);
            }

            definitions[key] = value;
        }
    }

    cout << "Definitions extracted: " << definitions.size() << endl;
}


#include <sstream>

void addEdge(map<string, ConceptNode*>& graph, const string& from, const string& to) {
    ConceptNode* node = new ConceptNode(to);
    node->next = graph[from];
    graph[from] = node;
}

void buildConceptGraph(queue<string>& lines, map<string, ConceptNode*>& graph) {
    queue<string> temp = lines;

    while (!temp.empty()) {
        string line = temp.front();
        temp.pop();

        size_t pos = line.find(" and ");
        if (pos != string::npos) {
            string c1 = line.substr(0, pos);
            string rest = line.substr(pos + 5);

            stringstream ss(rest);
            string c2;
            ss >> c2;

            for (char& c : c1) c = tolower(c);
            for (char& c : c2) c = tolower(c);

            addEdge(graph, c1, c2);
            addEdge(graph, c2, c1);
        }
    }

    cout << "Concept graph built successfully!" << endl;
}
