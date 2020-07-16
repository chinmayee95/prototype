#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
typedef std::string String;
typedef std::vector<String> CSVRow;
typedef CSVRow::const_iterator CSVRowCI;
typedef std::vector<CSVRow> CSVDatabase;
typedef CSVDatabase::const_iterator CSVDatabaseCI;
void readCSV(std::istream &input, CSVDatabase &db);
void display(const CSVRow&);
void display(const CSVDatabase&);
int main(){
  std::fstream file("tasks.csv", std::ios::in);
  if(!file.is_open()){
    std::cout << "File not found!\n";
    return 1;
  }
  CSVDatabase db;
  readCSV(file, db);
//   display(db);
//   storeCSV(db);
}
void readCSV(std::istream &input, CSVDatabase &db){
  String csvLine;
  std::ofstream file;
  file.open ("tasks_strings.txt");
  // read every line from the stream
  while( std::getline(input, csvLine) ){
    std::istringstream csvStream(csvLine);
    CSVRow csvRow;
    String csvCol;
    // read every element from the line that is seperated by commas
    // and put it into the vector or strings
    int cntr=1;
    while( std::getline(csvStream, csvCol, ';'))
    //  && (cntr==9) )
      {
          if(!(csvCol.empty())&(cntr==9|cntr==10|cntr==11))
            {csvRow.push_back(csvCol);
            std::cout<<"COL:"<<cntr<<" Data:"<<csvCol<<std::endl;
            file <<csvCol<<"\n";}
        cntr++;}
    db.push_back(csvRow);
  }
  
//   file << "Please writr this text to a file.\n this text is written using C++\n";
  file.close();
}
// void storeCSV(CSVDatabase &db){
//     if(!db.size())
//     return;
//     CSVDatabaseCI i=db.begin();
    
//     std::vector<std::string> tasks;
//     int cntr = 1;
//     for(; i != db.end(); ++i){
//         CSVRowCI j=i->begin();
//         for(;j != i->end();++j){
//             if(j==i->begin()+8){
//                 tasks.push_back(*i);
//                 std::cout<<*i<<std::endl;
//             }
//         }
//     }

// }
void display(const CSVRow& row){
  if(!row.size())
    return;
  CSVRowCI i=row.begin();
  std::cout<<*(i++);
  for(;i != row.end();++i)
    std::cout<<','<<*i;
}
void display(const CSVDatabase& db){
  if(!db.size())
    return;
  CSVDatabaseCI i=db.begin();
  for(; i != db.end(); ++i){
    display(*i);
    std::cout<<std::endl;
  }
}