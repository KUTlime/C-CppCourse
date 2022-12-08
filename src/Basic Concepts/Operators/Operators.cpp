#include <iostream>

int main()
{
	using namespace std;

	// Assignment operator (=)
	int a, b;         // a:?,  b:?
	a = 10;           // a:10, b:?
	b = 4;            // a:10, b:4
	a = b;            // a:4,  b:4
	b = 7;            // a:4,  b:7

	cout << "a:";
	cout << a;
	cout << " b:";
	cout << b;

	int x, y, z;
	y = 2 + (x = 5);
	x = 5;
	y = 2 + x;
	x = y = z = 5;

	// Arithmetic operators ( +, -, *, /, % )
	x = 11 % 3; // Modulo, x:2 



	// Compound assignment (+=, -=, *=, /=, %=, >>=, <<=, &=, ^=, |=)
	/*
	expression		equivalent to...
	y += x;			y = y + x;
	x -= 5;			x = x - 5;
	x /= y;			x = x / y;
	*/
	cout << a;
	a += 2;             // equivalent to a=a+2
	cout << a;

	// Increment and decrement (++, --)
	++x;
	x += 1;
	x = x + 1;

	x = 3;
	y = ++x;
	// x contains 4, y contains 4
	x = 3;
	y = x++;
	// x contains 4, y contains 3

	// Relational and comparison operators ( ==, !=, >, <, >=, <= )
	/*
	operator	description
	==			Equal to
	!=			Not equal to
	<			Less than
	>			Greater than
	<=			Less than or equal to
	>=			Greater than or equal to
	 */
	int c = 0;
	(7 == 5);    // evaluates to false
	(5 > 4);    // evaluates to true
	(3 != 2);   // evaluates to true
	(6 >= 6);    // evaluates to true
	(5 < 5);    // evaluates to false
	(a == 5);    // evaluates to false, since a is not equal to 5
	(a * b >= c);  // evaluates to true, since (2*3 >= 6) is true
	(b + 4 > a * c);  // evaluates to false, since (3+4 > 2*6) is false
	((b = 2) == a); // evaluates to true 

	// Logical operators ( !, &&, || )
	!(5 == 5);  // evaluates to false because the expression at its right (5 == 5) is true
	!(6 <= 4);   // evaluates to true because (6 <= 4) would be false
	!true;    // evaluates to false
	!false;   // evaluates to true

	((5 == 5) && (3 > 6));  // evaluates to false ( true && false )
	((5 == 5) || (3 > 6));  // evaluates to true ( true || false )

	// Conditional ternary operator ( ? )
	7 == 5 ? 4 : 3;     // evaluates to 3, since 7 is not equal to 5.
	7 == 5 + 2 ? 4 : 3;   // evaluates to 4, since 7 is equal to 5+2.
	5 > 3 ? a : b;      // evaluates to the value of a, since 5 is greater than 3.
	a > b ? a : b;      // evaluates to whichever is greater, a or b.  

	// Comma operator ( , )
	a = (b = 3, b + 2);

	// Bitwise operators ( &, |, ^, ~, <<, >> )
	/*
	 operator		asm equivalent		description
	&				AND					Bitwise AND
	|				OR					Bitwise inclusive OR
	^				XOR					Bitwise exclusive OR
	~				NOT					Unary complement (bit inversion)
	<<				SHL					Shift bits left
	>>				SHR					Shift bits right
	 */
	a = 5, b = 9; 		// a = 5(00000101), b = 9(00001001) 
	printf("a = %d, b = %d\n", a, b);
	printf("a&b = %d\n", a & b); 			// The result is 00000001 
	printf("a|b = %d\n", a | b); 		// The result is 00001101 
	printf("a^b = %d\n", a ^ b); 			// The result is 00001100 
	printf("~a = %d\n", a = ~a); 		// The result is 11111010 
	printf("b<<1 = %d\n", b << 1); 		// The result is 00010010 
	printf("b>>1 = %d\n", b >> 1); 		// The result is 00000100 

	// Explicit type casting operator
}
