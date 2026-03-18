# MINISHELL

**Minishell** is an implementation of an interactive Unix shell inspired by Bash, written in C.
It reproduces a significant part of the behavior of a classic shell.

![demo](https://github.com/user-attachments/assets/4f100bf5-4485-4c01-9d3f-c37baa0bcb5c)

---

## Installation

<details>
<summary>🐳 Option 1: Docker (all platforms)</summary>

1. Install Docker: [https://docs.docker.com/get-docker/](https://docs.docker.com/get-docker/)

2. Run the shell in a Docker container:

```bash
docker run --rm -it benjaminrap/minishell:latest
```

</details>

<details>
<summary>💻 Option 2: Linux (Debian/Ubuntu)</summary>

1. Clone the repository:

```bash
git clone https://github.com/BenjaminRap/MINISHELL.git
cd MINISHELL
```

2. Install dependencies:

```bash
sudo apt update
sudo apt install -y make gcc libreadline-dev
```

3. Compile the project:

```bash
make all
```

4. Run the shell:

```bash
./minishell
```

</details>

---

## Features

<details>
<summary>💾 Command Execution</summary>
<br>
The shell can execute programs by automatically searching in the `PATH` environment variable.

```bash
$ ls
minishell  README.md  src
```

</details>

<details>
<summary>🔗 Pipes</summary>
<br>
Pipes allow connecting the output of one command to the input of another.

```bash
$ ls | wc -l
3
```

</details>

<details>
<summary>➡️ Redirections</summary>
<br>
The shell supports input and output redirections.

```bash
$ echo "hello world" > file.txt
$ cat file.txt
hello world
```

Input redirection:

```bash
$ wc -l < file.txt
1
```

Append to a file:

```bash
$ echo "another line" >> file.txt
```

</details>

<details>
<summary>📄 Heredoc</summary>
<br>
Allows providing a block of text directly to a command.

```bash
$ cat << EOF
hello
world
EOF
hello
world
```

</details>

<details>
<summary>⚙️ Builtins</summary>
<br>
Some commands are executed directly by the shell:

* `cd`
* `echo`
* `pwd`
* `export`
* `unset`
* `env`
* `exit`

Example:

```bash
$ cd ..
$ pwd
/home/user
```

</details>

<details>
<summary>🌐 Environment Variables</summary>
<br>
The shell allows using and setting environment variables.

```bash
$ export NAME=world
$ echo hello $NAME
hello world
```

The return code of the last command is accessible via `$?`.

```bash
$ ls
$ echo $?
0
```

</details>

<details>
<summary>⚡ Conditional Execution</summary>
<br>
The shell supports the logical operators `&&` and `||`.

```bash
$ mkdir test && cd test
```

```bash
$ cat file.txt || echo "file not found"
file not found
```

</details>

<details>
<summary>🌀 Subshells</summary>
<br>
Commands can be executed in a subshell.

```bash
$ (cd /tmp && ls)
```

</details>

<details>
<summary>↔️ Command Line Navigation</summary>
<br>
Thanks to the `readline` integration, it is possible to edit the command line:

* move the cursor with left/right arrows
* modify a command before executing it

</details>

<details>
<summary>📜 Command History</summary>
<br>
Previously executed commands are saved in the history.  
Up and down arrows allow navigating through commands.

</details>

<details>
<summary>🔧 Autocompletion</summary>
<br>
The shell supports autocompletion for file and folder names.

```bash
$ Mak<TAB>
Makefile
```

</details>

<details>
<summary>🚨 Signal Handling</summary>
<br>
The shell handles certain user signals:

* `Ctrl + C`: `SIGINT` signal, interrupts the current command or creates a new shell line
* `Ctrl + D`: sends EOF, exits the shell or ends the input of a command
* `Ctrl + \`: `SIGQUIT` signal, interrupts the current command

</details>

<details>
<summary>🌟 Wildcards</summary>
<br>
The shell supports wildcard expansion.

```bash
$ ls *.c
main.c  parser.c  exec.c
```

</details>
