#include <iostream>
#include <string>
#include "File.h"

int File::gid = 1;

File::File(std::string name) {
    id = gid++;
    this->name = name;
    this->size = 16;
    this->type = "txt";
}

File::File(std::string name, size_t size) : File(name) {
    this->size = size;
}

File::File(std::string name, size_t size, std::string type) : File(name, size) {
    this->type = type;
}

void  File::printInfo() const {
    std::cout << "File name: " << name << " is " << size << " mb and has " << type << " type\n";
}

std::string File::getName(){
    return this->name;
}

void File::rename(std::string name) {
    this->name = name;
}

void File::resize(size_t size) {
    this->size = size;
}

int File::getId() const { 
    return id;
}

bool File::operator== (const File& other) {
    return this->id == other.getId();
}