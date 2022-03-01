# GitHub

The tutorial records some usage for GitHub.

# action

## self-action server

How to setup your own self action server

* Go to Organization => Action => Runners

* Click "New runner" and follow the steps to setup your server.
  - While running `run.sh` on your server, it'll prompt to enter password if GitHub action include "sudo apt-get" command. You can add "apt-get" into sudoers for the current user.

* Note that add "runs-on: [self-hosted, Linux, X64]" in your action jobs.

## Useful example

* To run in different architecture: [uraimo/run-on-arch-action](https://github.com/uraimo/run-on-arch-action)
  - Example: https://github.com/Adlink-ROS/mraa/blob/roscube_series/.github/workflows/main.yml

# secret

Put your password or sensitive data in secret in GitHub.

Usage: use `${{secrets.YOUR_SECRET_NAME}}` in action.
