// from https://community.topcoder.com/stat?c=problem_statement&pm=12794

function hasAllSameColor(str) {
	if (str.length < 1) return true;

	var firstChar = str[0];
	for (var i = 1; i < str.length; i++) {
		if (str[i] != firstChar) {
			return false;
		}
	}

	return true;
}

function removeBall(str, shouldRemoveFrontBall) {
	if (shouldRemoveFrontBall) {
		return str.substring(1);
	} else {
		return str.substring(0, str.length-1);
	}
}

function generateCombination(str, numTurns, minNumTurns) {
	if (hasAllSameColor(str)) {
		minNumTurns = Math.min(numTurns, minNumTurns);
		return minNumTurns;
	}

	if (str.length > 1) {
		var frontRemovedString = removeBall(str, true);
		minNumTurns = Math.min(minNumTurns, generateCombination(frontRemovedString, numTurns+1, minNumTurns));

		var backRemovedString = removeBall(str, false);
		minNumTurns = Math.min(minNumTurns, generateCombination(backRemovedString, numTurns+1, minNumTurns));
	}
	return minNumTurns;
}

function smallestNumberOfTurns(str) {
	var minNumTurns = 100000;
	minNumTurns = generateCombination(str, 0, minNumTurns);
	console.log("Smallest number of turns for string " + str + " = " + minNumTurns);
	return minNumTurns;
}

function assert(val, checkVal) {
	if (val === checkVal) {
		console.log("Assertion passed: " + val + " = " + checkVal);
	} else {
		console.log("Assertion failed: " + val + " != " + checkVal);		
	}
}

assert(smallestNumberOfTurns("RRR"), 0);
assert(smallestNumberOfTurns("RGGGGB"), 2);
assert(smallestNumberOfTurns("RGBRGB"), 5);