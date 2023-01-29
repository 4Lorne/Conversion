# Program Requisites
1. Reads in a C++ source file (.cpp)
2. Converts all '<' symbols to '&lt\;'
3. Converts all '>' symbols to '&gt\;'
4. Add the '<PRE\>' and </PRE\> tags to the front and end of the file
5. Output the modified file to disk as an html file

# Example

## Input
```c++
#include <iostream>

int main()

{

int x=4;

if (x < 3) x++;

cout << x << endl;

}
```

## Output
```html
<PRE>

#include &lt;iostream&gt;

int main()

{

int x=4;

if(x &lt; 3) x++;

cout &lt;&lt; x &lt;&lt; endl;

}

</PRE>
```

* You can test your output file by opening it with a web browser. The contents should appear identical to the original source code.

# Other Notes
* Validation must ensure that only valid Windows file names be processed (even if the demonstration will take place on a Mac). This will require that you research the criteria for a valid Windows file name for your validation routine.
* Be clear with the user (and validate) what information you want from them regarding the file names (e.g. “bobFile” or “c:\bobFile” or “c:\bobFile.cpp”). It is poor UI design to make them guess.
* Follow the rubric located below.
* Cite sources.


| Criteria                                     | Excellent                                                                                                                               |
| -------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| Solution developed to specification          | Program performs to all specifications and is free of syntax and logic errors.                                                          |
| Code Readability                             | Well documented, formatted, variables and other program elements named appropriately                                                    |
| User Interface                               | Functional, appropriate and easy to use.                                                                                                |
| Reading cpp file                             | Solution includes routine to read from a cpp file without error.                                                                        |
| Writing html file                            | Solution includes routine to write to an HTML file without error.                                                                       |
| File name & path requisition                 | Solution requests file name for both the cpp file being read and html file being written with **correct validation** for a Windows file |
| Custom String Replace Method to Replace tags | Solution implements a **custom** routine like a library string replace function                                                         |
| File Stream Methods                          | Solution implements fin.fail() and fout.fail() methods appropriately                                                                    |
| Exception Handling / Library Default & Programmer | Solution contains appropriate “try/catch” implementations. Minimum around all file read/write and file close routines. **You must provide examples of library, default, & programmer created exceptions.** |
