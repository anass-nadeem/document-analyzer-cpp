#ifndef DOCUMENT_PROCESSOR_H
#define DOCUMENT_PROCESSOR_H

#include "common.h"

void loadDocument(const string& filename, queue<string>& lines);
void extractDefinitions(queue<string>& lines, map<string, string>& definitions);
void buildConceptGraph(queue<string>& lines, map<string, ConceptNode*>& graph);

#endif
