// Finds the lowest unique number in a list of numbers.
// Author Jared Mavis - jmavis
var fs  = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== "") {
    	var numbers = line.match(/\w+/g);
        var counts = getCountOfNums(numbers);
        var lowestUnique = findLowestUnique(counts);
        printLowestPos(lowestUnique, numbers);
    }	
});

function  printLowestPos(lowestUnique, numbers) {
	if (lowestUnique === 0) {
		console.log(0);
	} else {
		for (var i = 0, length = numbers.length; i < length; i++) {
			if (numbers[i] === lowestUnique) {
				console.log(i+1);
			}
		}
	}
}

function getCountOfNums(numArray) {
	var counts = {};
	for (var i = 0, length = numArray.length; i < length; i++) {
		if (counts[numArray[i]]) {
			counts[numArray[i]]++;
		} else {
			counts[numArray[i]] = 1;
		}
	}
	return counts;
}

function findLowestUnique(counts) {
	var numbers = Object.keys(counts);
	for (var i = 0, length = numbers.length; i < length; i++) {
		if (counts[numbers[i]] === 1) {
			return numbers[i];
		}
	}
	return 0; // if no unique then return 0 flag
}