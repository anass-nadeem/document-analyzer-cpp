#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;

/*
 Linked List node for Concept Graph
*/
struct ConceptNode {
    string concept;
    ConceptNode* next;

    ConceptNode(string c) {
        concept = c;
        next = NULL;
    }
};

#endif
