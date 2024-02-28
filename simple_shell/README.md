1. Setting up the Project
Create: new repository for our shell project on GitHub.
repo name: *simple_shell

Add partners as a collaborator to the repository.

We are expected to set up a README.md file at the root of the project folder.
1.1 README
Write a detailed README.md file with the following information:
Project description
How to compile the shell
How to run the shell in interactive and non-interactive mode
Any additional information or features about our shell

AUTHORS File
Create an authors file at the root of your repository, listing all individuals who
 have contributed content to the repository.
Name of file: AUTHORS


2. Coding Style
Write our shell program using vi, vim, or emacs editors.
Follow the Betty style guidelines for our code.
Use betty-style.pl and betty-doc.pl to check your code for compliance.

3. Compilation
Compile your shell program using the specified gcc options:
bash
:gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

4. File Structure
Ensure that all your files end with a new line.
Implement no more than 5 functions per file.
Include header files with proper include guards.

main.c:
Contains the main function and handles the interactive mode.

shell.c:
Implements the core functionality of the shell, including command execution, parsing, and error handling.

helper_functions.c:
Includes helper functions that are used in the main shell logic.

builtins.c:
Implements any built-in commands our shell may support (e.g., exit).

parser.c:
Handles command parsing and tokenization.

executor.c:
Deals with command execution, including executing external commands and handling redirections.

error_handling.c:
Manages error messages and reporting.

header.h:
Header file containing function prototypes, struct definitions, and any necessary macros.
Include guards should be implemented in this header file.




5. Memory Leaks
Make sure our shell does not have any memory leaks. You can use tools like Valgrind
 for memory leak detection.bash :valgrind --leak-check=full ./our_program


6. System Calls and Functions
Use the allowed functions and system calls listed in the requirements.
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fork (man 2 fork)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
 (RTFM)more infor on man pages
7. Testing
Test our shell in both interactive and non-interactive modes.
Ensure that the output and error messages match the behavior of /bin/sh.
Use provided examples to verify the correctness of your shell.


Regularly push our changes to the GitHub repository.
You can add more information on this guide to executing our project.
