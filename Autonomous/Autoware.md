# Installation

* Download ade-cli from [release page](https://gitlab.com/ApexAI/ade-cli/-/releases)
* Rename to ade, add execute privilege, and then put under `/usr/local/bin/`.
* Update ade-cli: `ade update-cli`
* Setup ADE home

```bash
mkdir -p ~/adehome
cd ~/adehome
touch .adehome
git clone https://gitlab.com/autowarefoundation/autoware.auto/AutowareAuto.git
cd AutowareAuto
```

* Enter autoware environment

```bash
ls -l .aderc*
# Only start ade
ade start --update --enter
# Start ade with lgsvl
ade --rc .aderc-amd64-foxy-lgsvl start --update --enter
# If you've already run ade start
ade --enter
```

# Uninstallation

```bash
ade stop
docker system prune -a --volumes
```