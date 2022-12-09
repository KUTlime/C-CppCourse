#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Declarations
double Sum(const int* arr, const int& num_of_items);
double Average(const int* arr, const int& num_of_items);
double Median(const int* arr, const int& num_of_items);
double Mode(const int* arr, const int& num_of_items);

double Sum(const int* arr);
double Average(const int* arr);
double Median(const int* arr);
double Mode(const int* arr);

void Print_stats(const double* stats_values, const int& num_of_values);
const int* Read_values(const int& num_of_values);
int Read_input_from_user(const char* message);

const int* Bubble_sort(const int* arr, const int& num_of_values);
const int* Bubble_sort(const int* arr);


void Swap(int* a, int* b);

void Print_array(const int* arr, const int& num_of_values);
void Print_array(const int* arr);
#endif // !FUNCTIONS_H



