# Include Folder

This folder contains the header files for the Virtual File System (VFS) project.

## How to Use

To use the VFS in your project, you **only need to include the main header file**:

```cpp
#include "FileSystem.h"

All other headers (File.h, Directory.h, TreeNode.h, etc.) are included automatically through FileSystem.h, so there is no need to include them manually.