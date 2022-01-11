# Introduction

aptly can manage your apt server easily.

* Documentation: https://www.aptly.info/doc/overview/
* Installation (2 ways):
  - apt server: https://www.aptly.info/download/
  - deb file (Suggested): https://github.com/aptly-dev/aptly/releases
  - Note: the version of second one is newer (1.4), while the first one remains 1.3.
* Tutorials:
  - How to mirror existed repo and setup your own server: https://www.aptly.info/tutorial/mirror/
  - How to upload packages: https://www.aptly.info/tutorial/repo/
  - How to use pull: https://www.aptly.info/tutorial/pull/
* Configuration:
  - Location: `~/.aptly.conf`
  - The generated repo and snapshot is under `~/.aptly`
  - Refer to https://www.aptly.info/doc/configuration/

# Commands

The relationship between the state of aptly and commands.

# Usages

## Command Line

* Create repo and publish

```bash
# create repo
aptly repo create -component=main <repo_name>
# Remove repo (optional)
aptly repo drop <repo_name>
# List repo (optional)
aptly repo list
# Add deb into repo
aptly repo add <repo_name> <deb_name>
# Remove deb from repo
aptly repo remove <repo_name> <deb_name>
# Check the packages in repo (optional)
aptly repo show -with-packages <repo_name>
# Publish repo
aptly publish repo -distribution=focal <repo_name>
# Update repo if you've already published
aptly publish update focal
# List publish (optional)
aptly publish list
# Remove publish (optional)
aptly publish drop focal
# Run apt server
aptly serve
# Run api server
aptly api serve
```

* Use snapshot to publish

```bash
# Create repo
# ...
# Create snapshot from repo
aptly snapshot create <snapshot_name> from repo <repo_name>
# List snapshot
aptly snapshot list
# Publish snapshot
aptly publish snapshot -distribution=focal <snapshot_name>
# Run server
# ...
```

## API

We can use RESTful API to control aptly.
Refer to https://www.aptly.info/doc/api/

* Create repo and publish

```bash
# Create repos
curl -X POST -H 'Content-Type: application/json' --data '{"Name": "myrepo"}' http://localhost:8080/api/repos
# List repos (optional)
curl http://localhost:8080/api/repos
# Delete repos (optional)
curl -X DELETE http://localhost:8080/api/repos/myrepo
# Upload file
curl -X POST -F file=@mydeb.deb http://localhost:8080/api/files/myrepo
# List file (optional)
curl http://localhost:8080/api/files
# Add file into repo
curl -X POST http://localhost:8080/api/repos/myrepo/file/myrepo
# List packages detail in repo (optional)
curl http://localhost:8080/api/repos/myrepo/packages
# Publish
curl -X POST -H 'Content-Type: application/json' --data '{"SourceKind": "local", "Sources": [{"Name": "myrepo"}], "Architectures": ["i386", "amd64"], "Distribution": "focal"}' http://localhost:8080/api/publish/:.
# List publish (optional)
curl http://localhost:8080/api/publish
# The packages can be viewed under ~/.aptly/public/pool/main/
# Update publish while local change
curl -X PUT http://localhost:8080/api/publish/:./focal
```

## How to run with apt install

* Add the following line in `/etc/apt/sources.list`

```bash
deb [trusted=yes] http://localhost:8080/ focal main
```

* Update

```bash
sudo apt update
```
