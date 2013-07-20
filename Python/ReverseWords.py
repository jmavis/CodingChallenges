def ReverseWords(s):
    splitAr = s.split()
    splitAr.reverse()
    return(' '.join(splitAr))

print ("'" + ReverseWords("    This is     only a test      ") + "'")
