# Sui MOVE

## Installation

* Install Rust first
* Install CLI: `cargo install --locked --git https://github.com/MystenLabs/sui.git --branch testnet sui --features tracing`
  * Refer to [the tutorial](https://docs.sui.io/guides/developer/getting-started/sui-install)
  * You might need to run this if you see the version mismatch.
* Install sui-move-analyzer
  * Binary first: `cargo install --git http://github.com/movebit/sui-move-analyzer --branch master sui-move-analyzer`
  * VSCode extenstion

## CLI

* Build and test

```shell
# Create a new project
sui move new your_project_name
# Build
sui move build
# Test
sui move test
```

* Include local library
  * Update `Move.toml` and update the `[dependencies]`

```toml
[dependencies]
otherlib = { local = "../otherlib" }
```

* sui client

```shell
# Create a new address (Remember to record the recovery phrase)
sui client new-address ed25519
# Get all the address
sui client addresses
# Switch address
sui client switch --address <address>
# Get the token from https://faucet.sui.io/?network=testnet
# Get remaining gas
sui client gas
# Get the current coin (Merge all the objects)
sui client balance
# Publish program
sui client publish --gas-budget 30000000 --skip-dependency-verification
# Check the result on https://testnet.suivision.xyz/
# or view the current object
sui client objects --json
# Call the function in the contract
sui client call --package your_pkg_id --gas-budget 300000000 --module your_module --function your_function
sui client call --package your_pkg_id --gas-budget 300000000 --module your_module --function your_function --args <arg1> <arg2> ...
```

## Note

* If you want to pass an object type that generated from other contract as an argument, you need to put the package ID on the `published-at` and `[address]` field.
