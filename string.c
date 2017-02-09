#include <stdio.h>

#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

/* AV:
char *Reverse(char *str)
{
	int stringLen = strlen(str);
	int middle = stringLen / 2;
	for (int i = 0; i < middle; i++)
	{
		char temp = str[i];
		str[i] = str[stringLen-i-1];
		str[stringLen-i-1] = temp;
	}
	return str;
}

char *ReverseWords(char *sentence)
{
	// find the lengths of all the words in the sentence
	std::vector<int> wordLengths;
	int stringLen = strlen(sentence);
	int curWordLen = 0;
	printf("word lengths = ");
	for (int i = 0; i < stringLen; i++)
	{
		char curChar = sentence[i];
		if (curChar == ' ')
		{
			printf("%d ",curWordLen);
			wordLengths.push_back(curWordLen);
			curWordLen = 0;
		}
		else
		{
			curWordLen++;
		}
	}

	printf("%d ",curWordLen);
	wordLengths.push_back(curWordLen);
	printf("\n\n");

	// now reverse each word
	for (int i = 0; i < stringLen; i++)
	{
		int j = FindExchangeIndex(i, wordLengths);
		char temp = sentence[i];
		sentence[i] = sentence[j];
		sentence[j] = temp;
	}

	return sentence;
}

int FindExchangeIndex(int index, std::vector<int>& wordLengths)
{
	// find the length of the current word
	int wordLenSum = 0;
	int prevWordLenSum = 0;
	int i = 0;
	while (wordLenSum < index)
	{
		prevWordLenSum = wordLenSum;
		wordLenSum = wordLengths[i++];
	}
}
*/

bool hasAllUnique(string& str)
{
	set<char> seenChars;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (seenChars.contains(c))
		{
			return false;
		}

		seenChars.push(c);
	}

	return seenChars;
}

void test()
{
	std::vector<int> intVec;
	intVec.push_back(25);
	printf("intVec[0] = %d", intVec[0]);
}

std::vector<std::string> merge(std::vector<std::string>& words, std::vector<std::string>& more) 
{
	std::vector<std::string> ret;
	typedef std::vector<std::string> strVecType;
	for (strVecType::iterator stvIt = words.begin(); stvIt != words.end(); stvIt++)
	{
		ret.push_back(*stvIt);
	}
	for (strVecType::iterator stvIt = more.begin(); stvIt != more.end(); stvIt++)
	{
		ret.push_back(*stvIt);
	}
	return ret;
}

void PrintElt(std::string& str)
{
	printf("%s\n", str.c_str());
}

void ReverseStr(char *str)  // str is \0 terminated
{
	char *p = str;
	char *q = str;
	while (*q) q++;
	q--;
	while (p < q)
	{
		char t = *p;
		*p = *q;
		*q = t;
		p++;
		q--;
	}

	printf("%s", str);
}

void MoveAllCharsLeft(std::string::iterator it, std::string& orig)
{
	std::string::iterator copyIt = it;
	it++;
	while (it != orig.end())
	{
		*copyIt = *it;
		it++;
		copyIt++;
	}
	orig.resize(orig.length()-1);
}

void RemoveDuplicateChars(std::string& str)
{
	std::set<char> seenChars;
	for (std::string::iterator it = str.begin(); it != str.end();)
	{
		if (seenChars.find(*it) != seenChars.end())
		{
			// remove this char in place
			printf("Calling MoveAllCharsLeft at %c\n", *it);
			MoveAllCharsLeft(it, str);
		}
		else
		{
			// add it to the list of seen chars
			printf("adding %c to seenChars\n", *it);
			seenChars.insert(*it);
			it++;
		}
	}
}

