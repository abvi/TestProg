// from https://www.glassdoor.com/Interview/Given-two-words-and-a-dictionary-print-the-path-from-one-word-to-the-next-changing-one-letter-at-a-time-QTN_1723828.htm

function isInDictionary(word, dict) {
	for (var i = 0; i < dict.length; i++) {
		if (word == dict[i]) {
			return true;
		}
	}
	return false;
}

function changeWordOneLetter(word1, word2, dict) {
	var word1Arr = word1.split('');
	var word2Arr = word2.split('');
	for (var i = 0; i < word1.length; i++) {
		var ch1 = word1Arr[i];
		var ch2 = word2Arr[i];

		if (ch1 !== ch2) {
			word1Arr[i] = ch2;
			if (isInDictionary(word1Arr.join(''), dict)) {
				console.log(word1Arr.join(''));
			} else {
				word1Arr[i] = ch1;
			}			
		}
	}
}

changeWordOneLetter('book', 'door', Array('book', 'dook', 'baek', 'door', 'boor'));