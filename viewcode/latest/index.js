let doing = 0;
let doLine = 1;
let i = 0;

let builder = "";
let checker = "";
let response = "";
let olr = [];
let mlr = [];

let errorList = [];
let errorCount = 0;
let logs = [];

let args = [];

const logBegin = "/[/<[/ Logged \\]>\\]\\: ";
const nl = "\n";
const tdent = "   ";

let enableStrict = false;
let showLogs = false;
let showErrors = true;

function print(toPrint, console, id=null) {
  if (console) {
    console.log(toPrint);
  } else {
    document.getElementById(id).value = toPrint;
  }
}

function log(message) {
  logs.push(message);
  if (showLogs) {
    print(`${logBegin}${message}${nl}`, false, "output");
  }
}

function error(message) {
  errorList.push(`Line: ${doLine}, message: ${message}`);
  errorCount++;
  if (showErrors) {
    print(`Error at line ${doLine}:${nl}${tdent}${message}`, false, "output");
  }
}

function notHave(more="") {
  error(`Module "${module}" doesn't have function "${func}". ${more}`);
}

function mainOnExit() {
  print(`${nl}${nl}...${nl}${nl}Process finished.`, false, "output");
}

function returns(returned) {
  print(`A function returned: ${returned}`, true);
}

function typeify(todo) {
  let result = [];
  for (let idx = 0; idx < todo.length; idx++) {
    if (idx == 0 && (todo[idx] == "\"" || todo[idx] == "'")) {
      continue;
    } else if (idx == todo.length - 1 && (todo[idx] == "\"" || todo[idx] == "'")) {
      continue;
    } else {
      result.push(todo[idx]);
    }
    return result;
  }
}

function param(idx) {
  return typeify(params[idx]);
}

function waitUntilFileIsnt(file, data) {
  // empty
}

function printList(a) {
  print(`Elements: ${nl}`, false, "output");
  for (let i = 0; i < a.length; i++) {
    print(`${a[i]}${nl}`, false, "output");
  }
}

function stSplit(s, delimiter) {
  return s.split(delimiter); // temp
}

function splitFunc(funcAsString) {
  let ct = funcAsString.split("(");
  let gtArgs = ct[0].toLowerCase().split(".");
  let gtParams = stSplit(ct[1].substr(0, ct[1].length - 1), ",");
  let gtFinal = [gtArgs, gtParams];
  return gtFinal;
}

function input(question) {
  return prompt(question);
}

const underscoreNames = ["cm","comma","dt","dot","period","dsd"];
const underscoreDatas = [",",",",".",".",".","-/-"];

function formatUnderscores(toFormat) {
  if (toFormat in underscoreNames) {
    for (let idx = 0; idx < underscoreNames.length; idx++) {
      if (underscoreNames[idx] == toFormat) {
        return underscoreDatas[idx];
      }
    }
  } else if (toFormat in underscoreDatas) {
    for (let idx = 0; idx < underscoreDatas.length; idx++) {
      if (underscoreDatas[idx] == toFormat) {
        return underscoreNames[idx];
      }
    }
  } else {
    return `Error: ${toFormat} not in an array.`;
  }
}

function math_22(func, param0, param1) {
  // nothing(temporary)
  return ""; //temporary
}

function runOneLine(lineAsString) {
  let ct = splitFunc(lineAsString);
  let module = ct[0][0];
  let func = ct[0][1];
  let params = ct[1];
  if (module == "main") {
    if (func == "print") {
      print(param(0), false, "output");
    } else if (func == "ask") {
      log("Main.Ask() used. Now waiting for user input.");
      returns(input(param(0)));
    } else if (func == "exit") {
      log("Main.Exit used, now intentionally exiting.");
      mainOnExit();
      while (true) {
        // stop program from running anymore
      }
    } else if (func == "loglist") {
      // none
    } else if (func == "errlist") {
      // none
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
        error(`Can only be true or false, not ${param(0)}.`);
      }
    } else if (enableStrict) {
      if (func == "setvals") {
        // none
      } else {
        notHave();
      }
    } else {
      notHave("Also, strict mode is not enabled.");
    }
  } else if (module == "math") {
    checker = math_22(func, param(0), param(1));
    if (checker == "err") {
      error(response);
    } else {
      returns(checker);
    }
  } else {
    error(`Unknown module "${module}".`);
  }
}

function runPiznCode(code) {
  for (let line = 0; line < code.length; line++) {
    runOneLine(line);
  }
}

function start() {
  let codeToRun = "main.print(test);main.exit();";  
  let codeToRunNoColon = codeToRun.split(";");
  print("<//  Pizn Compiler  //>\n\n...\n\n", false, "output");
  runPiznCode(codeToRunNoColon);
  mainOnExit();
}
