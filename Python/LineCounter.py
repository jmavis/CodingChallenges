import os
import fnmatch

def CountLinesInFile(file):
     count = 0
     for line in file.readlines():
          count += 1
     print('Count = ' + str(count))
     return (count)

def CountLines(directory):
     count = 0
     for (dir, dirs, files) in os.walk(directory):
          print ('Looking in : ' + dir)
          for file in files:
               if fnmatch.fnmatch(file, '*.js'):
                    L = open(os.path.join(dir, file), "r")
                    count += CountLinesInFile(L)
                    print('Count = ' + str(count))
                    L.close()
directory = raw_input('Enter directory to search and convert (or nothing for current directory): ')
if (len(directory) == 0):
    directory = '.'

if (not os.path.isdir(directory)):
     print ('Error ' + directory + ' was not valid')
else:
     CountLines(directory)
