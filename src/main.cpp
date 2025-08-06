#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class IVFSObject {
public:
    virtual void printInfo() const = 0;
    virtual std::string getName() = 0;
    virtual ~IVFSObject() = default;
};

class File : public IVFSObject{
private:
    static int gid;
    int id;
    std::string name;
    size_t size;
    std::string type;
public:
    File(std::string name) {
        id = gid++;
        this->name = name;
        this->size = 16;
        this->type = "txt";
    }

    File(std::string name, size_t size) : File(name) {
        this->size = size;
    }

    File(std::string name, size_t size, std::string type) : File(name, size) {
        this->type = type;
    }

    void printInfo() const override {
        std::cout << "File name: " << name << " is " << size << " mb and has " << type << "type\n";
    }

    std::string getName() override {
        return this->name;
    }

    void rename(std::string name) {
        this->name = name;
    }

    void resize(size_t size) {
        this->size = size;
    }

    int getId() const { 
        return id;
    }

    bool operator== (const File& other) {
        return this->id == other.getId();
    }
};

int File::gid = 1;

class Directory : public IVFSObject {
private:
    static int gid;
    int id;
    std::string name;
    std::vector<File> contain;
public:
    Directory(std::string name) {
        id = gid++;
        this->name = name;
    }

    int getId() const {
        return id;
    }

    void printInfo() const override {
        std::cout << name << " directory has:\n";
        for (auto& f : contain) {
            f.printInfo();
            std::cout << ";\n";
        }
    }

    std::string getName() override {
        return this->name;
    }

    void add(File& f) {
        contain.push_back(f);
    }

    void remove(File& f) {
        auto it = std::find(contain.begin(), contain.end(), f);
        if (it != contain.end()) {
            contain.erase(it);
        }
    }

    bool operator== (const Directory& other) const {
        return this->id == other.getId();
    }
};

int Directory::gid = 1;

struct TreeNode {
    std::shared_ptr<Directory> value;
    std::vector<std::shared_ptr<TreeNode>> children;

    TreeNode(Directory& val) : value(std::make_shared<Directory>(val)) {}

    void addChild(std::shared_ptr<TreeNode> child) {
        children.push_back(child);
    }
};

std::shared_ptr<TreeNode> dfs(std::shared_ptr<TreeNode> root, int neededId) {
    if (root->value->getId() == neededId) return root;
    for (auto& i : root->children) {
        auto result = dfs(i, neededId);
        if (result) return result;
    }
    return nullptr;
}

class FileSystem {
private:
    std::shared_ptr<TreeNode> root;
    FileSystem() {}
public:
    static FileSystem* getInstance() {
        static FileSystem instance;
        return &instance;
    }
    FileSystem(const FileSystem&) = delete;
    FileSystem& operator= (const FileSystem&) = delete;

    void AddDirectory(Directory* father, std::string name) {
        auto newDir = std::make_shared<Directory>(name);
        auto newNode = std::make_shared<TreeNode>(*newDir);
        if (!root) {
            root = newNode;
            return;
        }
        auto parent = dfs(root, father->getId());
        if (parent) {
            parent->addChild(newNode);
        }
    }
};


int main()
{
    return 0;
}