std::vector<std::string> GetPermutations(const std::string& str)
{
	if (str.length() == 1)
	{
		std::vector<std::string> ret;
		ret.push_back(str);
		return ret;
	}
	else
	{
		char firstChar = str[0];
		std::vector<std::string> perms = GetPermutations(str.substr(1));

		// push firstChar into each location
		for (int i = 0; i < perms.size(); i++)
		{
			std::string permi = perms[i];
			for (int j = 1; j < permi.length(); j++)
			{
				perms[i] = permi.substr(0, j-1) + firstChar + permi.substr(j);
			}
		}

		return perms;
	}
}

vector<string> GetAllPermutations(const string& str)
{
	printf("=====\nGetAllPermutations(%s)\n", str.c_str());
	if (str.length() == 1)
	{
		vector<string> perms;
		printf("Adding: %s\n", str.c_str());
		perms.push_back(str);
		return perms;
	}

	vector<string> subPerms = GetAllPermutations(str.substr(1));
	printf("Back from GetAllPermutations(%s)\n", str.substr(1).c_str());

	// insert the first char into all possible positions in all 
	// permutations of the substring
	vector<string> allPerms;
	for (int i = 0; i < subPerms.size(); i++)
	{
		string permi = subPerms[i];
		for (int j = 0; j <= permi.length(); j++)
		{
			string newPerm = (j > 0? permi.substr(0, j) : "") + 
				str[0] + (j < permi.length()? permi.substr(j) : "");
			printf("Adding: %s\n", newPerm.c_str());
			allPerms.push_back(newPerm);
		}
	}

	return allPerms;
}

void PrintAllValidAnagrams(string& str, set<string> dict)
{
	vector<string> perms = GetAllPermutations(str);
	for (int i = 0; i < perms.size(); i++)
	{
		if (dict.find(perms[i]) != dict.end())
		{
			// permutation which is a valid word
			printf("%s ", perms[i].c_str());
		}
	}
}

string ReplaceAllSpacesWithPct20(const string& str)
{
	// first count the number of spaces in the string
	int len = str.length();
	int numSpaces = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			numSpaces++;
		}
	}

	string retVal;
	retVal.resize(len + numSpaces * 2);  // 3 characters per string
	for (int i = 0, j = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			//printf("Replacing space with %%20\n");
			retVal[j++] = '%';
			retVal[j++] = '2';
			retVal[j++] = '0';
		}
		else
		{
			//printf("Copying %c\n", str[i]);
			retVal[j++] = str[i];
		}
	}

	return retVal;
}

int main()
{
	printf("Running string\n");
	/* AV:
	char *strings[] = { (char*)"test", (char*)"string", (char*)"hack", (char*)"pro", (char*)"program", (char*)"C++" };
	for (int i = 0; i < sizeof(strings)/sizeof(strings[0]); i++)
	{
		printf("Reverse(%s) = ", strings[i]);
		printf("%s\n", Reverse(strings[i]));
	}
	*/

	//ReverseWords((char *)"this is a test sentence");
	//test();

	/* AV:
	std::vector<std::string> w1;
	w1.push_back("abhi");
	w1.push_back("sejal");
	std::vector<std::string> w2;
	w2.push_back("aryaa");
	w2.push_back("aayati");

	std::vector<std::string> wMerged = merge(w1, w2);
	std::for_each(wMerged.begin(), wMerged.end(), PrintElt);
	*/

	//char *str = (char *)"abhi";
	//ReverseStr(str);

	/* AV:
	std::string str("Abbhijeett");
	RemoveDuplicateChars(str);
	printf("After removing duplicate chars, str=%s", str.c_str());
	*/

	/* AV:
	std::string str("abc");
	// AV: std::vector<std::string> vec = GetPermutations(str);
	std::vector<std::string> vec = GetAllPermutations(str);
	for (int i = 0; i < vec.size(); i++)
	{
		printf("%s\n", vec[i].c_str());
	}
	*/

	printf("Enter a string in which to replace spaces with %%20:\n");
	char inputStr[256];
	fgets(inputStr, 256, stdin);
	printf("Replacement string = %s\n", ReplaceAllSpacesWithPct20(string(inputStr)).c_str());

	return 0;
}