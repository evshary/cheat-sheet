# File

## lsof

* `lsof <file name>`: Who open the file
* `lsof -c <command>`: List files opened by certain command
* `lsof -p <PID>`: List files opened by certain process

## zip

* `sudo apt install zip unzip`: Installation
* `zip -r file.zip folder/*`: Compress folder into file.zip
* `unzip file.zip`: Uncompress the folder

# Picture & Video

* Show picture from terminal
  - `eog picture.png`
* Play the video from /dev/video0
  - `mplayer tv://device=/dev/video0`: need to `sudo apt install mplayer` first
  - `vlc v4l2:///dev/video0`: need to `sudo apt install vlc` first
* Check the resolution & FPS of camera
```bash
sudo apt-get install v4l-utils
v4l2-ctl --list-formats-ext
```

# Bash redirect

```shell
# Redirect stderr to stdout
ls UnExistedFile 2>&1
# Redirect stderr and stdout to file
ls UnExistedFile > output.txt 2>&1
ls UnExistedFile &> output.txt # abbreviation
# Redirect stdout to file but stderr to stdout
ls UnExistedFile 2>&1 > output.txt
```

# tee

Copy the output to another place

* Redirect all the output to output.txt

```shell
# Replace
./executable 2>&1 | tee result.txt
# Append
./executable 2>&1 | tee -a result.txt
```

* Save the output of executable to output.txt and grep something 

```shell
./executable | tee output.txt | grep something
```

* Put string into file with root privilege

```bash
echo 'My conntent' | sudo tee /tmp/filename > /dev/null
# append string into file
echo 'My appended content' | sudo tee -a /tmp/filename > /dev/null
```

# Others

* Search with filename
  - `find <PATH> -name <FILE NAME>`
* Search content from files
  - `ag <CONTENT>`
  - Should install `silversearcher-ag` first.
* Show folder size
  - `du -sh <FOLDER>`
* List the largest file under the path
  - Include directories: `du -ah * | sort -rh | head -n 10`
  - Ignore directories: `find . -type f -exec du -ah {} + | sort -rh | head -n 10`
* xargs
  - `echo a b c d e f | xargs -n 3`: Echo the first 3 items
  - `echo a b c d e f | xargs -p`: Check before execution
  - `find . -name "*.swp" | xargs rm -f -p`: Delete all the files match the search result.
  - `find . -name "*.swp" -print0 | xargs -0 rm -rf -p`: Delete all the files match the search result. (name can have space.)
  - `find . -name '*.c' | xargs grep 'main'`: Pase all the `.c` files and find main.
* Make you seem like busy
  - `sudo apt install hollywood`
  - `hollywood`
* Parallel execution
  - `parallel echo ::: 1 2 3`
  - `parallel ::: 'echo "1"' 'echo "2"' 'echo "3"'`
