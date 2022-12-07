#include <iostream>
#include <cstdio>

void FloatingPointNumbers()
{
	float f;
	double df;
	long double ldf;

	printf("size of float f is %ld\n", sizeof(f));
	printf("size of double df is %ld\n", sizeof(df));
	printf("size of long double float ldf is %ld\n", sizeof(ldf));

	// How about that?
	f = 0.1F + 0.1F + 0.1F;

	printf("float f is %f\n", f);
	if (f == 0.3)
	{
		puts("True.\n");
	}
	else
	{
		puts("False.\n");
	}
	printf("float f is %1.10f\n", f);

	df = 0.1 + 0.1 + 0.1;

	printf("double f is %f\n", df);
	if (df == 0.3)
	{
		puts("True.\n");
	}
	else
	{
		puts("False.\n");
	}
	printf("double df is %1.20f\n", df);

	if (df)
	{
		puts("Floating point number is evaluated as True/False");
	}
}

int main()
{
	FloatingPointNumbers();
    std::cout << "Hello World!\n";
}
