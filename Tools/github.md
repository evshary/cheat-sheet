# GitHub

The tutorial records some usage for GitHub.

# action

## self-action server

How to setup your own self action server

* Go to Organization => Action => Runners

* Click "New runner" and follow the steps to setup your server.
  - While running `run.sh` on your server, it'll prompt to enter password if GitHub action include "sudo apt-get" command. You can add "apt-get" into sudoers for the current user.

* Note that add "runs-on: [self-hosted, Linux, X64]" in your action jobs.

### WARNING: You need to make sure Action has right permission:

* Action => General => General actions permissions => Policies: Add your repository into it.
* Action => Runner Groups => Default => Repository access: Add your repository into it.

## Useful example

* To run in different architecture: [uraimo/run-on-arch-action](https://github.com/uraimo/run-on-arch-action)
  - Example: https://github.com/Adlink-ROS/mraa/blob/roscube_series/.github/workflows/main.yml

# secret

Put your password or sensitive data in secret in GitHub.

Usage: use `${{secrets.YOUR_SECRET_NAME}}` in action.

# Personal Access Tokens (PAT)

* Go to Settings => Developer settings => Personal access tokens

# How to use GHCR

Refer to https://docs.github.com/en/packages/working-with-a-github-packages-registry/working-with-the-container-registry

* Generate PAT with the following privileges:
  - read:packages
  - write:packages
  - delete:packages
* Export PAT: `export CR_PAT=YOUR_TOKEN`
* Login: `echo $CR_PAT | docker login ghcr.io -u USERNAME --password-stdin`
* Tag your images: `docker tag IMAGE_NAME:latest ghcr.io/OWNER/IMAGE_NAME:latest`
* Push docker images: `docker push ghcr.io/OWNER/IMAGE_NAME:latest`
