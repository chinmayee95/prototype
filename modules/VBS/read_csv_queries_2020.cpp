#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <stdio.h>

using namespace std;
int main ()
{
// Read the file ----------
    // string path = "/Users/chinmayees/VBS/database/csvexports/vbs2020/tasks.csv";

    FILE* fp = fopen("tasks.csv", "rb");
    if (fp == NULL) return 0;
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *pData = new char[size + 1];
    fread(pData, sizeof(char), size, fp);
    fclose(fp);
    // Read the file ----------

    //store the contents of the file
    vector<string> tasks;
    
    // while (fscanf(fp, "%g,%g\n", &f1, &f2) == 2)
    // printf("%g\n", f1+f2);

    char* pch;
    pch = strtok (pData, ",");
    int iCpt = 1;
    while (pch != NULL)
    {
        if (iCpt == 9)
        // || iCpt == 4 || iCpt == 5)
        {
        printf ("%s\n", pch);
        tasks.push_back(pch);
        }
        pch = strtok (NULL, ",");
        iCpt++;
    }

    // // Parse the file content ----------
    // char* pch;
    // pch = strtok (pData, "|");
    // while (pch != NULL)
    // {    
    //     printf ("%s\n", pch);
    //     pch = strtok (NULL, "|");
    // }
    // // Parse the file content ----------  
    return 0;
}