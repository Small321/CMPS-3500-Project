#include "scope.h"
#include <string>

Scope *enterScope(Scope *current)
{
    Scope *new_scope = new Scope;
    new_scope->parent = current;
    return new_scope;
}

Scope *exitScope(Scope *current)
{
    if (current == nullptr)
    {
        return nullptr;
    }

    Scope *parent_scope = current->parent;
    delete current;
    return parent_scope;
}

void addBinding(Scope *scope, const std::string &name, const std::string &value)
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

std::string lookupBinding(Scope *scope, const std::string &name)
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

    return "NOT FOUND";
}

bool existsInCurrentScope(Scope *scope, const std::string &name)
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
