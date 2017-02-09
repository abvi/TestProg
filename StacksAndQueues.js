var Stack = function () { 
	this.items = Array();
};

Stack.prototype.push = function(item) {
	this.items.push(item);
};

Stack.prototype.pop = function() {
	return this.items.pop();
}

Stack.prototype.peek = function() {
	return this.items[this.items.length-1];
}

Stack.prototype.isEmpty = function() {
	return this.items.length == 0;
}

Stack.prototype.size = function() {
	return this.items.length;
}

var Item = function(size) { this.size = size; }

//////////////

var stacks = Array(new Stack(), new Stack(), new Stack());

function initialize() {
	var items = Array(new Item(3), new Item(2), new Item(1));
	for (var i = 0; i < items.length; i++) {
		stacks[0].push(items[i]);
	}	
}

function moveItem() {
	for (var i = 0; i < stacks.length; i++) {
		// see if the top item in this stack can be moved anywhere else
		for (var j = stacks.length - 1; j >= 0; j--) {
			if (i === j) continue;
			if (stacks[i].isEmpty()) continue;

			if (stacks[j].isEmpty() || stacks[i].peek().size < stacks[j].peek().size) {
				console.log("Moving item of size "+stacks[i].peek().size+" to disk "+j);
				stacks[j].push(stacks[i].pop());
			}
		}
	}
}

initialize();
while (stacks[2].size() != 3) {
	moveItem();
}
console.log("Last disk sorted!");