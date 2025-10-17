#pragma once
#include <string>
#include "IVFSObject.h"

class File : public IVFSObject{
private:
    static int gid;
    int id;
    std::string name;
    size_t size;
    std::string type;
public:
    //Constructors
    File(std::string name);
    File(std::string name, size_t size);
    File(std::string name, size_t size, std::string type);

    //Another methods
    void printInfo() const override;
    std::string getName() override;
    void rename(std::string name);
    void resize(size_t size);
    int getId() const;
    bool operator== (const File& other);
};