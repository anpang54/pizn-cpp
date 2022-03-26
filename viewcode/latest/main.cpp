// Imports
#include <iostream>
#include <vector>
#include <locale>
#include <string>
using namespace std;

// Global variables
const string nl = "\n"; // Newline
const string tdent = "    "; // Two indent
int doing = 0;
int doLine = 1;

int i = 0;
string builder = "";
string checker = "";
vector<string> olr; // One line ram
vector<string> mlr; // Many line ram

vector<string> errorList;
int errorCount = 0;
vector<string> logs;

vector<string> params;

// Really general functions
void printStr(string message) {
  cout << message;
}

void log(string message) {
  logs.push_back(message);
  cout << "Something logged:\n" << tdent << message;
}

void error(string message) {
  errorList.push_back(string(string("Line: " + doLine) + ", Message: ") + message);
  errorCount++;
  cout << "Error at line " << doLine << ":" << nl << tdent << message;
}

auto param(int index) {
  return params[index];
}

string toLower(string s) {        
  for(char &c: s) {
    c = tolower(c);
  }
  return s;
}

string toUpper(string s) {
  for(char &c: s) {
    c = toupper(c);
  }
  return s;
}

string typeify(string todo) {
  // This is supposed to remove quotes if its strings
  return todo; // Temporary
}

void printList(vector<string> const &a) {
  cout << "Elements: " << nl;
  for(int i = 0; i < a.size(); i++) {
     cout << a.at(i) << nl;
  }
}

vector<string> split(string s,string delimiter) {
  vector<string> got;
  size_t pos = 0;
  string token;
  while ((pos = s.find(delimiter)) != string::npos) {
    token = s.substr(0, pos);
    got.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  token = s.substr(0, pos);
  got.push_back(token);
  s.erase(0, pos + delimiter.length());
  return got;
}

vector<string> stSplit(string s,string delimiter) {
  // split() but stuff in strings are ignored
  return split(s,delimiter); // Temporary
}

vector<vector<string>> splitFunc(string funcAsString) {
  vector<string> ct = split(funcAsString,"(");
  vector<string> gtArgs = split(toLower(ct[0]),".");
  vector<string> gtParams = stSplit(ct[1].substr(0,ct[1].size() - 1),",");
  vector<vector<string>> gtFinal = {gtArgs,gtParams};
  return gtFinal;
}

int askInt(string prompt) {
  int answer;
  printStr(prompt);
  // getline(cin, answer); broken
  return answer;
}

string askStr(string prompt) {
  string answer;
  printStr(prompt);
  // getline(cin, answer); broken
  return answer;
}

// Run one line of the code
void runOneLine(string lineAsString) {
  vector<vector<string>> ct = splitFunc(lineAsString);
  string module = ct[0][0];
  string function = ct[0][1];
  params = ct[1]; // Already defined in global form
  if (module == "main") {
    if (function == "print") {
      printStr(typeify(param(0)));
    } else {
      error("Module \"" + module + "\" doesn't have function \"" + function + "\".");
    }
  } else {
    error("Unknown module \"" + module + "\".");
  }
}

// Run multiple lines
void runPiznCode(const vector<string> code) {
  for(string i: code) {
    runOneLine(i);
  } 
}

// Int main
int main() {

  vector<string> codeToRun = {"main.print(Hello, World!)"};
  
  printStr("<//  Pizn Compiler  //>\n\n...\n\n");
  runPiznCode(codeToRun);
  printStr("\n\n...\n\nProcess finished.");
  return 0;
}
