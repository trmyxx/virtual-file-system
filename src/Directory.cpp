#include <iostream>
#include <string>
#include "Directory.h"

int Directory::gid = 1;

Directory::Directory(std::string name) {
    id = gid++;
    this->name = name;
}

int Directory::getId() const {
    return id;
}

void Directory::printInfo() const {
    std::cout << name << " directory has:\n";
    for (auto& f : contain) {
        f.printInfo();
        std::cout << ";\n";
    }
}

std::string Directory::getName() {
    return this->name;
}

void Directory::add(File& f) {
    contain.push_back(f);
}

void Directory::remove(File& f) {
    auto it = std::find(contain.begin(), contain.end(), f);
    if (it != contain.end()) {
        contain.erase(it);
    }
}

bool Directory::operator== (const Directory& other) const {
    return this->id == other.getId();
}

