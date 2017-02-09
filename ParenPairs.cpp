// Write a program to output all valid pairs of n balanced parens
#include <string>
#include <cstdio>

using namespace std;

void addParen(string stringSoFar, 
				int numLeftParensSoFar, int numRightParensSoFar,
				int totalParenPairs, 
				char parenToAdd) {
	if (parenToAdd == '(') {
		if (numLeftParensSoFar >= totalParenPairs) {
			// cannot add
			return;
		}
		stringSoFar += '(';
		numLeftParensSoFar++;
	} else {
		// need to add a ')'
		if (numRightParensSoFar >= numLeftParensSoFar) {
			return;
		}
		stringSoFar += ')';
		numRightParensSoFar++;

		if (numRightParensSoFar == totalParenPairs) {
			printf("%s\n", stringSoFar.c_str());
		}
	}

	addParen(stringSoFar, numLeftParensSoFar, numRightParensSoFar, totalParenPairs, '(');
	addParen(stringSoFar, numLeftParensSoFar, numRightParensSoFar, totalParenPairs, ')');			
}

int main() {
	printf("Enter number of paren pairs: ");
	int numPairs = 0;
	scanf("%d", &numPairs);
	addParen("", 0, 0, numPairs, '(');
	return 0;
}