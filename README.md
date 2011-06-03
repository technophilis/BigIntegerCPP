BigIntegerCPP, a C++ Big Integer Library
----------------------------------------

BigIntegerCPP is a C++ library that performs basic arithmetic operations on large intergers which would not normally fit in a 64 bits integer.

### Status:

At the present moment the library supports Big Integer Addition and Multiplication.
In the future, I am planning to implement the Substraction and Division operations.
Feel free to fork the project and add your own code. 

### Test:

	Run the following commands

	make tests
	./run_tests
	
### Usage:

	// Create two big integers
	BigInteger a("35742549198872617291353508656626642567");
	BigInteger b("1298074214633706835075030044377087");
	
	// Perfom the addition and multiplication of the big integers
	// and store the result in new objects
	BigInteger c = a + b;
	BigInteger d = a * b;

	// Display the operands (Big Integers) and opration result (another Big Integer)
	cout << a << " + " << b << " = " << c << endl;
	cout << a << " * " << b << " = " << d << endl;
	
### Run Demo:

	I have included a single file implementation for your convenience.
	To run the demo uncomment the code in 'BigIntegerSingleFile' then run the following commands
	
	make demo
	./demo
	
### Author:

Mahmoud Mechehoul (http://mahmoud.devgator.com)