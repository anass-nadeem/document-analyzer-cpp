#ifndef QUERY_SYSTEM_H
#define QUERY_SYSTEM_H

#include "common.h"

void askQuestion(map<string, string>& definitions, stack<string>& history);
void showHistory(stack<string> history);

#endif
