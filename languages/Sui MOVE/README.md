# Sui MOVE

## Installation

* Install Rust first
* Install CLI: `cargo install --locked --git https://github.com/MystenLabs/sui.git --branch testnet sui --features tracing`
  * Refer to [the tutorial](https://docs.sui.io/guides/developer/getting-started/sui-install)
* Install sui-move-analyzer
  * Binary first: `cargo install --git http://github.com/movebit/sui-move-analyzer --branch master sui-move-analyzer`
  * VSCode extenstion

## CLI

* Build and test

```shell
# Build
sui move build
# Test
sui move test
```

* sui client

```shell
# Get current address
sui client active-address
# Get remaining gas
sui client gas
# Publish program
sui client publish --gas-budget 30000000 --skip-dependency-verification
# View the current object
sui client objects --json
```
