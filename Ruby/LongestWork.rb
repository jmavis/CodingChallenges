# Author: Jared Mavis
# Prints the longest word in each line of the file
File.open(ARGV[0]).each_line do |line|
	currentWord = ""
	longestWord = ""
	line.each_char do |char|
		if char == ' ' || char == "\n"
			if currentWord.length() > longestWord.length()
				longestWord = currentWord
			end
			currentWord = ""
		else
			currentWord += char
		end
	end
	if longestWord != ""
		print longestWord + "\n"
	end
end
