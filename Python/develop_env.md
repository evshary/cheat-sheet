# Python development environment

This is Python develop environment note.

# Environment

* Find sys.path: `python3 -m site`
* More beautiful environment: `sudo apt install ipython ipython3`

# pip

Used to install packages for Python.

* pip should be installed after installing python.
* Correct to use pip
  - `python3 -m pip install <your_package>`
  - installed in `~/.local/lib/<python_version>/site-packages`
  - Note: if you use `apt install python-<packag>`, the path will be `/usr/lib/<python_version>/dist-packages`. (Not suggested)
  - The difference between site-packages and dist-packages:
    * site-packages: install from pip
    * dist-packages: install from apt
* Show packages detail
  - `python3 -m pip show <your_package>`
* Show all installed packages
  - `python3 -m pip list`
  - `python3 -m pip list -v`: more detail with path
* Upgrade pip: `python3 -m pip install --upgrade pip`

# pyenv

Used to run different version of Python.

* Installation

```bash
curl -L https://raw.githubusercontent.com/pyenv/pyenv-installer/master/bin/pyenv-installer | bash
```

* Add the environmental variable into `~/.bashrc`

```bash
export PYENV_ROOT="${HOME}/.pyenv"

if [ -d "${PYENV_ROOT}" ]; then
  export PATH="${PYENV_ROOT}/bin:${PATH}"
  eval "$(pyenv init -)"
fi
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
  - priority: shell(current shell) -> local(current directory) -> global(OS level)

```bash
pyenv global <version>
pyenv local <version>
pyenv shell <version>
# clean shell python version
pyenv shell --unset
```

* Show current python path and execute

```
# Show current python path
pyenv which python
# Execute python with current version
pyenv exec python
```

# virtualenv

Used to run virtual and clean Python environment.

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

# poetry

Python package manager, like npm in javascript.

* Installation & Usage

```bash
curl -sSL https://raw.githubusercontent.com/sdispater/poetry/master/get-poetry.py | python3
# Before use poetry
source $HOME/.poetry/env
# Update poetry
poetry self update
```

* init poetry (Generate pyproject.toml)

```bash
# --no-interaction means not to ask questions
poetry init --no-interaction
```

* Use correct Python version

```bash
poetry env use $(which python3)
# If you use pyenv
poetry env use $(pyenv which python)
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

# Reference
* [pyenv & virtualenv usage](https://www.maxlist.xyz/2020/04/01/python-pyenv-virtualenv/)
* [poetry with Django](https://ithelp.ithome.com.tw/articles/10233355)
