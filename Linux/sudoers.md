# sudoers

There are two paths for sudoers:

* `/etc/sudoers`: Default path for sudoers
* `/etc/sudoers.d/filename`: Customized configuration for sudoers

# rules

## format

Format: `useralias hostalias = (user:group) command`

That is, `useralias` can login from `hostalias` with priviege `user` & `group` and run `command`

If `useralias` starts with %, it means group

```
# user => for user root
root    ALL=(ALL:ALL) ALL
# group => for group sudo
%sudo   ALL=(ALL:ALL) ALL
```

## Example

* `ros ALL=(ALL:ALL) NOPASSWD:ALL`: user `ros` can run any commands without password.
* `ros ALL=(root) NOPASSWD: /usr/bin/apt-get update`: Only available to run `apt-get update` in root privilege

# Note

Always use `visudo` to modify sudoer file, since it'll check the syntx.

* `visudo`: modify `/etc/sudoers`
* `visudo -f /etc/sudoers.d/filename`: modify the file under `/etc/suders.d`

If you've already had the wrong sudoer file, run `pkexec visudo` to fix it.

If default editor is not vim, you can change it with `sudo update-alternatives --config editor`.
