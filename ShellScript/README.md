# introduction

Here is some cheatsheet for writing shell script.

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

## Useful operators

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

## Check absolute path or not

```sh
if [[ "$TEST_PATH" = /* ]]; then
fi
```

# Read input
```bash
echo -n "What is your input? (y/N)"
read your_input
if [ "$your_input" '==' "y" ] || [ "$your_input" '==' "Y" ]; then
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

# Others
* Include other shell file
  - `source shell_file_name`
