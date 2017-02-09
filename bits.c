#include <cstdio>

#include <vector>

using namespace std;

int SetBits(int dest, int src, int startPos, int endPos)
{
	for (int i = startPos; i < endPos; i++)
	{
		int bitPattern = (src & (1 << i));
		if (bitPattern > 0)
		{
			// we need to set a 1 at that location in dest
			dest |= bitPattern;
		}
		else
		{
			// we need to set a 0 at that location in dest
			dest &= (bitPattern | ~(1 << i));
		}
	}

	return dest;
}

int GetBit(int val, int bitPos)  //  bitPos is [0, 31]
{
	return ((val >> bitPos) & 0x1);
}

int SetBit(int val, int bitPos, bool bitVal)
{
	if (bitVal) // set to 1
	{
		return (val | (1 << bitPos));
	}
	else
	{
		// set to 0
		return (val & ~(1 << bitPos));
	}
}

int NumBitsToConvert(int n1, int n2)
{
	int numBitsToChange = 0;
	for (int i = 0; i < sizeof(int)*8; i++)
	{
		if (((n1 >> i) ^ (n2 >> i)) & 0x1 > 0)
		{
			numBitsToChange++;
		}
	}
	return numBitsToChange;
}

void setNumIntoBitSet(int num, char arr4k[4000])
{
	int index = (num - 1) / 8;
	int bitPos = (num - 1) % 8;
	arr4k[index] |= (0x1 << bitPos);
}

bool isNumSet(int num, char arr4k[4000])
{
	int index = (num - 1) / 8;
	int bitPos = (num - 1) % 8;
	return (arr4k[index] & (0x1 << (bitPos - 1)) > 0);	
}

// print all duplicate elements in the given array while only using the 4KB array provided 
void PrintAllDuplicateElements(vector<int> numVec, char arr4k[4000])
{
	int numElements = numVec.size();
	for (int i = 0; i < numElements; i++)
	{
		//printf("Testing numVec[%d] = %d\n", i, numVec[i]);
		if (isNumSet(numVec[i], arr4k))
		{
			printf("Repeated: %d\n", numVec[i]);
		}
		else
		{
			setNumIntoBitSet(numVec[i], arr4k);
		}
	}
}


int main()
{
	/*
	int src = 2;
	int dest = 4;
	int startPos = 1;
	int endPos = 3;
	int result = SetBits(src, dest, startPos, endPos);
	printf("%d(%d..%d) = %d => %d\n", src, startPos, endPos, dest, result);
	return 0;
	*/
	/*
	int n1 = 32;
	int n2 = 14;
	printf("Num bits to convert %d to %d = %d", n1, n2, NumBitsToConvert(n1, n2));
	*/

	vector<int> numVec;
	numVec.resize(32000);
	for (int i = 0; i < 32000; i++)
	{
		numVec[i] = (rand() % 32000) + 1;
	}

	char arr4k[4000];
	PrintAllDuplicateElements(numVec, arr4k);
}