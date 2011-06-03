/*
 * BigInteger Class, performs basic arithmetic operations of very large integers.
 * Copyright (C) 2011  Mahmoud Mechehoul
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "BigInteger.h"

using namespace std;

#define ADD 0
#define MUL 1

void big_integer_class_tester();

void small_integer_tester(int tests, int operation);

void big_integer_addition_tester();

void big_integer_multiplication_tester();

int main() {
	big_integer_class_tester();
	small_integer_tester(1000, ADD);
	small_integer_tester(1000, MUL);
	big_integer_addition_tester();
	big_integer_multiplication_tester();

	return 0;
}

void big_integer_class_tester() {
	cout << "Big Integer Class Tester" << endl;

	BigInteger big_int_0("0");
	BigInteger big_int_0s("00000000");
	BigInteger big_int_1_digit(9);
	BigInteger big_int_10(10);
	BigInteger big_int_1000(1000);
	BigInteger big_int(0xFFFFFFFF);
	BigInteger very_big_int("7" + string(50, '9') + "8");
	BigInteger overflow("4294967296");

	cout << "Zero: " << big_int_0.toString() << endl;
	cout << "Zeros: " << big_int_0s.toString() << endl;
	cout << "Single digit: " << big_int_1_digit.toString() << endl;
	cout << "Ten: " << big_int_10.toString() << endl;
	cout << "Thousand: " << big_int_1000.toString() << endl;
	cout << "Big integer: " << big_int.getIntValue() << endl;
	cout << "Real big integer: " << very_big_int.toString() << endl;
	cout << "Overflow: " << overflow.getIntValue() << endl;
	cout << endl;
}

/* operation: 0 for addition, 1 for multiplication */
void small_integer_tester(int tests, int operation) {
	cout << "Small Integer " << (operation == 0 ? "Addition" : "Multiplication") << " Tests" << endl;
	srand(time(NULL));
	int failed = 0;
	for (int i = 0; i < tests; i++) {
		int c = floor(sqrt(0xFFFFFF));
		int a = rand() % c, b = rand() % c;
		BigInteger big_a(a), big_b(b);
		bool fail;
		if (operation == 0) {
			fail = BigInteger(a + b).toString() != (big_a + big_b).toString();
		} else {
			fail = BigInteger(a * b).toString() != (big_a * big_b).toString();
		}
		failed += (fail ? 1 : 0);
	}
	cout << failed << " tests failed from " << tests << endl << endl;
}

void big_integer_addition_tester() {
	cout << "Big Integer Addition Tests" << endl;

	BigInteger small("99");
	BigInteger big(string(10, '9'));
	BigInteger very_big(string(30, '9'));
	BigInteger small_big = BigInteger("10000000098");
	BigInteger small_very_big = BigInteger("1000000000000000000000000000098");
	BigInteger very_big_twice = BigInteger("1999999999999999999999999999998");

	cout << "Small + Big: " << (small + big == big + small) << " " << (big + small == small_big) << endl;

	cout << "Small + Very Big: " << (small + very_big == very_big + small) << " " << (very_big + small == small_very_big) << endl;

	cout << "Very Big + Very Big: " << (very_big + very_big == very_big_twice) << endl;

	cout << endl;
}

void big_integer_multiplication_tester() {
	cout << "Big Integer Multiplication Tests" << endl;

	BigInteger small("99");
	BigInteger big(string(10, '9'));
	BigInteger very_big(string(30, '9'));
	BigInteger small_big("989999999901");
	BigInteger small_very_big("98999999999999999999999999999901");
	BigInteger very_big_twice("999999999999999999999999999998000000000000000000000000000001");

	cout << "Small * Big: " << (small * big == big * small) << " " << (big * small == small_big) << endl;

	cout << "Small * Very Big: " << (small * very_big == very_big * small) << " " << (very_big * small == small_very_big) << endl;

	cout << "Very Big * Very Big: " << (very_big * very_big == very_big_twice) << endl;

	cout << endl;
}
