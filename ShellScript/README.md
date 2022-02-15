# Introduction

Here is some cheatsheet for writing shell script.

# Check execution output

* Whether equals to certain output

```sh
OUTPUT=`cat xxxx`
if [ $OUTPUT = "yyy" ]
    echo $OUTPUT
fi
```

* Whether the output is empty

```sh
if [[ $(ls -al) ]]; then
    echo "files exist"
else
    echo "empty"
fi
```

* Check exit code

```bash
files=$(ls -al)
if [[ $? != 0 ]]; then
    echo "execution failed"
elif [[ $files ]]; then
    echo "files exist"
else
    echo "empty"
fi
```

# if condition

```sh
if [ "$1" = "abc" ]; then
    echo "abc"
elif [ "$1" = "123" ]; then
    echo "123"
else
    echo "others"
fi
```

## Variable operation

```sh
if [ -n "$1" ]; then
    echo "If you have the first argument."
else
    echo "No first argument."
fi
```

* `-n variable`: return true if variable is set.
* `-z variable`: return true if variable is not set.

## Check absolute path or not

```sh
if [[ "$TEST_PATH" = /* ]]; then
fi
```

# Read input
```bash
echo -n "What is your input? (y/N)"
read your_input
if [ "$your_input" = "y" ] || [ "$your_input" = "Y" ]; then
    echo "Yes"
else
    echo "No"
fi
```

# for-loop

There are several ways for for-loop.

* `list`
```sh
for i in item1 item2 item3
do
    echo $i
done
```
* `seq`
```sh
for i in $(seq 1 10)
do
    echo $i
done
```
* `{min..max}`
```sh
for i in {1..10}
do
    echo $i
done
```
* `{min..max..step}`
```sh
for i in {1..10..2}
do
    echo $i
done
```
* `((exp1;exp2;exp3))`
```sh
for ((i=0;i<10;i=i+2))
do
    echo $i
done
```

# while loop

* Infinte loop
```sh
while :
do
    echo "Waiting..."
    sleep 1
done
```
* Condition
```sh
while [ $1 -le 10 ]
do
    echo "Do something..."
done
```

# Array

* Declaration
```sh
array=(
      element1
      element2
      element3
      )
```
* Get/Set: start from 1
```sh
array[1]="modified element1"
echo $array[1]
```
* Interation
```sh
# The quotes is needed
for i in "${array[@]}"; do
    echo "$i"
done
```

# function

```sh
# function definition
function funcname()
{
  # Get function name
  func_name=$0
  # Get parameter
  arg1=$1
  arg2=$2
  # Get arg number
  argn=$#
  # Get all arg
  echo "All arg: $*"
  echo "All arg: $@"
}

# call function
funcname arg1 arg2
```

# argument

```sh
if [ $# -ne 2 ]; then
    echo "./script.sh <arg1> <arg2>"
    exit 1
fi
```

# File operation

## Path attributes

```sh
if [ -f /this/is/filename ]; then
    echo "File exist."
fi
if [ ! -f /this/is/filename ]; then
    echo "File not exist."
fi
```

* `-d name`: return true if name is directory.
* `-f name`: return true if name is file.
* `-r name`: return true if name is readable.
* `-s name`: return true if name is not empty (size is not 0).
* `-w name`: return ture if name is writable.
* `-x name`: return true if name is executable.

## Iterate files

```bash
for filename in mypath/*.txt; do
    echo $filename
done
```

# Trap
trap is the shell built-in command, which can catch the signal.
Refer to [trap](https://wangchujiang.com/linux-command/c/trap.html)

* List all available trap: `trap -l`
* Show the trap settings: `trap -p`
* Set trap and test:
```bash
# While receiving INT signal, run `echo test123`
trap "echo test123" INT
# Send INT signal to current shell
kill -2 $$
```
* Useful commands
  - refer to [What is the difference between "kill 0" and "kill -‍- -$$"?](https://stackoverflow.com/questions/19252115/what-is-the-difference-between-kill-0-and-kill)
```bash
# Send TERM signal to the process group, which is the absolute number of current process ID.
# If pid is 10, send signal to pgid 10
trap "kill -TERM -$$ ; exit 1" INT QUIT
# Send TERM signal to the process group of the current process ID.
# If pid is 10 and pgid is 20, send signal to pgid 20
trap "kill -TERM 0 ; exit 1" INT QUIT
```

# Tips:
* Include other shell file
  - `source shell_file_name`
* Ignore output
  - `script >/dev/null`: Only ignore standard output
  - `scriptname >/dev/null 2>&1` or `scriptname >/dev/null 2>/dev/null`: Also ignore error output
* Equation:
  - `-eq` used in numeric.
  - `=` used in string.
  - `==` only used in bash.
  - refer to https://stackoverflow.com/questions/20449543/shell-equality-operators-eq
* Trace the shell script:
  - It'll print all commands you run (print + sign before the line)
  - Enable: `set -x` or `set -o xtrace`
  - Disable: `set +x`
* Get the shell you're using:
  - `cat /proc/$$/cmdline | tr -d '\0'`
    - refer to https://stackoverflow.com/questions/3327013/how-to-determine-the-current-shell-im-working-on
  - Note that if you are using login shell, the output will be like `-bash`
    - you can try `sudo login -f <username>` or refer to https://superuser.com/questions/278859/dash-in-front-of-bash
* Check whether run in root privilege
```bash
if [ "$EUID" -ne 0 ]; then
  echo "Please run in root privilege"
  exit
fi
```
* Check where the script is
  - Also available while source by other script
  - `${BASH_SOURCE[0]}` is the script name
```bash
export SCRIPT_PATH=`realpath ${BASH_SOURCE[0]}`
export DIR_PATH=`dirname ${SCRIPT_PATH}`
```
