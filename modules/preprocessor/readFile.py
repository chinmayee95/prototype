import os
import ast

def fileRead(fileName):
    f = open(fileName)
    out = readCont(f)
    # print(out)
    raw = open(fileName, "w")
    # raw.write(str(out))
    for item in out:
        raw.write("%s" % item)
        print(item)
    raw.close()
    # print("reading...")
    # f = open(fileName)
    # print(f.readlines())

def readCont(f):
    contents = []
    for cont in f:
        contents.append(cont)

    if len(contents)<=1:
        return contents
    else:
        return rank(contents)

def takeThird(elem):
    return elem[2]

def convert_string_list_to_list(elem):
    return ast.literal_eval(elem)

def rank(contents):
    print("original data")
    contents = list(map(convert_string_list_to_list, contents))
    s = sorted(contents, key=lambda x: x[2],reverse=True)
    print("after sorting")
    print(s)
    return s
    # contents.sort(key=lambda x: x[2],reverse=True)

# def sorting(filename):
#     # filename = ("food.txt")
#     file_handle = open(filename, "r")
#     words = []
#     for line in file_handle:
#         words += line.split()
#     file_handle.close()
#     print sorted(words)

path = "/Users/chinmayees/work/prototype/database/num_id/"
# for subdir, dirs, mod_files in os.walk(path):
    # print(subdir, dirs)
# fileRead(path)
# print("hi",os.walk(path))
for subdir, dirs, mod_files in os.walk(path):
    # print(files[0])
    for files in mod_files:
        if files.endswith(".txt"):
            print("File:",files)
    # print(len(mod_files))
            fileRead(os.path.join(path,files))
            # break

# if __name__ == "__main__":
#     contents = [['00996', '00996_0000418_cnn_inception100.csv', '0.0069492'],['00679', '00679_0001094_cnn_inception100.csv', '0.00111029'],['01834', '01834_0007907_cnn_inception100.csv', '0.00091328'],['01818', '01818_0000782_cnn_inception100.csv', '0.0137386'],['01577', '01577_0002650_cnn_inception100.csv', '0.00170234'],['01863', '01863_0004494_cnn_inception100.csv', '0.000311351'],['01599', '01599_0000652_cnn_inception100.csv', '3.09207e-05'],['02871', '02871_0002467_cnn_inception100.csv', '0.000849985'],['02325', '02325_0005146_cnn_inception100.csv', '0.00109981'],['03612', '03612_0001568_cnn_inception100.csv', '0.0111088'],['03509', '03509_0004854_cnn_inception100.csv', '0.000303689'],['04188', '04188_0000693_cnn_inception100.csv', '0.0053078'],['04382', '04382_0001388_cnn_inception100.csv', '0.0028163'],['04506', '04506_0004790_cnn_inception100.csv', '0.00105647'],['05853', '05853_0002293_cnn_inception100.csv', '0.00924722'],['06501', '06501_0001824_cnn_inception100.csv', '0.00436523']]
#     # print(contents)

#     rank(contents)
