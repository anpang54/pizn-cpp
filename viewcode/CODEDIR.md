**README:** [Main](https://github.com/piznium/pizn/blob/main/README.md) | [License](https://github.com/piznium/pizn/blob/main/LICENSE.md) | [Notes](https://github.com/piznium/pizn/blob/main/NOTES.md) | [**Code Directory**](https://github.com/piznium/pizn/blob/main/viewcode/CODEDIR.md)

### viewcode Directory
The pizn/viewcode directory contains 4 subdirectories:
| Directory | Name | Description |
| - | - | - |
| [/latest](https://github.com/piznium/pizn/tree/main/viewcode/latest) | Latest Pizn Version | The most recent stable version of Pizn. Should be the one that's imported. |
| [/beta](https://github.com/piznium/pizn/tree/main/viewcode/beta) | Latest Beta Pizn Version | The most recent beta/preview version of Pizn. |
| [/latest_pie](https://github.com/piznium/pizn/tree/main/viewcode/latest_pie) | Latest Pie Version | The most recent stable version of Pie. |
| [/beta_pie](https://github.com/piznium/pizn/tree/main/viewcode/beta_pie) | Latest Beta Pie Version | The most recent beta/preview version of Pie. |

### viewcode/latest Files
| File | Description | Hosts |
| - | - | - |
| [/main.cpp](https://github.com/piznium/pizn/blob/main/viewcode/latest/main.cpp) | The main C++ file containing most code. | Main code and many modules |
| /math.cpp | The C++ file containing code for the `Math` module. | `Math` module |
| [/tt.cpp](https://github.com/piznium/pizn/blob/main/viewcode/latest/tt.cpp) | The C++ file containing code for the `tt` module. | `tt` module |
| /tt-buildsite.cpp | The C++ file containing code for the `BuildSite` module. | `BuildSite` module |
| [/comms.json](https://github.com/piznium/pizn/blob/main/viewcode/latest/comms.json) | The file where the other code files send data to each other. | *none* |
| [/cross.json](https://github.com/piznium/pizn/blob/main/viewcode/latest/cross.json) | The file where cross-file variables are stored at. | *none* |
| [/main.java](https://github.com/piznium/pizn/blob/main/viewcode/latest/main.java) | The main Java file containing most Java-related code. | `Game` and `Graphics` modules. |
| /multil/execpy.py | The Python file for the `MultiL` module. | `MultiL.RunPy()` |
| /multil/execjava.java | The Java file for the `MultiL` module. | `MultiL.RunJava()` |
| /multil/execjs.js | The JavaScript file for the `MultiL` module. | `MultiL.RunJS()` |
| /multil/execcs.cs | The C# file for the `MultiL` module. | `MultiL.RunCS()` |
| /multil/execlua.lua | The Lua file for the `MultiL` module. | `MultiL.RunLua()` |

#### Notes and references
* There is no `execc.c` file because there is no `MultiL.RunC()` as all C code can be ran in C++. And there is also no `execcpp.cpp`, of course.
