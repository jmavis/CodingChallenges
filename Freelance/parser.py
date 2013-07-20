# parser.py
# Will go through a given directory and will privatize any entries that it finds then save over the file
# usage python parser.py
# Will ask for a directory to perform on or will perform on the current directory with a return

import os
import fnmatch

def FindStartOFTitle(memory):
    #print ("FindStartOFTitle(" + str(entry) +")")
    countOfSeperators = 0
    charPlace = 0
    for char in memory:
        charPlace += 1
        #print (str(char))
        if (char == "|"):
            countOfSeperators += 1
            if (countOfSeperators == 11):
                return charPlace

def IsPrivate(memory):
    if ("PRIVATE-TITLE" in memory):
        return (True)
    return (False)

def MakePrivate(memory, startOfTitle):
    #print ("Making private from " + str(memory[startOfTitle:]))
    memory = memory.replace(memory[startOfTitle:], 'PRIVATE-TITLE|PRIVATE-TEXT')
    #print ('Now it is ' + memory)
    return (memory)

def PrivatizeMemory(memory):
    #print ("Privatizing " + str(memory[0:20]))
    startOfTitle = int(FindStartOFTitle(memory))
    return (MakePrivate(memory, startOfTitle))

# if any of the memories has a private title make them all private
def PrivatizeEntry(entry):
    if (any ('PRIVATE-TITLE' in memory for memory in entry)):
        #print ('there was a private memory')
        newEntry = []
        for memory in entry:
            if (not IsPrivate(memory)):
                newEntry.append(PrivatizeMemory(memory))
            else:
                newEntry.append(memory)
        return (newEntry)
    else:
        return (entry)
        

def PrivatizeEntries(entries):
    newEntries = []
    for entry in entries:
        newEntries.append(PrivatizeEntry(entry))
    return (newEntries)

# Reads in the file a returns a list of entries each of which is a list of memories
def FindEntries(file):
    currentEntry = [] # The entry with any reflection or test
    firstLine = False
    entries = []
    for line in file.readlines():
        line = line.rstrip() #remove endline
        #print (str(line))
        if (line.strip()):
            if (firstLine == False):
                if ('Type|ID|ParentID|' in line):
                    firstLine = True
                    continue
                else:
                    return (None)
            else:
                #print ('currentEntry = ' + str(currentEntry))
                currentEntry.append(str(line))  
        elif (firstLine == False and not 'Type|ID|ParentID|' in line):
            return (None)
        else:
            #print('Adding ' + str(currentEntry))
            entries.append(currentEntry)
            currentEntry = []    
    entries.append(currentEntry)
    return (entries)

def WriteEntries(entries, file):
     file.write('Type|ID|ParentID|Date-Time Created|Date Created|Time Created|Happiness|Acted On|Remember|Unique|ourType|Title|Text\n')
     for entry in entries:
          for memory in entry:
               file.write(memory + "\n")
          file.write("\n")

def SaveFile(entries, fileName):
     try:
          # This will create a new file or **overwrite an existing file**.
          f = open(fileName, "w")
          try:
               WriteEntries(entries, f) # Write a string to a file
               #f.writelines(entries) # Write a sequence of strings to a file
          finally:
               f.close()
     except IOError:
          pass

def CovnertInDirectory(directory):
     for (dir, dirs, files) in os.walk(directory):
          print ('Looking in : ' + dir)
          for file in files:
               if fnmatch.fnmatch(file, '*.txt'):
                    print (' Converting: ' + file)
                    L = open(os.path.join(dir, file), "r")#.read()
                    entries = FindEntries(L)
                    if (entries == None):
                        print ('  Was not a study file')
                        continue
                    entries = PrivatizeEntries(entries)
                    SaveFile(entries, os.path.join(dir, file))
                    L.close()
     
directory = raw_input('Enter directory to search and convert (or nothing for current directory): ')
if (len(directory) == 0):
    directory = '.'

if (not os.path.isdir(directory)):
     print ('Error ' + directory + ' was not valid')
else:
     CovnertInDirectory(directory)
print ('Done')
