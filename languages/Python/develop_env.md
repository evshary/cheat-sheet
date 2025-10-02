# Python development environment

This is Python develop environment note.

## Environment

* Find sys.path: `python3 -m site`
* More beautiful environment: `sudo apt install ipython ipython3`

## Include other module

* Add sys.path

```py
# In your python file
import sys
sys.path.append("/your_module_path/lib/python3.6/dist-packages")
```

* Use environment variables: `PYTHONPATH`

```bash
env PYTHONPATH="/your_module_path/lib/python3.6/dist-packages" python3
```

* Use pth: Put `.pth` file under `/usr/local/lib/python3.6/dist-packages/`
  * File content:

```raw
/your_module_path/lib/python3.6/dist-packages
```

## pip

Used to install packages for Python.

* pip should be installed after installing python.
* Correct to use pip
  * `python3 -m pip install <your_package>`
  * installed in `~/.local/lib/<python_version>/site-packages`
  * Note: if you use `apt install python-<packag>`, the path will be `/usr/lib/<python_version>/dist-packages`. (Not suggested)
  * The difference between site-packages and dist-packages:
    * site-packages: install from pip
    * dist-packages: install from apt
* Show packages detail
  * `python3 -m pip show <your_package>`
* Show all installed packages
  * `python3 -m pip list`
  * `python3 -m pip list -v`: more detail with path
* Upgrade pip: `python3 -m pip install --upgrade pip`

## Useful tools

* uv (suggested): It's fast and able to do all the things
* pyenv: Manage the Python version
* poetry: Manage the project packages
* virtualevn: Manage the virtual environment

## uv

* Install uv

```bash
curl -LsSf https://astral.sh/uv/install.sh | sh
```

* Install python

```bash
# List the available Python
uv python list
# Install the latest Python
uv python install
# Install a specific Python version
uv python install 3.10
# Unstall Python
uv python uninstall 3.10
# Pin the default Python (create .python-version on the current folder)
uv python pin 3.12
```

* Run Python

```bash
# Use default Python to run
uv run demo.py
# Run with a specific Python version
uv run --python 3.10 demo.py
```

* Create a new project

```bash
# Create a new project. Will create pyproject.toml and .python-version
uv init [project name]
# With a specific version
uv init [project name] --python 3.10
# Add a new package
uv add [package name]
# Remove a package
uv remove [package name]
# Upgrade a specific package
uv lock --upgrade-package [package name]
# Upgrade all packages
uv lock --upgrade
```

## pyenv

Used to run different version of Python.
Don't use `pyenv-virtualenv` to avoid the conflict with poetry.

* Installation

```bash
curl https://pyenv.run | bash
```

* Add the environmental variable into `~/.profile`

```bash
export PYENV_ROOT="$HOME/.pyenv"
[[ -d $PYENV_ROOT/bin ]] && export PATH="$PYENV_ROOT/bin:$PATH"
eval "$(pyenv init -)"
```

* Install Python list

```bash
# List all the Python
pyenv install --list
# Install the specific Python version
pyenv install -v <version>
# Check the installed Python version
pyenv versions
```

* Change the Python version
  * priority: shell(current shell) -> local(current directory) -> global(OS level)

```bash
pyenv global <version>
pyenv local <version>
pyenv shell <version>
# clean shell python version
pyenv shell --unset
```

* Show current python path and execute

```shell
# Show current python path
pyenv which python
# Execute python with current version
pyenv exec python
```

## poetry

Python package manager, like npm in javascript.
poetry also supports virtual env of Python, so you don't need pyenv and virtualenv.
[再見了 pip！最佳 Python 套件管理器——Poetry 完全入門指南](https://blog.kyomind.tw/python-poetry/) is the best tutorial I've ever seen for poetry.

* Installation & Usage

```bash
curl -sSL https://install.python-poetry.org | python3 -
# Add to the environmental variables
export PATH=$PATH:$HOME/.local/bin
# Update poetry
poetry self update
# Uninstall
POETRY_UNINSTALL=1 bash -c 'curl -sSL https://install.python-poetry.org | python3'
```

* init poetry (Generate pyproject.toml)

```bash
# --no-interaction means not to ask questions
poetry init --no-interaction
```

* Create Python environment

```bash
# Put .venv file under the project
poetry config virtualenvs.in-project true
# Use the current python3
poetry env use python3
# If you use pyenv
poetry env use $(pyenv which python)
# Remove environment
poetry env remove <env_name>
```

* Add/Remove package for poetry

```bash
poetry add <package_name>
poetry remove <package_name>
```

* Install poetry packages from pyproject.toml

```bash
poetry install
```

* Run python with poetry environment

```bash
poetry run [python3 command]
# Run shell with poetry environment
poetry shell
```

* Config

```bash
# list all the config
poetry config --list
# disable virtualenv
poetry config virtualenvs.create false
```

* Package

```bash
poetry build
```

## virtualenv (Not recommended)

Used to run virtual and clean Python environment.
However, it overlaps with poetry, so not recommend to use this.

* Installation

```bash
pip3 install virtualenv
```

* Create environment

```bash
virtualenv venv
# Assign python version
virtualenv -p /usr/bin/python3 venv
# If you use pyenv, you the following commands
virtualenv -p $(pyenv which python) venv
```

* Activate / Deactivate venv

```bash
# Activate environment
source venv/bin/activate
# Show packages list
pip3 list
# Deactivate environment
deactivate
```

## Reference

* [pyenv & virtualenv usage](https://www.maxlist.xyz/2020/04/01/python-pyenv-virtualenv/)
* [poetry with Django](https://ithelp.ithome.com.tw/articles/10233355)
