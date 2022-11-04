# Device detail

## Wireless Device detail
* `iwconfig`
* `iwlist`: More functions

## Ethernet Device detail
* `ethtool`

# Address
* Show IP address
  - `ip addr show` or `ip a s`
  - IPv4/IPv6 only: `ip -4 a s` or `ip -6 a s`
* Set IP address
  - Set address: `ip a add <IP>/<NETMASK> dev <DEVICE>`
  - Clear address: `ip a del <IP>/<NETMASK> dev <DEVICE>`
* DHCP address
  - `dhclient <interface>`: Get IP address from DHCP Server
  - `dhclient -r <interface>`: Release IP address

# Router
* Show router
  - `ip route` or `ip r` 
* Set default router
  - `ip r add default via <GATEWAY> dev <DEVICE>`
* Set routing table
  - `ip route add <IP>/<NETMASK> via <GATEWAY> dev <DEVICE>`
  - `ip route del <IP>/<NETMASK>`

# Interface
* Only show MAC
  - `ip link show`
  - Show the running interface: `ip link show up`
* Turn on/off network interface
  - `ip link set <DEVICE> up`
  - `ip link set <DEVICE> down`

# Socket Status
* List all the socket status: `ss`
* Only list certain socket
  - Listening port: `ss -l`
  - TCP socket: `ss -t`
  - UDP socket: `ss -u`
  - Domain socket: `ss -x`

# Network Manager
* Enable/Disable Network Mangager
  - `nmcli networking on`
  - `nmcli networking off`
* Show network device status
  - `nmcli device status`
* Show detail device info
  - `nmcli device show`
* Connect/Disconnect device
  - `nmcli device connect <interface>`
  - `nmcli device disconnect <interface>`
* Network Settings
  - `nmcli device modify <interface> ipv4.method manual ipv4.addresses 10.0.0.1/8 ipv4.gateway 10.0.0.254 ipv4.dns "8.8.8.8 8.8.4.4"`
  - `nmcli device modify <interface> ipv4.method auto`
  - We can use `-` to remove setting. For example, `nmcli device modify enp1s0 -ipv4.dns 0`.
* Show wireless signal
  - `nmcli device wifi`
* Connect to SSID
  - `nmcli device wifi connect <SSID> password <password>`
  - Connection infomation will be in `/etc/NetworkManager/system-connections/<SSID>`
* Connect/disconnect to SSID already known
  - `nmcli connection show` to get UUID
  - `nmcli connection up <UUID>`
  - `nmcli connection down <UUID>`

# Remote
* Scan the certain port in the LAN
  - `nmap -p <port> 192.168.0.1-255`

# Settings
* IPv4 settings: `/proc/sys/net/ipv4/`

# Bridge

Used to bridge different interffaces, and become hub

* create/delete bridge
    
```bash
brctl addbr br0
brctl delbr br0
```
    
* show bridge
    
```bash
brctl show
```
    
* add/delete interface
    
```bash
brctl addif br0 eth0
brctl delif br0 eth0
```

# Change MAC address

```bash
sudo ifconfig eth0 down
sudo ifconfig eth0 hw ether 00:11:22:33:44:55
sudo ifconfig eth0 up
```
