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

#ifndef BIGINT_H_
#define BIGINT_H_

#include <iostream>

using namespace std;

class BigInteger {
private:
	string integer;
public:
	/* Constructs a big integer representation of the integer given as an argument */
	BigInteger(unsigned int integer);

	/* Parses the string given as an argument looking for an integer.
	 * Stops as soon as it finds a non-digit character.
	 * Trailing zeros will eventually get removed.
	 */
	BigInteger(string integer);

	/* Constructs a big integer representation of the integer given as an argument
	 * and assigns it to the internal representation of the big integer.
	 */
	void setInteger(unsigned int integer);

	/* Parses the string given as an argument looking for an integer and assigns it to
	 * the internal representation of the big integer.
	 * Stops as soon as it finds a non-digit character.
	 * Trailing zeros will eventually get removed.
	 */
	void setInteger(string integer);

	/* Returns 0 if the value of the internal big integer won't fit in 32 bits.
	 * Otherwise it returns the integer values.
	 */
	unsigned int getIntValue() const;

	/* Returns the internal big integer as a string */
	string toString() const;

	/* Adds the big integer given as an argument to the internal big integer
	 * and returns the result as a string.
	 */
	BigInteger addInteger(const BigInteger& integer_to_add) const;

	/* Adds the integer represented by the string given as an argument to the internal
	 * big integer and returns the result as a string.
	 */
	BigInteger addInteger(const string& integer_to_add) const;

	/* Multiplies the big integer given as an argument by the internal big integer
	 * and returns the result as a string.
	 */
	BigInteger multiplyInteger(const BigInteger& integer_to_multiply) const;

	/* Multiplies the integer represented by the string given as an argument by the internal
	 * big integer and returns the result as a string.
	 */
	BigInteger multiplyInteger(const string& integer_to_multiply) const;

	/* Returns the index of the first non-zero digit in the string given as an argument.
	 * This function is used to trim trailing zeros from a string representation of an integer.
	 * A trimmed version of the string is a substring that starts at the index returned by this
	 * function.
	 */
	static size_t getTrimIndex(const string& integer);

	bool operator==(const BigInteger& integer) const;

	BigInteger operator+(const BigInteger& integer) const;

	BigInteger operator*(const BigInteger& integer) const;
};

#endif /* BIGINT_H_ */
