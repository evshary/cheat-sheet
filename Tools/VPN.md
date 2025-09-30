# VPN

There are two solutions:

* OpenVPN
  * Complete solution supporting many algorithms.
  * Run at the user level
  * Stateful
* WireGuard
  * Lightweight with the modern algorithm
  * Run at the kernel level
  * Stateless

We suggest using WireGuard here.

## WireGuard

### Installation

* Install WireGuard on both the client and server sides

```bash
sudo apt update
sudo apt install wireguard
```

* Generate the key pairs (Will be used later)

```bash
# Server
wg genkey | tee privatekey_server | wg pubkey > publickey_server
# Client
wg genkey | tee privatekey_client | wg pubkey > publickey_client
```

* (Server side) The configuration: `/etc/wireguard/wg0.conf`

```toml
[Interface]
PrivateKey = xxxx  # Fill in privatekey_server
Address = 10.0.0.1/24       # The server IP in VPN
ListenPort = 51820          # Listen ports
PostUp = iptables -A FORWARD -i wg0 -j ACCEPT && iptables -A FORWARD -o wg0 -j ACCEPT && iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
PostDown = iptables -D FORWARD -i wg0 -j ACCEPT && iptables -D FORWARD -o wg0 -j ACCEPT && iptables -t nat -D POSTROUTING -o eth0 -j MASQUERADE

[Peer]
PublicKey = yyyy    # Fill in publickey_client
AllowedIPs = 10.0.0.2/32    # The client IP in VPN
```

* (Server side) Enable the VPN

```bash
sudo systemctl start wg-quick@wg0
sudo systemctl enable wg-quick@wg0
# You can see wg0 interface
ip a
```

* (Server side) Enable the IP forward in `/etc/sysctl.conf`
  * Uncomment `net.ipv4.ip_forward=1` and run `sudo sysctl -p`

* (Client side) The configuration: `/etc/wireguard/wg0.conf`

```toml
[Interface]
PrivateKey = aaaa    # Fill in privatekey_client
Address = 10.0.0.2/24       # The client IP in VPN

[Peer]
PublicKey = bbbb    # Fill in publickey_server
Endpoint = 1.2.3.4:51820 # Fill in the WireGuard server IP and port
AllowedIPs = 0.0.0.0/0
PersistentKeepalive = 25
```

* (Client side) Start the VPN

```bash
wg-quick up wg0
# Stop the VPN
wg-quick down wg0
```

### Reference

* [[Linux 架站] Wireguard VPN 設定教學](https://blog.jks.coffee/linux-wireguard-vpn-settings/)
