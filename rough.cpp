#include <string>
#include <cstdio>

#include <vector>
#include <set>
#include <map>

using namespace std;

char *reverse(char *str)
{
	for (int i = 0; i < strlen(str)/2; i++)
	{
		char c = str[i];
		str[i] = str[strlen(str)-i-1];
		str[strlen(str)-i-1] = c;
	}

	return str;
}

bool isPalindrome(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len-i-1])
		{
			return false;
		}
	}
	return true;
}

vector<int> knapsack(vector<int>& values, vector<int>& weights, int weightThreshold)
{
	int numItems = values.size();
	for (int i = 0; i < numItems; i++)
	{
		if (weights[i] < weightThreshold)
		{

		}
		else
		{

		}
	}
}

bool hasUniqueChars(const string& str)
{
	set<char> usedChars;
	for (int i = 0; i < str.length(); i++)
	{
		if (usedChars.count(str[i]) > 0)
		{
			return false;
		}
		usedChars.insert(str[i]);
	}
	return true;
}

bool areAnagrams(const string& a, const string& b)
{
	int usedCharCountsA[256] = { 0 };
	int usedCharCountsB[256] = { 0 };

	for (int i = 0; i < a.size(); i++)
	{
		usedCharCountsA[(int)a[i]]++;
	}

	for (int i = 0; i < b.size(); i++)
	{
		usedCharCountsB[(int)b[i]]++;
	}

	for (int i = 0; i < 256; i++)
	{
		if (usedCharCountsA[i] != usedCharCountsB[i])
		{
			return false;
		}
	}

	return true;
}

int numWaysToMakeChange(int amount)
{
	int *numWays = new int[amount+1];
	for (int i = 0; i < amount+1; i++)
	{
		numWays[i] = 0;
	}
	numWays[1] = 1;

	int denominations[] = { 1, 5, 10, 25 };
	for (int i = 0; i < sizeof(denominations)/sizeof(int); i++)
	{
		for (int j = 0; j < amount+1; j++)
		{
			int amountRemaining = j - denominations[i];
			if (amountRemaining >= 0)
			{
				numWays[j] += numWays[amountRemaining];
				//printf("Set numWays[%d] to %d\n", j, numWays[j]);
			}
		}
	}

	int retVal = numWays[amount];
	delete [] numWays;
	return retVal;
}

int main()
{
	//printf("%s\n", reverse((char *)"Test string"));
	/* AV:
	printf("%d\n", isPalindrome((char *)"Hello"));
	printf("%d\n", isPalindrome((char *)"teset"));

	printf("%d\n", hasUniqueChars(string("teset")));
	printf("%d\n", hasUniqueChars(string("abcd")));

	printf("%d\n", areAnagrams(string("abcd"), string("bcad")));
	printf("%d\n", areAnagrams(string("abcd"), string("bcade")));
	*/

	int amounts[] = { 1, 3, 7, 10, 11 };
	for (int i = 0; i < sizeof(amounts)/sizeof(int); i++)
	{
		printf("Num ways to make change for $%d = %d\n", amounts[i], numWaysToMakeChange(amounts[i]));
	}
}