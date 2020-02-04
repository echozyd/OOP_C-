CSE332 Lab5

author: Yidi Zhang  yidi.zhang@wustl.edu
        https://github.com/cse332s-fl19-wustl/studios-echozyd
        MuZhou Liu  muzhouliu@wustl.edu
        https://github.com/cse332s-fl19-wustl/studios-TYTYTYTYTYTYTYTYTY


======================================================
Functions Modified:

LSCommand.cpp
 Add option "-l" which enables to show the MetaData of each file in the directory.

RemoveCommand.cpp
 
 Add option "-r" which enables to recurcively delete unempty directories.

HierarchicalFileSystem.cpp
 Modified it to make sure that unempty directory files can not be deleted.

------------------------------------
Functions Added:

CatCommand.h
 Header file for CatCommand.cpp

CatCommand.cpp
 Implement cat command to write the files.
 Provide "-a" option to help append files.

DisplayCommand.h
 Header file for DisplayCommand.cpp

DisplayCommand.cpp
 Implement display command to display both formatted and unformatted files.

CopyCommand.cpp:
    Implementation of the function for copy a file that exists in the file system and add the copy to the file system in a different locaiton. 
CopyCommand.h:
    Header field for CopyCommand.cpp. 

ProxyFile.cpp:
    Implementation of the interface for the proxy file, which inherits from the AbstractFile class. 
ProxyFile.h: 
    Header file for the ProxyFile.cpp.

symCommand.cpp:
    Implementation of the function for create a symbolic link to an existing file and add symbolic link to the file system in the given location. 
    The symbolic link is the type of ProxyFile. 

symCommand.h 
    Header file for the symCommand.cpp.
=======================================================

Test ls command:

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch dir2
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch dir1/dir3
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch 1.txt
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
dir1
dir2
1.txt

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls -l
dir1    directory    5
dir2    directory    0
1.txt    text    0
To quit: q, For a list of commands: help, For information about a specific command: help <command name>

----------------------------
Test cat and display command:

root $ touch 2.txt
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat 2.txt
Enter data you would like to write to the file, enter :wq to save the file and exit, enter :q to exit withough saving
12345
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds 2.txt
12345

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat 2.txt -a
12345

Enetr data you would like to add to the file, enter :wq to save the file and exit, enter :q to exit withough saving
6789
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds 2.txt
12345
6789

-----test if ":q" works correctly-----
root $ cat 2.txt -a
12345
6789

Enetr data you would like to add to the file, enter :wq to save the file and exit, enter :q to exit withough saving
1123
:q
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds 2.txt
12345
6789

-----test ds command and cat command for image
root $ touch 1.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat 1.img
Enter data you would like to write to the file, enter :wq to save the file and exit, enter :q to exit withough saving
X X X X X3
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds 1.img
X X
 X
X X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds 1.img -d
X X X X X

--------------------------------

Test remove command

root $ touch dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch dir1/dir3
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch dir1/dir3/3.txt
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir1/dir3
unable to delete non-empty directorycommand failed
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir1/dir3 -r
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
r
root/dir1 $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
1.img


---------------------------------

Test copy command:

root $ touch dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch dir1/dir3
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ touch 1.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat 1.img
Enter data you would like to write to the file, enter :wq to save the file and exit, enter :q to exit withough saving
X X X X X3
:wq

root $ cp 1.img root/dir1/dir3
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
dir1
1.img
root/dir1 $ cd dir3
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir3 $ ls
1.img
root/dir1/dir3 $ ds 1.img
X X
 X
X X

-----------------------------------

Test symbolic link

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ sym 1.img root/dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
dir1
1.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls
dir3
1.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds 1.img
X X
 X
X X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ cat 1.img
Enter data you would like to write to the file, enter :wq to save the file and exit, enter :q to exit withough saving
X  X2
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
dir1
1.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds 1.img
 X
X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm 1.img
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
dir1

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls
dir3
1.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds 1.img
 X
X


