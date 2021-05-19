# Python development environment

This is Python develop environment note.

# pyenv

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
```

# virtualenv

* Installation

```bash
pip3 install virtualenv
```

* Create environment

```bash
virtualenv venv
# Assign python version
virtualenv -p /usr/bin/python3 venv
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
```

* Install poetry packages from pyproject.toml

```bash
poetry install
```

* Run python with poetry environment

```bash
poetry run [python3 command]
```

* Config

```bash
# list all the config
poetry config --list
# disable virtualenv
poetry config virtualenvs.create false
```

# Reference
* [pyenv & virtualenv usage](https://www.maxlist.xyz/2020/04/01/python-pyenv-virtualenv/)
* [poetry with Django](https://ithelp.ithome.com.tw/articles/10233355)
