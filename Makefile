all: demo tests

demo : BigIntegerSingleFile.o
	g++ -o demo BigIntegerSingleFile.o

BigIntegerSingleFile.o : BigIntegerSingleFile.cpp
	g++ -c BigIntegerSingleFile.cpp

tests : BigInteger.o tests.o
	g++ -o run_tests BigInteger.o tests.o

BigInteger.o : BigInteger.cpp
	g++ -c BigInteger.cpp

tests.o : tests.cpp
	g++ -c tests.cpp

clean: 
	rm -rf *.o tests demo