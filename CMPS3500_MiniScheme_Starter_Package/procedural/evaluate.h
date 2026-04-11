#ifndef EVALUATE_H
#define EVALUATE_H

#include <vector>
#include <string>
#include "scope.h"

void evaluate(const std::vector<std::string>& expr, Scope* scope);

#endif