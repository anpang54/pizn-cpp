// Imports
#include <iostream>
#include <vector>
#include <locale>
#include <string>
#include <regex>
using namespace std;

// Global variables
int doing = 0;
int doLine = 1;
int i = 0;

string builder = "";
string checker = "";
string response = "";
vector<string> olr; // One line ram
vector<string> mlr; // Many line ram

vector<string> errorList;
int errorCount = 0;
vector<string> logs;

string module;
string func;
vector<string> args;
vector<string> params;

// Constants
const string logBegin = "/[/<[/ Logged \\]>\\]\\: ";
const string nl = "\n"; // Newline, use instead of endl and/or "\n"
const string tdent = "    "; // Two indent

// Configs
bool enableStrict = false;
bool showLogs = false;
bool showErrors = true;

// Really general functions
void printStr(string message) {
  cout << message << nl;
}

void log(string message) {
  logs.push_back(message);
  if (showLogs) {
    cout << logBegin << message << nl;
  }
}

void error(string message) {
  errorList.push_back(string(string("Line: " + doLine) + ", Message: ") + message);
  errorCount++;
  if (showErrors) {
    cout << "Error at line " << doLine << ":" << nl << tdent << message;
  }
}

void notHave(string more = "") {
  error("Module \"" + module + "\" doesn't have function \"" + func + "\"." + more);
}

void mainOnExit() {
  printStr("\n\n...\n\nProcess finished.");
}

void returns(string returned) {
  printStr("A function returned: " + returned); // temporary
}

string replace(string str,string replaceThis,string replaceWith) {
  string test = str;
  test = regex_replace(test, regex(replaceThis), replaceWith);
  return test;
}

string typeify(string todo) {
  // This is supposed to remove quotes if its strings
  return todo; // Temporary
}

auto param(int index) {
  return typeify(params[index]);
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

string askStr(string prompt) {
  string answer;
  cout << prompt; // Use cout << not printStr
  getline(cin, answer);
  return answer;
}

// Constants for formatUnderscores
const vector<string> underscoreNames = {"cm","comma","dt","dot","period","dsd"};
const vector<string> underscoreDatas = {",",",",".",".",".","-/-"};

void formatUnderscores(string toFormat) {
  // temporary
}

auto math_22(string func,string param0,string param1) {
  // nothing(temporary)
  return ""; //temporary
}

// Run one line of the code
void runOneLine(string lineAsString) {
  vector<vector<string>> ct = splitFunc(lineAsString);
  module = ct[0][0];
  func = ct[0][1];
  params = ct[1];
  if (module == "main") {
    if (func == "print") {
      printStr(param(0));
    } else if (func == "ask") {
      log("Main.Ask() used. Now waiting for user input.");
      returns(askStr(param(0)));
    } else if (func == "exit") {
      log("Main.Exit used, now intentionally exiting.");
      mainOnExit();
      exit(0); // The 0 is required
    } else if (func == "loglist") {
    } else if (func == "errlist") {
    } else {
      notHave();
    }
  } else if (module == "strict") {
    if (func == "enabled") {
      if (param(0) == "true") {
        enableStrict = true;
      } else if (param(0) == "false") {
        enableStrict = false;
      } else {
        error("Can only be true or false.");
      }
    } else if (enableStrict == true) {
      if (func == "setvals") {
        // temporary
      } else {
        notHave();
      }
    } else {
      notHave(" Also, strict mode is not enabled.");
    }
  } else if (module == "math") {
    checker = math_22(func,param(0),param(1));
    if (checker == "err") {
      error(response);
    } else {
      returns(checker);
    }
  } else {
    error("Unknown module \"" + module + "\".");
  }
}

// Run multiple lines
void runPiznCode(const vector<string> code) {
  for (string i: code) {
    runOneLine(i);
  } 
}

// int main
int main() {
  string codeToRun = "main.print(test);main.exit();";
  
  vector<string> codeToRunNoColon = split(codeToRun,";");
  printStr("<//  Pizn Compiler  //>\n\n...\n\n");
  runPiznCode(codeToRunNoColon);
  mainOnExit();
  return 0;
}
