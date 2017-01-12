# RANDMedian

Excerpt from TopCoder https://www.topcoder.com/community/data-science/data-science-tutorials/the-importance-of-algorithms/

"Another algorithm that uses random numbers finds the median of a group of numbers with an average runtime of O(N). This is a significant improvement over sorting the numbers and taking the middle one, which takes O(N*Log(N)). Furthermore, while deterministic (non-random) algorithms exist for finding the median with a runtime of O(N), the random algorithm is attractively simple, and often faster than the deterministic algorithms. 

The basic idea of the median algorithm is to pick one of the numbers in the group at random, and count how many of the numbers in the group are less than it.Lets say there are N numbers, and K of them are less than or equal to the number we picked at random.
If K is less than half of N, then we know that the median is the(N / 2 - K) th number that is greater than the random number we picked, 
so we discard the K numbers less than or equal to the random number.Now, we want to find the(N / 2 - K) th smallest number, 
instead of the median.The algorithm is the same though, and we simply pick another number at random, and repeat the above steps."

RandomMedian.cpp is my implementation of a random algorithm that finds the Median in a vector of integers.

Assumption:
Define a Median M in a list of integers: it is the middle number that divides the list into equal parts - i.e. the number of integers less than or equal to (covers the even number of integers case) M is the same as the number of integers larger than M.

Test case 1:
input: 5 2 7 15 20 1 19
Median: 7
