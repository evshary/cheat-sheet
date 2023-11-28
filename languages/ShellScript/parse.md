# Useful tool

* `tr`: remove the specific characters
  - `echo "abc 123" | tr -d ' '` => abc123
* `sed`: Use regular expression
* `cut`: split strings and the specific fields
  - `echo "a,b,c,d" | cut -d , -f 3` => c

# Replace string

* Replace string in file: use sed
  - Note: we need to use `""` for shell variable `$`
  - `sed -i "s/vx.x.x/${version}/g" filename`

# Split String

* If you have "abc-def-ghi" and want to get each items

```sh
# Split the string
strarr=(`echo "abc-def-ghi" | tr '-' ' '`)
for var in ${strarr[@]}
do
   echo $var
done
echo $strarr[0]
echo $strarr[1]
echo $strarr[2]
# If you use zsh, it should start with 1, that is echo ${strarr[1]}
```

* If you have "aaa: bbb, xxx: yyy" and want to get yyy

```sh
echo "aaa: bbb, xxx: yyy" | cut -d : -f 3 | tr -d ' '
```