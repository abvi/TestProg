// From https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493
/*
A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a zig-zag sequence.

For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. A subsequence is obtained by deleting some number of elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
*/

#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef enum { INC, DEC, ANY } Sign;

bool continuesSequence(int nextNum, int prevNum, int nextSign) {
	if ((nextSign == ANY || nextSign == INC) && nextNum > prevNum)
		return true;
	else if ((nextSign == ANY || nextSign == DEC) && nextNum < prevNum)
		return true;

	return false;
}

int longestZigZag(int arr[], int numElts) {
	vector<int> maxLen(numElts, 0); // all 0s
	vector<Sign> nextSign(numElts);

	maxLen[0] = 1;
	nextSign[0] = ANY;
	for (int i = 1; i < numElts; i++) {
		bool foundSequenceContinuation = false;
		for (int j = 0; j < i; j++) {
			// does the difference between the ith and jth element
			// have the right sign?
			if (continuesSequence(arr[i], arr[j], nextSign[j])) {
				foundSequenceContinuation = true;
				if (maxLen[j] + 1 > maxLen[i]) {
					maxLen[i] = maxLen[j] + 1;
					nextSign[i] = (
						nextSign[j] == INC ? DEC : 
						(nextSign[j] == DEC? INC : 
							(arr[i] > arr[j] ? DEC : INC)));
				}
			}
		}
		if (!foundSequenceContinuation) {
			// this element could not continue a sequence with any previous
			// element
			maxLen[i] = 0;
			nextSign[i] = ANY;

		}
	}

	return *max_element(maxLen.begin(), maxLen.end());
}

int main() {
	// int arr[] = { 1, 7, 4, 9, 2, 5 }; // should return 6
	// int arr[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }; // should return 7
	// int arr[] = { 44 };  // should return 1
	// int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // should return 2
	// int arr[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };  // should return 8
	int arr[] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };  // should return 36
	printf("Max zig-zag sequence = %d\n", longestZigZag(arr, 
			sizeof(arr)/sizeof(arr[0])));
	return 0;
}