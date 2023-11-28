#!/usr/bin/python3

import click

@click.command()
@click.option("--count", default=1, help="Number of greetings.")
@click.option("--name", prompt="Your name", help="The person to greet.")
@click.version_option("1.0.0")
def main(count, name):
    print("Hi "+name)

if __name__ == '__main__':
    main()

