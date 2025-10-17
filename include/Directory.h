#pragma once
#include "IVFSObject.h"
#include "File.h"
#include <vector>

class Directory : public IVFSObject {
private:
    static int gid;
    int id;
    std::string name;
    std::vector<File> contain;
public:
    Directory(std::string name);

    int getId() const;

    void printInfo() const override;

    std::string getName() override;

    void add(File& f);

    void remove(File& f);

    bool operator== (const Directory& other) const;
};