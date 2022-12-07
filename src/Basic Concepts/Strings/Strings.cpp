#include <iostream>

int main()
{
	char cstring[] = "String";

	puts(cstring);

	for (unsigned int i = 0; cstring[i]; i++) {
		printf("%02d: %c\n", i, cstring[i]);
	}

	char cstring2[] = "String" "String" "String";

	puts(cstring2);

	for (unsigned int i = 0; cstring2[i]; i++) {
		printf("%02d: %c\n", i, cstring2[i]);
	}

	char string[] = "This is a string. \'";

    std::cout << string << std::endl;
}
