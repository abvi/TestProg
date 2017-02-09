function hasUniqueChars(str) {
	var charSet = new Set();
	for (var i = 0; i < str.length; i++) {
		if (charSet.has(str[i])) {
			return false;
		}
		else {
			charSet.add(str[i]);
		}
	}
	return true;
}

function reverseStr(cStr) {
	cStrArr = cStr.split('');
	for (var i = 0; i < (cStrArr.length - 1)/2; i++) {
		var tmp = cStrArr[i];
		cStrArr[i] = cStrArr[cStrArr.length - i - 2];
		cStrArr[cStrArr.length - i - 2] = tmp;
	}
	return cStrArr.join('');
}

/**
Shift all characters in the string starting from index j+1 left one spot
*/
function shiftLeft(arr, j, arrLen) {
	for (var i = j; i < arrLen-1; i++) {
		arr[i] = arr[i+1];
	}
}

function removeDuplicateChars(str) {
	var arr = str.split('');
	var arrLen = arr.length;
	for (var i = 0; i < arrLen; i++) {
		var ch = arr[i];
		for (var j = i+1; j < arrLen; j++) {
			if (arr[j] == ch) {
				shiftLeft(arr, j, arrLen);
				arrLen--;
			}
		}
	}
	return arr.join('').substring(0, arrLen);
}

function isAnagram(str1, str2) {
	return str1.split('').sort().join('') == str2.split('').sort().join('');
}

// given an mxn array, if an element is zero, set its entire row and column to zero
function setRowAndColumnToZero(arr) {
	var rows = arr.length;
	var cols = arr[0].length;

	var zeroRows = new Set();
	var zeroCols = new Set();
	for (var i = 0; i < rows; i++) {
		for (var j = 0; j < cols; j++) {
			if (arr[i][j] === 0) {
				zeroRows.add(i);
				zeroCols.add(j);
			}
		}
	}

	// now set all entries in the rows and columns to zero
	zeroRows.forEach(function (row, val) {
		for (var j = 0; j < cols; j++) {
			arr[row][j] = 0;
		}
	});

	zeroCols.forEach(function (col, val) {
		for (var j = 0; j < rows; j++) {
			arr[j][col] = 0;
		}
	});

	return arr;
}

function moveChars(arr, startIndex, numChars) {
	var arrLen = arr.length;
	for (var i = arrLen + numChars - 1; i >= startIndex + numChars; i--) {
		arr[i] = arr[i-numChars];
	}
	return arr;
}

function replaceSpaces(str) {
	var arr = str.split('');

	var arrLen = arr.length;
	for (var i = 0; i < arrLen; i++) {
		if (arr[i] == ' ') {
			// move all characters to the right of this character two slots to the right
			arr = moveChars(arr, i+1, 2);

			// replace the space with %20
			arr[i] = '%';
			arr[i+1] = '2';
			arr[i+2] = '0';
			i += 2; // this points to the '0', so that the loop increment makes it point to the right character
			arrLen += 2;
		}
	}

	return arr.join('');
}

console.log(hasUniqueChars("abhi"));
console.log(hasUniqueChars("abhijeet"));

console.log(reverseStr("abhi\0"));

console.log(removeDuplicateChars("aabhii"));

console.log(isAnagram("abhi", "ibha"));
console.log(isAnagram("abhi", "sejal"));

var arr = [[1, 2, 3], [2, 0, 4], [2, 1, 2]];
console.log(arr);
console.log(setRowAndColumnToZero(arr));

console.log(replaceSpaces("This is a test "));