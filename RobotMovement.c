// Question 8.2 in Cracking The Coding Interview
// Imagine a robot sitting on the upper left hand corner of an NxN grid 
// The robot can only move in two directions: right and down 
// How many possible paths are there for the robot?

#include <utility>
#include <vector>

#include <cstdio>

using namespace std;

typedef pair<int, int> Point;
typedef vector<Point> Path;
typedef Path::iterator PathIt;

vector<Path> validPaths;

// print a path
void PrintPath(Path& path)
{
	for (PathIt it = path.begin(); it != path.end(); it++)
	{
		Point pt = *it;
		printf("(%d, %d) ", pt.first, pt.second);
	}
}

// check if the given paths match
bool DoPathsMatch(Path& path1, Path& path2)
{
	if (path1.size() != path2.size())
	{
		return false;
	}

	for (PathIt it1 = path1.begin(), it2 = path2.begin(); it1 != path1.end() && it2 != path2.end(); it1++, it2++)
	{
		Point pt1 = *it1;
		Point pt2 = *it2;
		if (pt1.first != pt2.first || pt1.second != pt2.second)
		{
			return false;
		}
	}
	return true;
}

// check if the given path occurs in the list of valid paths
bool IsPathAlreadyFound(Path& path)
{
	vector<Path>::iterator validPathsIt = validPaths.begin();
	for (; validPathsIt != validPaths.end(); validPathsIt++)
	{
		Path currPath = *validPathsIt;
		if (DoPathsMatch(currPath, path))
		{
			return true;
		}
	}

	return false;
}

void GetValidPathsFrom(const Point& startPt, Path pathSoFar, int numRows, int numCols)
{
	// AV: printf("Called with startPt = %d %d\n", startPt.first, startPt.second);

	pathSoFar.push_back(startPt);
	if (startPt.first == numRows - 1 && startPt.second == numCols - 1)
	{
		// we have reached the bottom right corner, so this is a valid path
		if (!IsPathAlreadyFound(pathSoFar))
		{
			validPaths.push_back(pathSoFar);
			printf("Valid path found: ");
			PrintPath(pathSoFar);
			printf("\n");
		}
		else
		{
			printf("Found repeated path: ");
			PrintPath(pathSoFar);
			printf("\n");
		}
	}
	else
	{
		if (startPt.first < numCols - 1)
		{
			// try a right move
			Point rightNeighbor(startPt.first + 1, startPt.second);
			GetValidPathsFrom(rightNeighbor, pathSoFar, numRows, numCols);
		}

		if (startPt.second < numRows - 1)
		{
			// try a down move
			Point bottomNeighbor(startPt.first, startPt.second + 1);
			GetValidPathsFrom(bottomNeighbor, pathSoFar, numRows, numCols);
		}
	}
}

void GetAllValidPaths(int r, int c)
{
	Path p;
	Point startPt(0, 0);
	GetValidPathsFrom(startPt, p, r, c);
}

int main()
{
	GetAllValidPaths(4, 4);
}