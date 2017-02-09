function GotoFloor(int floor) { ... }

function OpenDoor() { ... }

bool goingUp = true;
int currentFloor = 1;   // elevator starts at first floor

vector<int> upList;  // sorted
vector<int> downList;  // sorted

typedef vector<int>::iterator FloorIt;

function InsertIntoFloorListSorted(vector<int>& floorList, int newFloor)
{
	...
}

while (1)
{
	if (floorNum = KeyPressed())
	{
		if (floorNum > currentFloor)
		{
			InsertIntoListSorted(upList, floorNum);
		}
		else
		{
			InsertIntoListSorted(downList, floorNum);
		}
	}

	if (goingUp)
	{
		if (!upList.empty())
		{
			int nextFloor = upList.pop_back();
			GotoFloor(nextFloor);
			currentFloor = nextFloor;
		}
		else
		{
			goingUp = false;
		}
	}
	else   // going down
	{
		if (!downList.empty())
		{
			int nextFloor = downList.pop_back();
			GotoFloor(nextFloor);
			currentFloor = nextFloor;
		}
		else
		{
			goingUp = true;
		}
	}
}
