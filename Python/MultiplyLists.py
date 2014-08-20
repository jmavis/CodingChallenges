import sys


def ReadFile(file):
    """ Reads in and parses the lines of the given file."""
    for line in file.readlines():
        line = line.rstrip() #remove endline
        lists =  map(lambda x : filter(None, x.split(' ')), line.split('|'));
        multiples = [];
        for i in range(len(lists[0])): #assuming both are same size
            multiples.append(str(int(lists[0][i]) * int(lists[1][i])))
        print ' '.join(multiples);

#---------------------------------------------------------
# Running Test Cases
#---------------------------------------------------------
test_cases = open(sys.argv[1], 'r')
ReadFile(test_cases)
test_cases.close()