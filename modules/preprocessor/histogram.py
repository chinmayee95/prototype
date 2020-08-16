import os
import ast
import matplotlib.pyplot as plt
import numpy as np
# def fileRead(fileName):
#     file = open(fileName)
#     len = []
#     files = []
#     for f in file:
#         lenfile = readCont(f)
#         len.append(lenfile)
#         files.append(f)
#     plothist(files,len)
    
def plothist(x,y):
    x = np.asarray(x)
    y = np.asarray(y)
    plt.bar(x,y,align='center') # A bar chart
    plt.xlabel('Bins')
    plt.ylabel('Frequency')
    for i in range(len(y)):
        plt.hlines(y[i],0,x[i]) # Here you are drawing the horizontal lines
    plt.show()
    
def readCont(f):
    contents = []
    for cont in f:
        contents.append(cont)
    return len(contents)

path = "/Users/chinmayees/work/prototype/database/num_id/"
for subdir, dirs, mod_files in os.walk(path):
    for files in mod_files:
        len = []
        filename = []
        if files.endswith(".txt"):
            print("File:",files)
            fileName = os.path.join(path,files)
            # file = open(fileName)
            
            # for f in file:
            #     lenfile = readCont(f)
            len.append(os.path.getsize(fileName))
            filename.append(files)
plothist(filename,len)