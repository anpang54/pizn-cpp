#include <iostream>
#include <vector>
#include <locale>
using namespace std;

const string nl = "\n"; // Newline
const string tdent = "    "; // Two indent
int doing = 0;
int doLine = 1;

void printStr(string message) {
  cout << message;
}

void error(string message) {
  cout << "Error at line " << doLine << ":" << nl << tdent << message;
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

void runOneLine(string lineAsString) {
  vector<vector<string>> ct = splitFunc(lineAsString);
  string module = ct[0][0];
  string function = ct[0][1];
  vector<string> params = ct[1];
  if (module == "main") {
    if (function == "print") {
      printStr(params[0]);
    } else {
      error("Module \"" + module + "\" doesn't have function \"" + function + "\".");
    }
  } else {
    error("Unknown module \"" + module + "\".");
  }
}

void runPiznCode() {
  runOneLine("mAin.print(Entirely a test)"); // temporary
}

int main() {
  printStr("<//  Pizn Compiler  //>\n\n...\n\n");
  runPiznCode();
  printStr("\n\n...\n\nProcess finished.");
  return 0;
}
