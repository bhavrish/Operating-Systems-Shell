# Operating-Systems-Shell

Operating-Systems-Shell is a Terminal-based app that simulates a basic shell. It supports the follow functions: 
1. **tree-** this new command will create a directory and call it Dir0. Then it will change the working
directory to Dir0, and create three empty text files namely; t1.txt, t2.txt,and t3.txt, and one empty
directory , called Dir1,inside it.
2. **list-** this new command will clear the terminal screen and print a detailed list of all content of
the current directory (similar to ls -l) to the terminal and t1.txt. Finally, it will change the name of
text file to tree.txt.
3. **path-** this new command will print the path of the current directory to the terminal and t2.txt,
and change the name of text file to path-info.txt. Concatenate the content of tree.txt and path.txt
into t3.txt and change the last to log.txt. Finally, delete tree and path text files
4. **exit-** this new command will print a list the last 4 commands to the terminal, a detailed list of all content of the current directory (similar to ls -l). Finally, it will wait for the user to hit the “return”
key to terminate the shell and return the control to the original shell program on your machine.

It was developed by Bhavesh Shah, Krushang Shah, David Balaban, Zeal Patel, and Greg Kimatov for our CSC332 class.

## How to use

```
git clone https://github.com/bhavrish/Operating-Systems-Shell.git
cd Operating-Systems-Shell
./build.sh // compiles all the source files
./shell // runs the shell
```

