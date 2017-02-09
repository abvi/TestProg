// 11.4

#include <bitset>

void PrintDuplicates(int arr[], int len)
{
	bitset<32000> b;
	for (int i = 0; i < len; i++)
	{
		if (test(b[arr[i]] == true)
		{
			printf("%d ", arr[i]);
		}
		b[arr[i]] = true;
	}
}