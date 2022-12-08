#include <cstdio>

int main()
{
	int array[] = { 1,2,3,4,5 };// We have an array of 5 integers.
	printf("%p\n", array);		// An identifier "arr" is a constant pointer (to int).
	int* pointer = array;		// It can be assigned to another pointer.
	printf("%d\n", *array);		// An array pointer points to the begging of the array by default.
	*array = 6;					// We can assign a value via this pointer.
	//++array;					// We can't do that.
	++pointer;					// We can do this! We moved a pointer to the next item in the array.

	int arr[5]; // Undefined array for five elements of type int.
	arr[0] = 1; // A value assignment to the first item of the array.
	*arr = 1;   // Exactly same thing like line above. The array name is pointer to array type. See next line.
	int* arr_pointer = arr;
	*arr_pointer = 2; // The first item in the array. A pointer was initialized with an array address, so it is same like before.
	++arr_pointer; // Incrementing of the pointer to points to the second item in the array.
	*arr_pointer = 3; // The second item in the array has value 3 now.
	*(++arr_pointer) = 4; // The third item in the array has a value 4 now.
	*(++arr_pointer) = 5; // The fourth item in the array has a value 4 now.
	*(arr_pointer++) = 6; // The fourth item in the array has a value 4 now.
	++(*arr_pointer);	  // I am at fifth item in the array right now.
	int temp = ++(*arr_pointer);
	++(*arr_pointer) = 10;
	++(*arr_pointer) = 15;

	// What happens when we increment outside the array size?
	++arr_pointer;		// I moved my self to sixth position in the array which actually doesn't exist.
	printf("The sixth item in the array: %d", *arr_pointer);

	int arr2[5] = { 1,2,3,4,5 }; //C++ 11 feature

	return 0;
}