#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

void fib(int n)
{
	int a = 0;
	int b = 1;
	for (int i = 1; i <= n; i++)
	{
		int c = a+b;
		printf("%d ", b);
		a = b;
		b = c;
	}
}

void PrintAllSubsets(const char *set, int numElts, string strSoFar, int& numSubsetsPrintedSoFar)
{
	//printf("PrintAllSubsets(%s, %d, %s)\n", set, numElts, strSoFar.c_str());
	if (numElts == 0)
	{
		printf("%s\n", strSoFar.c_str());
		numSubsetsPrintedSoFar++;
	}
	else
	{
		// don't include the first element
		PrintAllSubsets(set+1, numElts - 1, strSoFar, numSubsetsPrintedSoFar);

		// include the first element
		strSoFar += *set;
		//printf("strSoFar=%s\n", strSoFar.c_str());
		PrintAllSubsets(set+1, numElts - 1, strSoFar, numSubsetsPrintedSoFar);
	}
}

vector<string> PermuteString(const char *str)
{
	//printf("PermuteString(%s)\n", str);
	int strLen = strlen(str);
	if (strLen == 1)
	{
		vector<string> temp;
		temp.push_back(string(str));
		return temp;
	}
	else
	{
		// get all permutations for substrings
		vector<string> perms = PermuteString(str+1);
		//printf("Number of permutations for %s = %d; str=%s\n", str+1, perms.size(), str);

		// insert the first character into all positions in all the permutations so far
		vector<string> permsToReturn;
		char ch = str[0];
		for (int i = 0; i < perms.size(); i++)
		{
			string permi = perms[i];
			for (int j = 0; j <= permi.length(); j++)
			{
				string final = permi.substr(0, j) + ch + permi.substr(j);
				//printf("final=%s\n", final.c_str());
				permsToReturn.push_back(final);
			}
		}
		return permsToReturn;
	}
}

void Count(int sumLeft, vector<int> pathSoFar)
{
	if (sumLeft == 0)
	{
		for (int i = 0; i < pathSoFar.size(); i++)
		{
			printf("%d ", pathSoFar[i]);
		}
		printf("\n");
	}
	else if (sumLeft < 0)
	{
		// no valid path
		return;
	}
	else
	{
		// take a penny
		pathSoFar.push_back(1);
		Count(sumLeft-1, pathSoFar);
		pathSoFar.pop_back();

		// take a nickel
		pathSoFar.push_back(5);
		Count(sumLeft-5, pathSoFar);
		pathSoFar.pop_back();
		
		// take a dime
		pathSoFar.push_back(10);
		Count(sumLeft-10, pathSoFar);
		pathSoFar.pop_back();
		
		// take a quarter
		pathSoFar.push_back(25);
		Count(sumLeft-25, pathSoFar);
		pathSoFar.pop_back();
	}
}

int main()
{
	/* AV:
	printf("Enter n: ");

	int n;
	scanf("%d", &n);
	fib(n);
	*/

	/* AV:
	// all subsets of a set
	string set("sejal");
	string str("");
	int numSubsetsPrintedSoFar = 0;
	PrintAllSubsets(set.c_str(), set.length(), str, numSubsetsPrintedSoFar);
	printf("Num subsets printed = %d, predicted = 2^%d\n", numSubsetsPrintedSoFar, set.length());
	*/

	/* AV:
	// all permutations of a string
	string str("abhi");
	vector<string> allPerms = PermuteString(str.c_str());
	for (int i = 0; i < allPerms.size(); i++)
	{
		printf("%s\n", allPerms[i].c_str());
	}
	printf("Num permutations = %d, predicted = %d!", allPerms.size(), str.length());
	*/

	vector<int> path;
	Count(7, path);

	return 0;
}