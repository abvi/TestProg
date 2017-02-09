// Question 3.6 from Cracking the Coding Interview
// Write a program to sort a stack in ascending order

#include <cstdio>
#include <stack>

using namespace std;

void PrintStackDestructive(stack<int>& stackToPrint)
{
	while (!stackToPrint.empty())
	{
		printf("%d\n", stackToPrint.top());
		stackToPrint.pop();
	}
}

void PrintSorted(stack<int>& orig)
{
	stack<int> scratchStack;
	while (!orig.empty())
	{
		int topOrig = orig.top();
		orig.pop();

		if (scratchStack.empty() || scratchStack.top() < topOrig)
		{
			printf("Pushing %d onto scratch\n", topOrig);
			scratchStack.push(topOrig);
		}
		else
		{
			// pop off elements from the scratch stack, and push them onto the original stack, so that
			// we can push topOrig onto the scratch stack
			while (!scratchStack.empty() && scratchStack.top() > topOrig)
			{
				int transferElt = scratchStack.top();
				scratchStack.pop();

				printf("Transferring %d from scratch to original stack\n", transferElt);
				orig.push(transferElt);
			}

			// push the element onto the stack
			printf("Transfer complete, push %d onto scratch stack\n", topOrig);
			scratchStack.push(topOrig);
		}
	}

	// at this point the scratch stack is sorted in ascending order
	printf("****\nPrinting sorted stack:\n");
	PrintStackDestructive(scratchStack);  // this empties the stack
}

stack<int> MakeStack(int nums[], int numNums)
{
	stack<int> retStack;
	for (int i = 0; i < numNums; i++)
	{
		retStack.push(nums[i]);
	}
	return retStack;
}

int main()
{
	int nums[] = { 0, 5, 4, 29, -36, 78, 43, 0, 1 };
	stack<int> numStack = MakeStack(nums, sizeof(nums)/sizeof(int));
	PrintSorted(numStack);
	return 0;
}