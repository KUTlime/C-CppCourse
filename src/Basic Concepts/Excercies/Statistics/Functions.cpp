#include "Functions.h"
#include <iostream>

// Declarations
double Sum(const int* arr, const int& num_of_items)
{
	double sum = 0;
	for (int i = 0; i < num_of_items; ++i)
	{
		sum += arr[i];
	}
	return sum;
};

double Average(const int* arr, const int& num_of_items)
{
	return Sum(arr, num_of_items) / num_of_items;
};

double Median(const int* arr, const int& num_of_items)
{
	double median = 0;

	if (num_of_items % 2)
	{
		// num_of_items is odd
		median = arr[num_of_items / 2];
	}
	else
	{
		// num_of_items is even
		median = (arr[num_of_items / 2 - 1] + arr[(num_of_items / 2)]) / 2.0;
	}
	return median;
};

double Mode(const int* arr, const int& num_of_items)
{
	// 1, 1, 2, 2, 3, 4, 5
	int number = arr[0];
	int mode = number;
	int count = 1;
	int countMode = 1;
	for (int i = 1; i < num_of_items; i++)
	{
		if (arr[i] == number)
		{
			++count;
		}
		else
		{
			if (count > countMode)
			{
				countMode = count;
				mode = number;
			}
			count = 1; // reseting a counter for a new value
			number = arr[i];
		}
	}
	return mode + 0.0;
}

double Sum(const int* arr)
{
	return Sum(arr, sizeof(arr) / sizeof(*arr));
}

double Average(const int* arr)
{
	return Average(arr, sizeof(arr) / sizeof(*arr));
};

double Median(const int* arr)
{
	return Median(arr, sizeof(arr) / sizeof(*arr));
};

double Mode(const int* arr)
{
	return Mode(arr, sizeof(arr) / sizeof(*arr));
};

void Print_stats(const double* stats_values, const int& num_of_values)
{
	for (int i = 0; i < num_of_values; i++)
	{
		std::cout << stats_values[i] << std::endl;
	}
};

const int* Read_values(const int& num_of_values)
{
	int* arr_of_values = new int[num_of_values]; // Create a chunk of memory on heap
	if (arr_of_values == nullptr)
	{
		// Some message about unsufficient memory
		// in the system.
		std::cout << "There isn't enough memory in the system." << std::endl;
		return nullptr;
	}
	//char other_string[64] = "Please, enter the "; // Make sure you allocate enough space to append the other string
	char postfix[64] = ". number ";
	//strcat_s(other_string, integer_string); // other_string now contains "Integer: 1234"
	const int* arr = arr_of_values; // Storing the pointer to the beginning of the array.
	// Populating the memory with values from user.
	for (int i = 0; i < num_of_values; i++)
	{
		char other_string[64] = "Please, enter the ";
		char integer_string[11];
		sprintf_s(integer_string, "%d", i + 1);
		strcat_s(other_string, integer_string);
		strcat_s(other_string, postfix);
		*arr_of_values = Read_input_from_user(other_string);
		++arr_of_values; // Shift to next memory address.
	}
	return arr; // Returing the beginning of the array.
};

int Read_input_from_user(const char* message)
{
	int n;
	std::cout << message;
	std::cin >> n;
	return n;
}

const int* Bubble_sort(const int* arr, const int& num_of_values)
{
	int* arr_sorted = new int[num_of_values]; // Create a chunk of memory on heap
	if (arr_sorted == nullptr)
	{
		// Some message about unsufficient memory
		// in the system.
		std::cout << "There isn't enough memory in the system." << std::endl;
	}
	for (int i = 0; i < num_of_values; ++i)
	{
		arr_sorted[i] = arr[i];
	}
	const int* begining_of_array = arr_sorted;
	int* first = nullptr;
	int* second = nullptr;
	// 0, 1, 2, 3 ... n-2 which will be the last run
	for (int i = 0; i < num_of_values - 1; ++i)
	{
		for (int j = 0; j < num_of_values - i - 1; ++j)
		{
			if (arr_sorted[j] > arr_sorted[j + 1])
			{
				arr_sorted[j] ^= arr_sorted[j + 1];
				arr_sorted[j + 1] ^= arr_sorted[j];
				arr_sorted[j] ^= arr_sorted[j + 1];
			}
		}
	}
	return begining_of_array;
}

const int* Bubble_sort(const int* arr)
{
	// allocation of the array "arr"
	return Bubble_sort(arr, sizeof(arr) / sizeof(*arr));
}

void Print_array(const int* arr, const int& num_of_values)
{
	for (int i = 0; i < num_of_values; ++i)
	{
		std::cout << i << ". item in array: " << arr[i] << std::endl;
	}
};

void Print_array(const int* arr)
{
	return Print_array(arr, sizeof(arr) / sizeof(*arr));
};

void Swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
};
