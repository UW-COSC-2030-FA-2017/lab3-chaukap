// lab3-chaukap.cpp
// Chandler Haukap
// COSC 2030 2017
// Containes multiple series that will be used to overflow the memory.

#include<iostream>
using std::cout;
using std::endl;

#include<iomanip>
using std::setprecision;
using std::setw;
using std::setfill;

short shortSum(short n)
{
	short sum(0);

	for (short i = n; i > 0; i--)
	{
		sum += i;
	}

	return sum;
}

long longSum(long n)
{
	long sum(0);

	for (long i = n; i > 0; i--)
	{
		sum += i;
	}

	return sum;
}

// long long will be used to find the true value and prove that the overflow occurs 
// where specified.
long long longLongSum(long long n)
{
	long long sum(0);

	for (long long i = n; i > 0; i--)
	{
		sum += i;
	}

	return sum;
}

float factorial(long n)
{
	float sum(1);

	for (long i = n; i > 1; i--)
	{
		sum *= i;
	}

	return sum;
}

double doubleFactorial(long n)
{
	double sum(1);

	for (long i = n; i > 1; i--)
	{
		sum *= i;
	}

	return sum;
}


// will be used to find the point where factorial() rounds the number for the first time
// lond double should be far more precise than float
long double longDoubleFactorial(long n)
{
	long double sum(1);

	for (long i = n; i > 1; i--)
	{
		sum *= i;
	}

	return sum;
}

float nOverNFloat(float n)
{
	float ratio = (1 / n);
	float sum(0);

	for (long i = n; i > 0; i--)
	{
		sum += ratio;
	}

	return sum;
}

double nOverNDouble(double n)
{
	double ratio = (1 / n);
	double sum(0);

	for (long i = n; i > 0; i--)
	{
		sum += ratio;
	}

	return sum;
}

