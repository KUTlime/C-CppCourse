#include <iostream>​

struct FilePermissions​
{
    bool read : 1;
    bool write : 1;
    bool full : 1;
    bool hidden : 1;
    bool shared : 1;
};

union FilePermission​
{
    uint8_t Rights;
    FilePermissions​ filePermission;
};

int main()
{
    FilePermissions​ accessRights;

    accessRights.read = false;  // Rights for reding of the file.​
    accessRights.write = false; // Rights for writing to the file.​
    accessRights.full = true;   // Rights for full contgrol of the file.​
    accessRights.hidden = true; // If the file should be hidden.​
    accessRights.shared = true; // If the file should be shared.

    FilePermission​ myFilePermission;

    myFilePermission.filePermission = accessRights;

    printf("File permission is: %d\n", myFilePermission.Rights);

    myFilePermission.filePermission.hidden = false;

    printf("File permission is: %d\n", myFilePermission.Rights);

};
