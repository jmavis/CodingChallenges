import sys

def is_left_paren(char):
	return (char == "(" or char == "[" or char == "{");

def is_right_paren(char):
	return (char == ")" or char == "]" or char == "}");

def parens_match(leftParen, rightParen):
	return ((leftParen == "(" and rightParen == ")") or
			(leftParen == "[" and rightParen == "]") or
			(leftParen == "{" and rightParen == "}"))

def has_valid_parens(string):
	""" Returns true if the string contains a list of valid matching parenthesis """
	parenList = [];
	for char in string:
		if is_left_paren(char):
			parenList.append(char);
		elif is_right_paren(char):
			if len(parenList) == 0 or not parens_match(parenList.pop(), char):
				return False;
	return len(parenList) == 0;

def parse_line(line):
    """ Reads the line and will call has_valid_parens
        with the appropriate arguments"""
    print has_valid_parens(line);
    
def read_file(file):
    """ Reads in and parses the lines of the given file"""
    for line in file.readlines():
        line = line.rstrip() #remove endline
        parse_line(line)

#---------------------------------------------------------
# Running Test Cases
#---------------------------------------------------------
test_cases = open(sys.argv[1], 'r')
read_file(test_cases)
test_cases.close()