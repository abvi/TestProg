#include <string>
#include <cstdio>

using namespace std;

/*
bool matchPattern(string& str, string& pattern)
{
	int strPos = 0;
	int patternPos = 0;
	int lastMatchedPos = 0;
	while (strPos < str.length())
	{
		string patternToken = GetNextToken(pattern, patternPos);
		while (strPos < str.length() && DoesMatchToken(str[strPos], patternToken))
		{
			lastMatchedPos = strPos;
			strPos++;
		}
	}
}
*/

string GetNextToken(string& pattern)
{
	if (pattern.length() == 0) return string("");

	string token;
	token.push_back(pattern[0]);
	if (pattern[1] == '*')
	{
		token.push_back('*');
	}
	return token;
}

bool MatchToken(char ch, string& token)
{
	if (token[0] == '.') return true;
	return (ch == token[0]);
}

bool IsRepeatingToken(string token)
{
	//printf("IsRepeatingToken(%s)\n", token.c_str());
	//printf("token length=%d, token[1]=%c\n", token.length(), token[1]);
	return (token.length() > 1 && token[1] == '*');
}

bool matchPattern(string str, string pattern)
{
	printf("matchPattern(%s, %s)\n", str.c_str(), pattern.c_str());

	if (str.length() == 0 && pattern.length() == 0)
	{
		printf("Returning TRUE\n");
		return true;
	}

	string patternToken = GetNextToken(pattern);
	//printf("token = %s\n", patternToken.c_str());
	if (MatchToken(str[0], patternToken))
	{
		if (IsRepeatingToken(patternToken))
		{
			return matchPattern(str.substr(1), pattern) ||
				   matchPattern(str.substr(1), pattern.substr(patternToken.length()));
		}
		else
		{
			// jump over the token
			return matchPattern(str.substr(1), pattern.substr(patternToken.length()));
		}
	}
	else if (IsRepeatingToken(patternToken))
	{
		// try skipping over this token
		return matchPattern(str, pattern.substr(patternToken.length()));
	}
	else
	{
		printf("Returning FALSE\n");
		return false;
	}
}

int main()
{
	string str("aaac");
	string pattern("a*b*ac");

	printf("DoesMatch(%s, %s) = %s", 
		str.c_str(), pattern.c_str(), matchPattern(str, pattern)? "true":"false");
	return 0;
}