vector<string> permute(string& str) {
	vector<string> permutations;
	if (str.length == 1) {
		permutations.push_back(str);
	}
	else {
		// take the first letter, and add it into all permutations of all remaining letters
		char firstChar = str[0];
		vector<string> restPermutations = permute(str.substring(1));
		foreach (restPermutations as perm) {
			// insert firstChar into every position
			for (int i = 0; i < perm.length(); i++) {
				string newPerm = perm.substring(0, i) + firstChar + perm.substring(i);
				permutations.push_back(newPerm);
			}
		}
	}
	return permutations;
}

void printPermutations(string str) {
	vector<string> permutations = permute(str);
	foreach (permutations as perm) {
		print(perm);
	}
}

printPermutations("abc");

struct Color { int r, g, b; };
struct Point { int x; int y; };
set<Point> visitedPoints;

void floodFill(Point currPt, Color [][] screen, Color newColor) {
	// if the current cell is of the new color, we have reached a border, so stop
	if (screen[currPt.x][currPt.y] == newColor && !visitedPoints.contains(currPt) {
		return;
	}

	// otherwise, color this cell with this color
	screen[currPt.x][currPt.y] = newColor;

	// add this cell to the list of visited cells
	visitedPoints.add(currPt);

	// floodfill all surrounding cells
	floodFill(Point(currPt.x+1, currPt.y), screen, newColor);
	...
}