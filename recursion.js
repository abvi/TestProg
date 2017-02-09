function generateCombinations(combinationsSoFar, arr, index) {
	//console.log("Generate combinations called with index " + index + " and combinationsSoFar: ");
	//console.log(combinationsSoFar);

	if (index == arr.length) {
		// we have reached the end of the array of numbers and generated one valid combination
		console.log("*** Reached end of array, final valid combination:")
		console.log(combinationsSoFar);
		return;
	}

	// include the next number, or not
	var nextNum = arr[index];

	// combine this number with the last number in the combinations array
	var oldLen = combinationsSoFar.length;
	if (oldLen > 0) {
		var oldLast = combinationsSoFar[oldLen - 1];
		var newLast = oldLast * 10 + nextNum;

		if (newLast < 26) {
			combinationsSoFar[oldLen-1] = newLast;

			// generate combinations for the remainder of the string
			generateCombinations(combinationsSoFar, arr, index+1);

			// remove all the extra combinations generated, which were printed at the end of the recursion
			combinationsSoFar = combinationsSoFar.slice(0, oldLen);

			// replace the previous number at the end of the combinationsSoFar array
			combinationsSoFar[oldLen-1] = oldLast;
		}		
	}

	// add the next number by itself to the array
	combinationsSoFar.push(nextNum);
	generateCombinations(combinationsSoFar, arr, index+1);
}

generateCombinations(Array(), Array(3,2,3,4), 0);