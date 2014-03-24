#include <cstdio>
#include <climits>

#include <set>
#include <string>

const int NUMROWS = 3;
const int NUMCOLS = 3;

void SetRowToZero(int arr[NUMROWS][NUMCOLS], int rowIndex)
{
	for (int i = 0; i < NUMROWS; i++)
	{
		arr[rowIndex][i] = 0;
	}
}

void SetColToZero(int arr[NUMROWS][NUMCOLS], int colIndex)
{
	for (int i = 0; i < NUMCOLS; i++)
	{
		arr[i][colIndex] = 0;
	}
}

void SetRowAndColToZero(int arr[NUMROWS][NUMCOLS])
{
	// find which rows/cols have a zero
	typedef std::set<int>::iterator intSetIt;
	std::set<int> rowsWithZeros;
	std::set<int> colsWithZeros;
	for (int i = 0; i < NUMROWS; i++)
	{
		for (int j = 0; j < NUMCOLS; j++)
		{
			if (arr[i][j] == 0)
			{
				rowsWithZeros.insert(i);
				colsWithZeros.insert(j);
				break;
			}
		}
	}

	// iterate over the array and for whichever coordinates correspond to a row or column
	// with zeros, set the entire row/col to 0
	for (intSetIt it = rowsWithZeros.begin(); it != rowsWithZeros.end(); it++)
	{
		SetRowToZero(arr, *it);
	}
	for (intSetIt it = colsWithZeros.begin(); it != colsWithZeros.end(); it++)
	{
		SetColToZero(arr, *it);
	}
}

void PrintArr(int arr[NUMROWS][NUMCOLS])
{
	for (int i = 0; i < NUMROWS; i++)
	{
		for (int j = 0; j < NUMCOLS; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}	
}

bool IsBigEndian()
{
	int x = 0xff;
	char *xp = (char *)&x;
	if (*xp == (char)0xff)  // the lowest byte has the LSB -- little endian
	{
		return false;
	}
	else
	{
		return true;
	}
}

int FindLargestValue(int arr[], int numElts)
{
	int max = INT_MIN;
	for (int i = 0; i < numElts; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

std::string toHex(int c)
{
	int c1 = c/16;
	int c2 = c%16;
	std::string ret;
	ret.resize(2);
	ret[0] = (c1 > 9? 'A'+(c1-10) : c1);
	ret[1] = (c2 > 9? 'A'+(c2-10) : c2);

	printf("c=%d, c1=%d, c2=%d, ret[0]=%c, ret[1]=%c\n", c, c1, c2, ret[0], ret[1]);
	return ret;
}

std::string FormatColor(char rgb[3])
{
	printf("toHex(rgb[2])=%s\n", toHex(rgb[2]).c_str());
	printf("toHex(rgb[1])=%s\n", toHex(rgb[1]).c_str());
	printf("toHex(rgb[0])=%s\n", toHex(rgb[0]).c_str());
	return toHex(rgb[2]) + toHex(rgb[1]) + toHex(rgb[0]);
}

int main()
{
	/*
	int arr[NUMROWS][NUMCOLS] = { { 1,2,3}, {3,4, 0}, {2,3,4}};
	printf("sizeof(arr)=%d\n", sizeof(arr));
	printf("sizeof(arr[0])=%d\n",sizeof(arr[0]));
	printf("sizeof(arr[1])=%d\n",sizeof(arr[1]));
	printf("sizeof(arr[0][0])=%d\n",sizeof(arr[0][0]));

	PrintArr(arr);
	printf("=>\n");
	SetRowAndColToZero(arr);
	PrintArr(arr);

	printf("This machine is %s", IsBigEndian()? "big endian" : "little endian");
	*/

	char arr[3] = { 0xff, 0xff, 0xff };
	printf("Formatted color=%s\n", FormatColor(arr).c_str());
}