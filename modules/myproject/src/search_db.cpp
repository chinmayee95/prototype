#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <cstdio>

using namespace std;
stringstream ss;

string convertToString(char* a, int size) 
{ 
    string s = a; 
    return s; 
} 
void removeStuff(string& str, char character)
{
 size_t pos;
 while( (pos=str.find(character)) != string::npos )
      str.erase(pos, 1);
}

int main(void) {
  char buf[100];     // declare space for the input string
  FILE *fp;          // pointer to the text file
  char fileBuf[256]; // space to keep a line from the file
  int ii, ll;

  printf("give a word to check:\n");
  fgets(buf, 100, stdin);    // fgets prevents you reading in a string longer than buffer
  printf("you entered: %s\n", buf);  // check we read correctly

  // see (for debug) if there are any odd characters:
  printf("In hex, that is ");
  ll = strlen(buf);
  for(ii = 0; ii < ll; ii++) printf("%2X ", buf[ii]);
  printf("\n");

  // probably see a carriage return - depends on OS. Get rid of it!
  // note I could have used the result that ii is strlen(but) but 
  // that makes the code harder to understand
  for(ii = strlen(buf) - 1; ii >=0; ii--) {
    if (isspace(buf[ii])) buf[ii]='\0';
  }

  // open the file:
  if((fp=fopen("/Users/chinmayees/work/prototype/database/synset_dictionary.txt", "r"))==NULL) {
    printf("cannot open file!\n");
    return 0;
  }

  while( fgets(fileBuf, 256, fp) ) {   // read in one line at a time until eof
    printf("line read: %s", fileBuf);  // show we read it correctly
  // find whitespace: we need to keep only the first word.
    ii = 0;
    while(!isspace(fileBuf[ii]) && ii < 255) ii++;
  // now compare input string with first word from input file:
    if (strlen(buf)==ii && strstr(fileBuf, buf) == fileBuf) {
        printf("found a matching line: %s\n", fileBuf);
        int size = sizeof(fileBuf) / sizeof(char);
        string temp = convertToString(fileBuf, size);
        
        int pos1 = temp.find("[");
        int pos2 = temp.find("]");
        string output = temp.substr(pos1+1,pos2);
        removeStuff(output, ']');
        cout<<"out:"<<output<<endl;
        removeStuff(output, ',');
        cout<<"the new string "<<output<<endl;
        vector<string> result;
        stringstream s_stream(output); //create string stream from the string
        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ' '); //get first string delimited by comma
            result.push_back(substr);
        }
        for(int i = 0; i<result.size(); i++) {    //print all splitted strings
            cout << result.at(i) << endl;
        }
        /*
        int j =0;
        j = ii;
        while(j<strlen(fileBuf) && fileBuf[j] != '['){ 
            j+=1;
        }
        
        char tempBuf[100];

        int k = 0;
        while(j<strlen(fileBuf) && fileBuf[j] != ']'){
                tempBuf[k] = fileBuf[j];
                j+=1;
        }
        int size = sizeof(tempBuf) / sizeof(char);
        string temp = convertToString(fileBuf, size);
        cont(temp);
        */
        /*
        cout<<"temp"<<temp<<endl;
        string out;
        
        char outs[64];
        // int n = sscanf(tempBuf, "%*[^[][%*[^]]][%[^]]]", outs);
        // printf("content: %s\n", outs);
        std::string str(temp);

        // std::string output(temp.find_last_of('['), temp.find_last_of(']'));
        
        // out = output.c_str();
        // cout<<"out"<<output<<endl;
        vector<string> result; 
        cout<<"Results"<<temp<<endl;
        boost::split(result, output, boost::is_any_of(",")); 
        cout<<"..."<<endl;
        for (int i = 0; i < result.size(); i++) 
            cout << result[i] << endl; */
   
        break;
    }
  }
  // when you get here, fileBuf will contain the line you are interested in
  // the second and third word of the line are what you are really after.
}


// #include<fstream>
// #include<iostream>
// #include<cstdlib>

// using namespace std;

// int main()
// {
// 	ifstream fin;
// 	fin.open("/Users/chinmayees/work/prototype/database/synset_dictionary.txt");
// 	if(fin.fail())
// 	{
// 		cout << "Input file opening failed.\n";
// 		exit(1);
// 	}
// 	string search;
// 	cout << "Please enter the query: ";
// 	cin  >> search;
// 	bool isFound=0;
// 	while(!fin.eof())
// 	{
// 		string temp = "";
// 		getline(fin,temp);
// 		for(int i=0;i<search.size();i++)
// 		{
// 			if(temp[i]==search[i])
// 				isFound = 1;
// 			else
// 			{
// 				isFound =0;
// 				break;
// 			}
// 		}

// 		if(isFound)
// 		{
// 			cout << "Password is: ";
// 			for(int i = search.size()+1;i<temp.size();i++)
// 				cout << temp[i];

// 			break;
// 		}

// 	}

// 	if(fin.eof()&&(!isFound))
// 	{
// 		cout << "Name not found!\n";
// 	}

// 	fin.close();

// 	return 0;
// }