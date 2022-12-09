#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* stream;

	// Open for write
	errno_t err = fopen_s(&stream, "data.txt", "w+");
	if (err == 0)
	{
		printf("The file 'data.txt' was opened\n");
	}
	else
	{
		printf("The file 'data.txt' was not opened\n");
	}

	fprintf(stream, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", stream);


	// Close stream if it is not NULL
	if (stream)
	{
		err = fclose(stream);
		if (err == 0)
		{
			printf("The file 'data.txt' was closed\n");
		}
		else
		{
			printf("The file 'data.txt' was not closed\n");
		}
	}

	FILE* stream2;
	err = fopen_s(&stream2, "data.txt", "r");
	char buff[255];
	fscanf_s(stream2, "%s", buff, _countof(buff));
	printf("1 : %s\n", buff);
	fgets(buff, 255, stream2);
	printf("2: %s\n", buff);
	fgets(buff, 255, stream2);
	printf("3: %s\n", buff);
	fclose(stream2);


}
