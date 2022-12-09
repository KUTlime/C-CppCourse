#include <iostream>
#include "Functions.h"

#define NUMBER_OF_VALUES 10

int main()
{
	double stat_result[4] = { 0,0,0,0 };
	const int num_of_values = Read_input_from_user("Give me a number of numbers: ");
	const int* data = Read_values(num_of_values);

	std::cout << "Input data: " << std::endl;

	Print_array(data, num_of_values);

	const int* sorted_data = Bubble_sort(data, num_of_values);

	stat_result[0] = Sum(data, num_of_values);
	stat_result[1] = Average(data, num_of_values);
	stat_result[2] = Median(sorted_data, num_of_values);
	stat_result[3] = Mode(sorted_data, num_of_values);

	std::cout << "Results: " << std::endl;
	Print_stats(stat_result, 4);

	std::cout << "Sorted data: " << std::endl;
	Print_array(sorted_data, num_of_values);

	std::cout << "End of the program\n";
}