#include <cstdio>

#include <vector>
#include <set>

using namespace std;

struct node
{
	int data;
	node *next;
};

/* AV:
int Insert(node **head, int data)
{
	node *cur = *head;
	node *prev = NULL;
	while (cur != NULL && cur->data > data)
	{
		prev = cur;
		cur = cur->next;
	}

	node *newNode = new node;
	newNode->data = data;
	if (prev)
	{
		prev->next = newNode;
	}
	else
	{
		*head = newNode;
	}

	newNode->next = cur;
	return 0;
}

void Split(node *head, int pivot, node **lt, node **gt)
{
	node *cur = head;
	node *prev = NULL;
	while (cur && cur->data > pivot)
	{
		prev = cur;
		cur = cur->next;
	}

	*gt = head;
	if (prev) prev->next = NULL;

	*lt = cur;
}

bool HasCycle(node *head)
{
	std::vector<node *> seenNodes;
	node *cur = head;
	while (cur)
	{
		if (std::find(seenNodes.begin(), seenNodes.end(), cur->data) != seenNodes.end())
		{
			return true;  // found a cycle
		}
		else
		{
			seenNodes.push_back(cur);
			cur = cur->next;
		}
	}
	return false;
}

void DeleteNode(node **head, int d)
{
	node *prev = NULL;
	node *cur = *head;
	while (cur && *cur != d)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur)
	{
		if (prev) 
		{
			prev->next = cur->next;
		}
		else
		{
			// the first element of the list got deleted
			*head = cur->next;
		}
		free(cur);
	}
}
*/

node *CreateNode(int val, node **prev, node **head)
{
	node *newNode = new node;
	newNode->data = val;
	newNode->next = NULL;

	if (*prev) (*prev)->next = newNode;
	if (*head == NULL)
	{
		//printf("Setting head to %d\n", newNode);
		*head = newNode;
	}
	*prev = newNode;
	return newNode;
}

node *AddNumbers(node *num1h, node *num2h)
{
	node *result = NULL;
	node *prev = NULL;
	int carry = 0;
	while (num1h && num2h)
	{
		int add = num1h->data + num2h->data + carry;
		//printf("Inserting %d\n", add);
		if (add >= 10)
		{
			carry = add / 10;
			add = add % 10;
		}

		node *newNode = CreateNode(add, &prev, &result);
		num1h = num1h->next;
		num2h = num2h->next;
	}

	// one or both of the numbers are done
	if (num1h)
	{
		while (num1h)
		{
			int add = num1h->data+carry;
			if (add >= 10)
			{
				carry = add / 10;
				add = add % 10;
			}
			node *newNode = CreateNode(add, &prev, &result);
			num1h = num1h->next;
		}
	}
	else if (num2h)
	{
		while (num2h)
		{
			int add = num2h->data+carry;
			if (add >= 10)
			{
				carry = add / 10;
				add = add % 10;
			}
			node *newNode = CreateNode(num2h->data, &prev, &result);
			num2h = num2h->next;
		}
	}

	if (carry > 0)
	{
		CreateNode(carry, &prev, &result);
	}

	return result;
}

node *CreateLinkedList(std::vector<int>& num)
{
	int numElts = (int)num.size();
	//printf("num elements=%d\n", numElts);
	node *head = NULL;
	node *prev = NULL;
	for (int i = 0; i < numElts; i++)
	{
		//printf("Creating node for %d\n", num[i]);
		CreateNode(num[i], &prev, &head);
		//printf("head=%d, prev=%d\n", head, prev);
	}
	return head;
}

void PrintLinkedList(node *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

void RemoveDuplicates(node *head)
{
	set<int> seenValues;
	node *cur = head;
	node *prev = NULL;
	while (cur != NULL)
	{
		if (seenValues.find(cur->data) != seenValues.end())
		{
			// seen before
			if (prev)
			{
				prev->next = cur->next;
			}
			cur = cur->next;
		}
		else
		{
			seenValues.insert(cur->data);
			prev = cur;
			cur = cur->next;
		}
	}
}

int main()
{
	printf("Running linkedlist program\n");

	/* AV:
	int num1[] = {0,9,4};
	std::vector<int> arr1(num1, num1+sizeof(num1)/sizeof(num1[0]));

	int num2[] = {1,3,9};
	std::vector<int> arr2(num2, num2+sizeof(num2)/sizeof(num2[0]));

	node *list1 = CreateLinkedList(arr1);
	node *list2 = CreateLinkedList(arr2);

	printf("Adding numbers:\n");
	PrintLinkedList(list1);
	printf(" + ");
	PrintLinkedList(list2);
	printf(" = ");
	node *sum = AddNumbers(list1, list2);
	PrintLinkedList(sum);
	*/

	int num3[] = {0,9,4,9,0,4,1,2};
	std::vector<int> arr3(num3, num3+sizeof(num3)/sizeof(num3[0]));

	node *list3 = CreateLinkedList(arr3);
	RemoveDuplicates(list3);
	PrintLinkedList(list3);

	return 1;
}