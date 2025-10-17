#pragma once
#include <string>

class IVFSObject {
public:
    virtual void printInfo() const = 0;
    virtual std::string getName() = 0;
    virtual ~IVFSObject() = default;
};