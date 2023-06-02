# Our Own Version Of Simple Shell

It is a clone of the Unix shell built in C language it is a great project from the ALX internship.
## Allowed functions and system calls
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)
## Features  
- can work in interactive mode and non-interactive mode (pipe)
- Handling the command lines with arguments
- Handling the PATH 
- Implement the exit built-in, that exits the shell and handles the exit with arguments also
- Implement the env built-in, that prints the current environment
- Implement the setenv and unsetenv builtin commands
- Implement the builtin command cd
- Handling the comments (#)


## Run the project
Clone the project  

~~~bash  
  git clone https://github.com/MinaSamirSaad/simple_shell.git
~~~

Go to the project directory  

~~~bash  
  cd simple_shell
~~~

Compilation  

~~~bash  
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
~~~

Start the app 

~~~bash  
./shell
~~~  

## Screenshots  
![App Screenshot](https://github.com/MinaSamirSaad/simple_shell/screenshots/screenshots1.png)



## Authors
* **Mina Samir** => [MinaSamirSaad](https://github.com/MinaSamirSaad)
* **Mina William** => [mina-william-23](https://github.com/mina-william-23)
 
 