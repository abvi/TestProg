#include <cstdio>
#include <vector>

using namespace std;

void MergeSortedArrays(vector<int>& A, vector<int>& B)
{
	vector<int>::iterator itB = B.begin();
	vector<int>::iterator itA = A.begin();
	for (; itB != B.end(); itB++)
	{
		while (itA != A.end() && *itB > *itA)
		{
			printf("*itA=%d, *itB=%d, incrementing itA\n", *itA, *itB);
			itA++;
		}

		if (itA == A.end())
		{
			// insert the remainder of B at the end of A
			printf("Inserting the rest of B at the end of A\n");
			A.insert(A.end(), itB, B.end());
			break;
		}
		else
		{
			// we have found the place where *itB should be inserted
			printf("Inserting %d before %d\n", *itB, *itA);
			A.insert(itA, *itB);
		}
	}	
}

int FindIndexInRotatedSortedArray(vector<int>& nums)
{
	while 
}

int main()
{
	vector<int> A;
	A.push_back(1);
	A.push_back(4);
	A.push_back(6);
	A.push_back(7);
	A.push_back(9);
	A.push_back(11);

	vector<int> B;
	B.push_back(0);
	B.push_back(3);
	B.push_back(7);
	B.push_back(10);

	A.reserve(A.size()+B.size());  // necessary so iterators remain valid in the loop above

	MergeSortedArrays(A, B);
	for (int i = 0; i < A.size(); i++)
	{
		printf("%d ", A[i]);
	}
}