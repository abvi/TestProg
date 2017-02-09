// Question 11.4 in Cracking the Coding Interview

#include <bitset>
#include <vector>

#include <cstdio>

using namespace std;

bitset<32000> mem;

void PrintDuplicates(const vector<int>& intVec)
{
	typedef vector<int>::const_iterator VecIt;
	for (VecIt it = intVec.begin(); it != intVec.end(); it++)
	{
		int num = *it;
		if (bool(mem[num]) != false)
		{
			// this is a duplicate
			printf("Duplicate found: %d\n", num);
		}
		else
		{
			mem[num] = true;
		}
	}
}

void ConstructVector(vector<int>& intVec)
{
	intVec.push_back(4);
	intVec.push_back(3);
	intVec.push_back(4);   // duplicate
	intVec.push_back(25);
	intVec.push_back(23);
	intVec.push_back(25);  // duplicate
}

int main()
{
	vector<int> intVec;
	ConstructVector(intVec);
	PrintDuplicates(intVec);

	return 0;
}