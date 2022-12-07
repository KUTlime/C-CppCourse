#include <iostream>
struct FilePermission {
	bool Read : 1;
	bool Write : 1;
	bool Full : 1;
	bool Hidden : 1;
	bool SharedOverNetwork : 1;
}; // Velikost 1 byte v paměti

union AccessRights
{
	FilePermission FilePermissions;
	uint8_t FilePermissionMask;
}; // Stále velikost 1 byte, protože to nám stačí na oba členy unionu

int main()
{
	AccessRights rights;
	rights.FilePermissions.Full = true;
	rights.FilePermissionMask = 28;
}