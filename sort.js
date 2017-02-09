function quickSort(arr, startIndex, endIndex) {
	if (startIndex >= endIndex) {
		// nothing to sort
		return;
	}

	var pivotIndex = endIndex;
	for (var i = startIndex; i < pivotIndex; i++) {
		if (arr[i] > arr[pivotIndex]) {
			var tmp = arr[i];
			arr[i] = arr[pivotIndex];
			arr[pivotIndex] = tmp;
		}
	}

	// now the highest element is in the pivot position; recursively sort the rest of the array
	quickSort(arr, startIndex, pivotIndex - 1);
}

var arr = Array(3, 5, 1, 4, 2, -1, 2003, -34567, 2.45);
quickSort(arr, 0, arr.length - 1);

console.log(arr);

function findElementInSortedArray(arr, val) {
	// find dimensions of array
	var rows = arr.length;
	var cols = arr[0].length;

	// find the right row
	var rowFound = -1;
	var rowL = 0;
	var rowH = rows-1;
	while (rowFound < 0) {
		if (rowL > rowH) {
			break;
		}

		if (rowL == rowH) {
			rowFound = rowL;
			break;
		}

		var rowM = (rowL + rowH)/2;
		if (arr[rowM][0] <= val && arr[rowM][cols-1] >= val) {
			// it is in the middle row
			rowFound = rowM;
			break;
		}

		if (arr[rowM][0] > val) {
			// found to the left of this
			rowH = rowM - 1;
		} else if (arr[rowM][cols-1] < val) {
			// found to the right of this
			rowL = rowM + 1;
		}
	}

	if (rowFound < 0) {
		console.log("Error! Could not find row");
		return;
	}

	console.log("rowFound="+rowFound);

	// perform binary search on this column
	var colFound = -1;
	var colL = 0;
	var colH = cols-1;
	while (colFound < 0) {
		console.log("cols="+colL+","+colH);
		if (colL > colH) {
			break;
		}

		if (colL == colH) {
			if (arr[rowFound][colL] == val) {
				colFound = colL;
				break;
			}

			break;
		}

		var colM = (colL + colH) / 2;
		if (arr[rowFound][colM] == val) {
			colFound = colM;
			break;
		}
		else if (arr[rowFound][colM] > val) {
			// to the left
			colH = colM - 1;
		} else if (arr[rowFound][colM] < val) {
			// to the right
			colL = colM + 1;
		}
	}

	if (colFound > 0) {
		console.log("Found at index " + rowFound + "," + colFound);
	} else {
		console.log("Could not find value");
	}
}

// [ 1 3 5
//   2 4 6
//   3 5 7 ]
findElementInSortedArray(Array(Array(1, 3, 5), Array(2, 4, 6), Array(3, 5, 7)), 5);
