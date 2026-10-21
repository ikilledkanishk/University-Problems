2. Introduction to Shell and Shell Script
A. Define Shell, Shell Types and vi Editor
Shell:
A shell is a command-line interpreter that acts as an interface between the user and the operating system. It accepts commands from the user, executes them, and displays the results.
Types of Shell:
Bourne Shell (sh): One of the original Unix shells.
Bourne Again Shell (bash): An enhanced version of the Bourne Shell with additional features.
C Shell (csh): Uses syntax similar to the C programming language.
Korn Shell (ksh): Combines features of the Bourne and C shells.
Z Shell (zsh): An advanced shell with features such as command completion and customization.
vi Editor:
The vi editor is a text editor available on Unix and Linux systems. It is used to create and edit text files, including shell scripts. It has three commonly described modes:
Command Mode: Used to navigate and perform editing operations.
Insert Mode: Used to enter or modify text.
Last-Line Mode: Used to save files, quit the editor, and execute commands.

B. Create a Bash Shell Script to Display Your Name
#!/bin/bash
val1="Kanishk"
echo "My name is $val1"