int main()
{
	// Part 1 and 2
	cout << "Part 1 and 2;" << endl;
	cout << "Testing shortSum();" << endl;
	cout << "shortSum(2)= " << shortSum(2) << " , shortSum(5)= " << shortSum(5) << endl;
	cout << "Finding the overflow point;" << endl;
	cout << "shortSum(255)= " << shortSum(255) << " , shortSum(256)= " << shortSum(256) << endl;
	cout << "Correct answers using long long data type;" << endl;
	cout << "longLongSum(255)= " << longLongSum(255) << " , longLongSum(256)= " << longLongSum(256) << endl 
		<< "Overflow occurs at n = 256 " << endl << endl;
	// The overflow occurs at n = 256. The value spilled over into the memory location holding the sign
	// and made the number negative.


	// Part 3
	cout << "Part 3;" << endl;
	cout << "Testing longSum();" << endl;
	cout << "longSum(2)= " << longSum(2) << " , longSum(5)= " << longSum(5) << endl;
	cout << "Finding the overflow point;" << endl;
	long counter(65500); // Loop to find the value where the sign changes. 65500 chosen as starting point after previous testing.
	while (longSum(counter) > 0)
	{
		counter++;
	}
	cout << "hit negative number at n = " << counter  << endl;
	cout << "longSum(65535)= " << longSum(65535) << " , longSum(65536)= " << longSum(65536) << endl;
	cout << "Correct answers using long long data type;" << endl;
	cout << "longLongSum(65535)= " << longLongSum(65535) << " , longLongSum(65536)= " << longLongSum(65536) << endl << endl;
	// The overflow occurs at n = 65535. The value spilled over into the memory location holding the sign
	// and made the number negative.


	// Part 4
	cout << "Part 4;" << endl;
	cout << "Testing factorial with type float;" << endl;
	cout << "factorial(4)= " << factorial(4) << " , factorial(5)= " << factorial(5) << endl;
	cout << "Finding the point where the answer first looses precision;" << endl;
	long counter2(13); 
	//loop to find where the value of the two factorial functions return different numbers
	while (factorial(counter2) == longDoubleFactorial(counter2))
	{
		counter2++;
	}
	cout << "Number rounded at n = " << counter2 << endl << setprecision(20); // show the whole number to find error
	cout << "longDoubleFactorial(13)= " << longDoubleFactorial(13) << " , factorial(13): " << factorial(13) << endl;
	cout << "longDoubleFactorial(14)= " << longDoubleFactorial(14) << " , factorial(14): " << factorial(14) << endl;
	// floating point numbers can handle larger numbers because they can round. 
	// However, floats will eventually report "inf" if the number is large enough
	cout << "The point where C++ gives up is; " << endl;
	cout << "factorial(34) = " << factorial(34) << " , factorial(35) = " << factorial(35) << endl << endl;


	// Part 5
	cout << "Part 5;" << endl;
	cout << "Testing factorial with type double;" << endl;
	cout << "doubleFactorial(4)= " << doubleFactorial(4) << " , doubleFactorial(5)= " << doubleFactorial(5) << endl;
	// cout << "Finding the point where the answer first loses precision;" << endl;
	//long counter3(60);
	//while(doubleFactorial(counter3) == longDoublefactorial(counter3))
	//{
	//	counter3++;
	//	cout << "testing " << counter3 << endl;
	//}
	// the previous loop did not end which means that for factorials doubleFactorial and longDoubleFactorial both lost
	// precision at the same rate. They also reported infinite at the same values, most likely due to the rapid growth
	// of the factorial function
	cout << "doubleFactorial(170)= " << doubleFactorial(170) << " , doubleFactorial(171)= " << doubleFactorial(171) << endl;
	// The function overflows at n = 171. The value is reported as infinite just like the float type.
	cout << "longDoubleFactorial(170)= " << longDoubleFactorial(170) << " , longDoubleFactorial(171)= " << longDoubleFactorial(171) << endl << endl;
	// Upon further inspection, both functions overflow at the same time. This is due to the fact that factorial growth
	// is one of the fastes growing functions. If the summation function was performed with them there would most likely be
	// a point were their values diverge due to rounding errors.


	// Part 6
	cout << "Part 6;" << endl;
	cout << "Testing n over n summation using type float and type double;" << endl;
	cout << setw(69) << setfill('-') << "" << endl << setfill(' ');
	cout << setw(7) << "n:  |" << setw(20) << " expected value: |" << setw(21) << "float        |" << setw(21) << "double        |" << endl << setprecision(18);
	for (int i = 30; i < 51; i++)
	{
		cout << setw(6) << i << "|" << setw(19) << 1 << "|" << setw(20) << nOverNFloat(i) << "|" << setw(20) << nOverNDouble(i) << "|" << endl;
	}
	cout << setw(69) << setfill('-') << "" << endl << setfill(' ') << endl;
	// float and double both aproximate when computing numbers like 1/3 because the decimal equivalent goes on forever. Therefore
	// after repeated additions the error will grow and eventually become visible in the output. The larger the number the larger
	// the error will be. Float was more likely to return "1" than double, but for the values where float did have an error the 
	// error was always greater than double.


	// Part 7
	cout << "Part 7;" << endl << setprecision(40);
	for (float i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}
	cout << endl;
	// Upon runnin the code it executed 6 times instead of 5 as expected. this is because the value on round 6 was slightly less than 4.4.
	// Numbers like .2 or 2/10 in base ten do not necesarily have writeable counterparts in base two. Therefore just because the number is writeable in
	// base 10 does not mean that it can be expressed precisely in base 2. That is why the function containes a rounding error even though there
	// is no inherent error when looking at the values in base 10. 4 is of course very easy to write in binary and the rounding error cannot be detected


	// Part 8
	cout << "Part 8;" << endl;
	for (double i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}
	// The effect is similar to the floating point block, except the results are closer to the true values. also in the 6th iteration the value of i
	// is slightly higher that 4.4 and the loop ends when expected.

	return 0;
}