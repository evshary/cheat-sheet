# System

* get BIOS: `wmic bios get smbiosbiosversion`

# Chocolatey
* List packages
  - List all packages: `choco list`
  - List installed packages: `choco list --local-only`
  - Search packages: `choco search <PACKAGES>`
  - Search packages contains string: `choco search ros-melodic-`
* Install/Uninstall packages
  - Install: `choco install <PACKAGES>`
  - Uninstall: `choco uninstall <PACKAGES>`
* Upgrade packages
  - Upgrade all: `choco upgrade all`
  - Upgrade certain: `choco upgrade <PACKAGES>`
  - Upgrade all except: `choco upgrade all --except="'<PACKAGES>,<PACKAGES>'"`
