#include <string>
#include <map>
#include <fstream>

using namespace std;

struct TeamInfo
{
	int totalMargin;
	int numGames;
	std::vector<string> teamsBetterThan;
};

typedef map<string, TeamInfo> teamMap;

bool IsBetterThan(string& teamA, string& teamB, teamMap& teamList)
{
	return (teamList.com)
}

int main()
{
	teamMap teamList;
	teamMap::iterator mapIt;

	ifstream infile;
    infile.open ("games.txt");

    // read the file line by line
	string str;
	while (getline(infile, str))
	{
		// A M B N
		printf("%s\n", str.c_str());
		char *teamA;
		char *teamB;
		int scoreA, scoreB;
		sscanf(str.c_str(), "%s %d %s %d", teamA, &scoreA, teamB, &scoreB);
		teamList[string(teamA)].totalMargin += scoreA-scoreB;
		teamList[string(teamA)].numGames++;
		teamList[string(teamA)].teamsBetterThan.push_back(teamB);
	}

	string teamName = "";
	float maxAvgMargin = -1;
	for (mapIt it = teamList.begin(); it != teamList.end(); it++)
	{
		float avgMargin = it->second.totalMargin / it->second.numGames;
		if (avgMargin > maxAvgMargin)
		{
			maxAvgMargin = avgMargin;
			teamName = it->first;
		}
	}

	printf("Max margin = Team %s, avg margin %.3f\n", teamName.c_str(), maxAvgMargin);

	// all teams that dominate


	return 0;
}