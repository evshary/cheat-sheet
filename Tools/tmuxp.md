# tmuxp

tmux session manager: Able to load tmux config directly.

## installation

```py
python3 -m pip install tmuxp
```

## Run

* Create config file

* Load config file

```sh
tmuxp load ./mysession.yaml
```

## YAML example

* 3 panes in one window

```yaml
session_name: myexample_session
windows:
  - window_name: myexample_window
    panes:
    - shell_command:
      - echo 'This is pane 1'
    - shell_command: echo 'This is pane 2'
    - echo 'This is pane 3'
```

* tiled panes

```yaml
session_name: 4-pane-split
windows:
  - window_name: tiled_window_example
    layout: tiled
    shell_command_before:
      - source /opt/ros/foxy/setup.bash
    panes:
      - shell_command: # pane no. 1
          - echo 'This is pane 1'
          - echo 'This is also pane 1'
      - echo 'This is pane 2' # pane no. 2
      - echo 'This is pane 3' # pane no. 3
      - echo 'This is pane 4' # pane no. 4
```

## Reference

* [tmuxp Official Website](https://tmuxp.git-pull.com/)
* [如何使用 Tmuxp 来优雅的管理多个 Tmux 会话](https://blog.csdn.net/easylife206/article/details/116473899)
