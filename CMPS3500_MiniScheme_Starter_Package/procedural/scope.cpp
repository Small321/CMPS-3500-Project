#include "scope.h"
#include <string>

Scope *enter_scope(Scope *current)
{
    Scope *new_scope = new Scope;
    new_scope->parent = current;
    return new_scope;
}

Scope *exit_scope(Scope *current)
{
    if (current == nullptr)
    {
        return nullptr;
    }

    Scope *parent_scope = current->parent;
    delete current;
    return parent_scope;
}

void add_binding(Scope *scope, const std::string &name, const std::string &value)
{
    if (scope == nullptr)
    {
        return;
    }

    Binding b;
    b.name = name;
    b.value = value;
    scope->bindings.push_back(b);
}

std::string lookup_binding(Scope *scope, const std::string &name)
{
    Scope *temp = scope;

    while (temp != nullptr)
    {
        for (int i = 0; i < (int)temp->bindings.size(); i++)
        {
            if (temp->bindings[i].name == name)
            {
                return temp->bindings[i].value;
            }
        }

        temp = temp->parent;
    }

    return "UNBOUND";
}

bool exists_in_current_scope(Scope *scope, const std::string &name)
{
    if (scope == nullptr)
    {
        return false;
    }

    for (int i = 0; i < (int)scope->bindings.size(); i++)
    {
        if (scope->bindings[i].name == name)
        {
            return true;
        }
    }

    return false;
}