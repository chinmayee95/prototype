import os
import ast

def fileRead(fileName):
    f = open(fileName)
    # contents = []
    for cont in f:
        n = len(cont)
        # print(n)
        cont = cont[1:n-1]
        # print(len(cont))
        contents = cont.split (",")
        # print(type(contents))
        # print(type(cont))
        # print(contents[0])
        # print(cont[0])
        for lines in contents:
            lines = lines.replace('"','')
            # print(lines)
            # exit(0)
            lineout = lines.split (":")
            try:
                if lineout[0] and lineout[1]:
                    # print(str(lineout[0]))#id
                    # print(str(lineout[1]))#content
                    namefile = fileName.split("/")
                    namefile = namefile[6]
                    # print("nf",namefile)
                    namefile = namefile.split(".")[0]
                    # print(namefile)
                    out = []
                    out.append(namefile)
                    out.append('_')
                    out.append(lineout[0])
                    out.append(' ')
                    out.append(lineout[1])
                    out.append('\n')
                    raw = open(os.path.join("/Users/chinmayees/work/V3C1-ASR-master/","ASR.txt"), "a+")
                    for item in out:
                        raw.write("%s" % item)
                        # print(item)
                    raw.close() 
            except IndexError:
                pass

path = "/Users/chinmayees/work/V3C1-ASR-master/json/"
for subdir, dirs, mod_files in os.walk(path):
    # print(mod_files[10])
    # for files in mod_files:
    i=0
    for i in range(len(mod_files)):
        
        files = mod_files[i]
        print(files)
        if files.endswith(".json"):
            # print(os.path.join(path,files))
            fileRead(os.path.join(path,files))
            # break
        i+=1