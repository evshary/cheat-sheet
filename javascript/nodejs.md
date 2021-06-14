# nvm (Node.js Version Manager)

## installation
* Install from script
```bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.37.2/install.sh | bash
```
* Add the following line to bashrc
```bash
source ~/.profile
```
* Select latest Node.js version
```bash
nvm install node
```

## Useful commands
* Get remote version
```bash
nvm ls-remote
```
* Show local version
```bash
nvm ls
```
* Select current version
```bash
nvm use <version>
```
* Change default version
```bash
nvm alias default <version>
```

# npm (Node.js Package Manager)
npm is used to manage the packages of Node.js.
After npm5, it'll create package-lock.json to specify the version npm uses.

## init
* Init workspace (It'll create packages.json)
```bash
mkdir test_ws && cd test_ws
npm init
```
* Install/Uninstall necessary packages
  - Note: <packages> here can be replaced by repo
```bash
# --save means to put packages info into packages.json
npm install --save <packages>
npm uninstall --save <packages>
```

## Run script in packages.json
* Add scripts in packages.json (Take vuepress as an example)
```json
...
  "scripts": {
    "dev": "vuepress dev . --open --host \"localhost\"",
    "build": "vuepress build ."
  },
...
```
* Run
```bash
npm run build
npm run dev
```

## Exist project
* Install dependency project in packages.json
```bash
npm install
```

## Useful command
* `npm update`: Check packages update
* `npm prune`: Remove unused packages
* `npm audit fix`: Fix security issues in packages

## Upgrade packages
```bash
npm install -g npm-upgrade
npm-upgrade
```

# yarn
yarn is the replacement of npm.
yarn can cache the downloaded packages (no need to download again) and has better performance.
It'll create yarn.lock to specify the packages version yarn uses.

## installation
* install (suggestion)
```bash
npm install -g yarn
```
* Another way
```bash
curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
echo "deb https://dl.yarnpkg.com/debian/ stable main" | sudo tee /etc/apt/sources.list.d/yarn.list
sudo apt update
sudo apt install --no-install-recommends yarn
```

## Usage

| npm | yarn |
| - | - |
| npm install | yarn install |
| npm install --save <pkg> | yarn add <pkg> |
| npm uninstall --save <pkg> | yarn remove <pkg> |
| rm -rf node_modules && npm install | yarn upgrade | 
| npm run <target> | yarn run <target> |

# Lerna
Used to manage multiple packages (build, version control...) in one project.

## Installation
```bash
npm install -g lerna
```
## Usage
* init
  - There are two modes in Lerna: Fixed Mode and Independent Mode
    - Fixed Mode: All the packages use the same version of dependencies.
    - Independent Mode: Each packages has its own version of dependencies.
```bash
# Fixed Mode
lerna init
# Independent Mode (suggested)
lerna init --independent
```
* list packages
```bash
lerna ls
```
* Run scripts
```bash
lerna run [script]
```
* Clean node_modules
```bash
lerna clean
```
