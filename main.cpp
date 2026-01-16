#include <iostream>
#include <queue>
#include <map>
#include <stack>

#include "document_processor.h"
#include "query_system.h"
#include "analysis_tools.h"

using namespace std;

int main() {
    queue<string> lines;
    map<string, string> definitions;
    map<string, ConceptNode*> graph;
    stack<string> history;

    string filename = "sample.txt";

    int choice;
    bool loaded = false;

    do {
        cout << "\n====== Document Analyzer ======\n";
        cout << "1. Load Document\n";
        cout << "2. Ask a Question\n";
        cout << "3. Search Word & Count\n";
        cout << "4. Show Concept Graph\n";
        cout << "5. Show Question History\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            loadDocument(filename, lines);
            extractDefinitions(lines, definitions);
            buildConceptGraph(lines, graph);
            loaded = true;
            break;

        case 2:
            if (loaded)
                askQuestion(definitions, history);
            else
                cout << "Please load document first.\n";
            break;

        case 3:
            if (loaded)
                searchWord(filename);
            else
                cout << "Please load document first.\n";
            break;

        case 4:
            if (loaded)
                displayConceptGraph(graph);
            else
                cout << "Please load document first.\n";
            break;

        case 5:
            showHistory(history);
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
