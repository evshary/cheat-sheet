# multipass
* Install
  - `snap install multipass`

* Run
  - Simple: `multipass launch --name myvm`
  - Assign detail: `multipass launch -c 4 -m 2048M -d 5G -n myvm`

* Info
  - List: `multipass list`
  - Info: `multipass info myvm`

* Use
  - Execute commands: `multipass exec myvm -- lsb_release -d`
  - Shell: `multipass shell myvm`

* Stop
  - Stop: `multipass stop myvm`
  - Clean: `multipass delete --purge myvm`
