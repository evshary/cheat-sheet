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

## Exist project
* Install dependency project in packages.json
```
npm install
```
