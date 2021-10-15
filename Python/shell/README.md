# Introduction

There are several ways to call shell commands.

* os
* subprocess (recommended)

# Environment

Both os and subprocess can inherit the environment of your current shell.
(We've tested `os.system("xxx")` and `subprocess.run("xxx", shell=True)`)
