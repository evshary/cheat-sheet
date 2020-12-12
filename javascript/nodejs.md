# nvm (Node.js Version Manager)

## installation
* Install from script
```
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.37.2/install.sh | bash
```
* Add the following line to bashrc
```
source ~/.profile
```
* Select latest Node.js version
```
nvm install node
```

## Useful commands
* Get remote version
```
nvm ls-remote
```
* Show local version
```
nvm ls
```
* Select current version
```
nvm use <version>
```
* Change default version
```
nvm alias default <version>
```

# npm (Node.js Package Manager)
## init
* Init workspace (It'll create packages.json)
```
mkdir test_ws && cd test_ws
npm init
```
* Install/Uninstall necessary packages
```
# --save means to put packages info into packages.json
npm install --save <packages>
npm uninstall --save <packages>
```

## Run script in packages.json
* Add scripts in packages.json (Take vuepress as an example)
```
...
  "scripts": {
    "dev": "vuepress dev . --open --host \"localhost\"",
    "build": "vuepress build ."
  },
...
```
* Run
```
npm run build
npm run dev
```

## Exist project
* Install dependency project in packages.json
```
npm install
```

## Useful command
* `npm update`: Check packages update
* `npm prune`: Remove unused packages

# yarn
yarn is the replacement of npm.

## installation
* install
```
curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
echo "deb https://dl.yarnpkg.com/debian/ stable main" | sudo tee /etc/apt/sources.list.d/yarn.list
sudo apt update
sudo apt install --no-install-recommends yarn
```

* Usage

| npm | yarn |
| - | - |
| npm install | yarn install |
| npm install --save <pkg> | yarn add <pkg> |
| npm uninstall --save <pkg> | yarn remove <pkg> |
| rm -rf node_modules && npm install | yarn upgrade | 
| npm run <target> | yarn run <target> |
