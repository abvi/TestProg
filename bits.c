#include <cstdio>

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
	int n1 = 32;
	int n2 = 14;
	printf("Num bits to convert %d to %d = %d", n1, n2, NumBitsToConvert(n1, n2));
}