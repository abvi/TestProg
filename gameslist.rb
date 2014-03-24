f = File.new("inputgames.txt")
while line = f.gets
	# Sample line is like:
	# [ "GP11_MATHS_CONVERTTOMULT_CC", "Identify Multiply", "subtractionsimpleicon" ],
	matches = /\[\s*\"(.*)\",\s*\"(.*)\",\s\"(.*)\"\s*\]/.match(line)

	# matches[2] contains the name of the game
	if (matches)
		puts matches[2]
	end
end
f.close
