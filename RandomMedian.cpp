#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

	/***	The basic idea of the median algorithm is to pick one of the numbers in the group at random, and count how many of the numbers in the group
			are less than it.Lets say there are N numbers, and K of them are less than or equal to the number we picked at random.
			If K is less than half of N, then we know that the median is the(N / 2 - K) th number that is greater than the random number we picked, 
			so we discard the K numbers less than or equal to the random number.Now, we want to find the(N / 2 - K) th smallest number, 
			instead of the median.The algorithm is the same though, and we simply pick another number at random, and repeat the above steps.
	***/

	/**		Define a Median M in a list of integers: it is the middle number that divides the list into equal parts - i.e. the number of integers less than
			or equal to (covers the even number of integers case) M is the same as the number of integers larger than M.
	**/
int findMedian(std::vector<int> numbers);

void main()
{
	std::vector<int> numbers;
	std::cout << "Please enter the sequence of numbers you wish to find the median for:"<<endl;
	int digit;

	cin >> digit;
	while (!cin.eof())
	{
		//int digitNum = digit - '0';
		numbers.push_back(digit);
		cin >> digit;
	}

	std::cout << "Median for this list of numbers is: " << findMedian(numbers) << endl;

}

int findMedian(std::vector<int> numbers)
{
	std::vector<int> listOfLessThanOrEqualMedianNumbers;
	double N = numbers.size();
	double nthSmallest = std::ceil(N / 2.0);
	while (true)
	{		
		int indexOfMedian = std::rand() % numbers.size(); // stay within range of allowed indices
		int median = numbers.at(indexOfMedian);
		int numberOfIntsLessThanOrEqualMedian = 0;
		
		listOfLessThanOrEqualMedianNumbers.clear();

		for (unsigned int i = 0; i < numbers.size(); ++i)
		{
			if (numbers.at(i) <= median)
			{
				++numberOfIntsLessThanOrEqualMedian;
				listOfLessThanOrEqualMedianNumbers.push_back(numbers.at(i));
			}
		}

		if (numberOfIntsLessThanOrEqualMedian == nthSmallest)
			return median;
		else if (numberOfIntsLessThanOrEqualMedian > nthSmallest)
		{
			numbers = listOfLessThanOrEqualMedianNumbers;
		}
		else if(numberOfIntsLessThanOrEqualMedian < nthSmallest)
		{
			nthSmallest -= listOfLessThanOrEqualMedianNumbers.size();
			for (std::vector<int>::iterator it = listOfLessThanOrEqualMedianNumbers.begin(); it != listOfLessThanOrEqualMedianNumbers.end(); ++it)
			{
				numbers.erase(std::find(numbers.begin(), numbers.end(), *it));
			}

		}
		else if (numbers.size() == 0)
			return 0;
	}

}