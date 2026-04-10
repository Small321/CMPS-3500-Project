#ifndef SCOPE_H
#define SCOPE_H

#include <string>
#include <vector>

struct Binding
{
    std::string name;
    std::string value;
};

struct Scope
{
    std::vector<Binding> bindings;
    Scope *parent;
};

Scope *enter_scope(Scope *current);
Scope *exit_scope(Scope *current);

void add_binding(Scope *scope, const std::string &name, const std::string &value);
std::string lookup_binding(Scope *scope, const std::string &name);
bool exists_in_current_scope(Scope *scope, const std::string &name);

#endif