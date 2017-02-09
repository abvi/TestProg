// Question 8.5 in Cracking the Coding Interview
// Implement an algorithm to print all valid (e g , properly opened and closed) combi- nations of n-pairs of parentheses

#include <string>

#include <cstdio>

using namespace std;

void PrintMatchingParens(int numUnbalancedLeftParens, int totalNumLeftParens, int maxNumLeftParens, string stringSoFar)
{
	//printf("INTERMEDIATE: %s, numUnbalancedLeftParens=%d, totalNumLeftParens=%d\n", stringSoFar.c_str(), numUnbalancedLeftParens, totalNumLeftParens);

	if (numUnbalancedLeftParens > 0)
	{
		// add a right paren
		PrintMatchingParens(numUnbalancedLeftParens - 1, totalNumLeftParens, maxNumLeftParens, stringSoFar + ")");
	}

	if (totalNumLeftParens < maxNumLeftParens)
	{
		// ad a left paren
		PrintMatchingParens(numUnbalancedLeftParens + 1, totalNumLeftParens + 1, maxNumLeftParens, stringSoFar + "(");
	}
	
	if (totalNumLeftParens == maxNumLeftParens && numUnbalancedLeftParens == 0)
	{
		// print the string so far
		printf("%s\n", stringSoFar.c_str());
	}

}

int main()
{
	int numParens = 3;

	string str;
	PrintMatchingParens(0, 0, numParens, str);
}