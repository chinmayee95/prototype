#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <sstream>  
#include <cstdio>
#include <vector>
using namespace std;
stringstream ss;
// ofstream myfile;

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

void fileRead(vector<string> files){
    int len = 0;
    string path = "/Users/chinmayees/work/prototype/database/num_id/";
    string str;
    while(len<files.size()){
        ifstream myfile;
        string line;
        cout<<"file:"<<files[len]<<endl;
        files[len].erase(files[len].find_last_not_of(" \n\r\t")+1);
        str = path + string(files[len]+".txt");
        
        cout<<"path:"<<str<<endl;
        myfile.open(str);

        if(!myfile.is_open()) {
            perror("Error open");
            exit(EXIT_FAILURE);
        }
        cout<<"...."<<endl;
        while(getline(myfile, line)) {
        cout << line << endl;
        }
    
        len+=1;
    }
}

// for string delimiter
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


void dbsearch(string s){
    cout <<"The word is:"<<s<<endl;
//   char buf[100];     // declare space for the input string
  FILE *fp;          // pointer to the text file
  char fileBuf[256]; // space to keep a line from the file
  int ii, ll;
  char buf[s.length()];
  int i; 
  for (i = 0; i < sizeof(buf); i++) { 
        buf[i] = s[i]; 
        // cout << p[i]; 
    } 
//   printf("give a word to check:\n");
//   fgets(buf, 100, stdin);    // fgets prevents you reading in a string longer than buffer
//   printf("you entered: %s\n", buf);  // check we read correctly

  // see (for debug) if there are any odd characters:
//   printf("In hex, that is ");
//   ll = strlen(buf);
//   for(ii = 0; ii < ll; ii++) printf("%2X ", buf[ii]);
//   printf("\n");

  // probably see a carriage return - depends on OS. Get rid of it!
  // note I could have used the result that ii is strlen(but) but 
  // that makes the code harder to understand
  for(ii = strlen(buf) - 1; ii >=0; ii--) {
    if (isspace(buf[ii])) buf[ii]='\0';
  }

  // open the file:
  if((fp=fopen("/Users/chinmayees/work/prototype/database/synset_dictionary.txt", "r"))==NULL) {
    printf("cannot open file!\n");
    // return 0;
    exit(0);
  }

  while( fgets(fileBuf, 256, fp) ) {   // read in one line at a time until eof
    // printf("line read: %s", fileBuf);  // show we read it correctly
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
        fileRead(result);
        break;
    }
  }
  // when you get here, fileBuf will contain the line you are interested in
  // the second and third word of the line are what you are really after.
}

int main(void) {
    
    char buf[100];     // declare space for the input string
    printf("give a word to check:\n");
    fgets(buf, 100, stdin);    // fgets prevents you reading in a string longer than buffer
    printf("you entered: %s\n", buf);
    int size = sizeof(buf) / sizeof(char);
    string str = convertToString(buf, size);
        
    // string str = "adsf-+qwret-+nvfkbdsj-+orthdfjgh-+dfjrleih";
    string delimiter = ",";
    vector<string> v = split (str, delimiter);

    // for (auto i : v) 
    for(int i=0; i<v.size();i++)
    {
        cout << v[i] << endl;
        dbsearch(v[i]);
        cout<<"searching.."<<endl;
    }

}
