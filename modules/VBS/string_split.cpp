/* strtok example */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <boost/algorithm/string.hpp>
#include "readfile.h"
// #includ <boost/algorithm/string/find_iterator.hpp>
using namespace std;

string removeWord(string str, string word)  
{ 
    // Check if the word is present in string 
    // If found, remove it using removeAll() 
    if (str.find(word) != string::npos) 
    { 
        size_t p = -1; 
  
        // To cover the case 
        // if the word is at the 
        // beginning of the string 
        // or anywhere in the middle 
        string tempWord = word + " "; 
        while ((p = str.find(word)) != string::npos) 
            str.replace(p, tempWord.length(), ""); 
  
        // To cover the edge case 
        // if the word is at the 
        // end of the string 
        tempWord = " " + word; 
        while ((p = str.find(word)) != string::npos) 
            str.replace(p, tempWord.length(), ""); 
    } 
  
    // Return the resultant string 
    return str; 
} 

void faces(string str1){
    std::vector<std::string> filenames = {"nofaces.txt","1face.txt","2faces.txt","3faces.txt","4faces.txt","manyfaces.txt"};

    typedef boost::find_iterator<string::iterator> string_find_iterator;
    int counter = 0;
    std::vector<std::string> humans_1,humans_2;
    humans_1 = {"he","she","girl","boy","him","her","lady","bride","groom","man","woman","worker","helper","farmer","teacher","doctor","lawyer","student","rider"};
    humans_2 = {"them","they","people","bridesmaid","groomsmaid","girls","boys","ladies","men","women","workers","helpers","teachers","doctors","lawyers","students","riders"};
    std::vector<std::string> faces_count;

    for(int j = 0; j < humans_1.size(); j++){
        for(string_find_iterator It = make_find_iterator(str1, first_finder(humans_1[j], boost::is_iequal()));It!=string_find_iterator();++It)
        {
            cout << boost::copy_range<std::string>(*It) << endl;
            
            counter+=1;
            if (counter>4)
                faces_count.push_back(filenames[5]);
                break;
            cout<<"Counter:"<<counter<<endl;
        }
    }
    
    for(int j = 0; j < humans_2.size(); j++){
        for(string_find_iterator It = make_find_iterator(str1, first_finder(humans_2[j], boost::is_iequal()));It!=string_find_iterator();++It)
        {
            cout << boost::copy_range<std::string>(*It) << endl;
            
            counter+=1;
            if (counter>4)
                faces_count.push_back(filenames[5]);
                break;
            cout<<"Counter:"<<counter<<endl;
        }
    }
    if (counter==0)
        faces_count.push_back(filenames[counter]);
    else if (counter==1)
        faces_count.push_back(filenames[counter]);
    else if (counter==2)
        faces_count.push_back(filenames[counter]);
    else if (counter==3)
        faces_count.push_back(filenames[counter]);
    else if (counter==4)
        faces_count.push_back(filenames[counter]);

    std::cout<<"Reading faces files...."<<std::endl;
    std::vector<std::string> frameid = readFile(faces_count[0]);
    
}

void colorfile(string str1){

    std::vector<std::string> filenames = {"BLACKWHITE.txt","BLUE.txt","CYAN.txt","GRAY.txt","GREEN.txt","MAGENTA.txt","ORANGE.txt",
                                            "RED.txt","VIOLET.txt","YELLOW.txt","UNDETERMINED.txt"};

    typedef boost::find_iterator<string::iterator> string_find_iterator;
    int counter = 0;

    std::vector<std::string> colors;
    // std::multimap<int,string> color_map;

    colors = {"blackwhite","blue","cyan","gray","green","magenta","orange","red","violet","yellow","unknown"};
    std::vector<std::string> color_present;
    for(int j = 0; j < colors.size(); j++){
        for(string_find_iterator It = make_find_iterator(str1, first_finder(colors[j], boost::is_iequal()));It!=string_find_iterator();++It)
        {
            cout << boost::copy_range<std::string>(*It) << endl;
            color_present.push_back(filenames[j]);
            // color_map.insert(std::make_pair(j,boost::copy_range<std::string>(*It)));
            counter+=1;
            cout<<"Counter:"<<counter<<endl;
        }
    }

    

    if(counter!=0){
         
        std::vector<std::string> frameid = readFile(color_present[0]);
    }

}


int main ()
{

    char * pch;
    string string1; 
    // = "Geeks the red in forest, and - for Geeks."; 
    cin>>string1;
    boost::to_lower(string1);
    cout<<"Lower case:"<<string1<<endl;
    string word1 = "test"; 

    vector<string> words = {",","-",":",".","a ","an ","the ","it ","of ","to ","for ","in ","is ","this ","there","that ","them ","by ","if ","then ","on ","by ","and "};
    // vector<string> 
    // string reduced_string;
    // strcpy(reduced_string,string1);
    // reduced_string = string1;
    int i = 0;
    while(i<words.size()){
        // reduced_string = removeWord(reduced_string,words[i]);
        boost::erase_all(string1, words[i]);  
        // boost::erase_all(reduced_string,words[i]);
        i++;
    }
    cout<<"Reduced string : "<<string1<<endl;
    colorfile(string1);
    faces(string1);
    string res = removeWord(string1, word1);
    char str_res[res.size() + 1]; 

    strcpy(str_res,res.c_str());

    printf ("Splitting string \"%s\" into tokens:\n",str_res);
    pch = strtok (str_res," ,.-");

    vector<string> string_vector;
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        string_vector.push_back(pch);
        pch = strtok (NULL, " ,.-");
    }
    
    for(int i=0;i<string_vector.size();i++)
        cout<<"PCH:"<<string_vector[i]<<endl;

    

  
/*
    // Test case 1 
    cout << "String: " << string1 << "\nWord: " 
         << word1 << "\nResult String: " 
         << removeWord(string1, word1) << endl; 
    
*/

/*
BLACKWHITE.txt

BLUE.txt

CYAN.txt

GRAY.txt

GREEN.txt

MAGENTA.txt

ORANGE.txt

RED.txt

UNDETERMINED.txt

VIOLET.txt

YELLOW.txt
*/
return 0;

}