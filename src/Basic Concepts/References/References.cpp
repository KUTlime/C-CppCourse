// Demonstration of side effect of reference
int& f(int& x)
{
	++x;
	return x;
}

// That's why we often can see this modification.
const int& g(const int& x)
{
	static int y = x;
	++y;
	return y;
}

int main()
{
	int i = 1;

	printf("the value is %d\n", i);
	printf("the value is %d\n", f(i));
	printf("the value is %d\n", i); // Side effect of the reference. The is no compiler indication about the reference.
	printf("the value is %d\n", g(i));

	int temp = g(i);
	temp++;

	//int temp2 = (g(i)++); // Can do, why?


}