#!/usr/bin/python3

import argparse

VERSION_STR="0.9.0"

def main():
    parser = argparse.ArgumentParser(description="Argument Test Example")
    parser.add_argument('command', metavar='cmd', nargs=1,
                        help="My command")
    parser.add_argument('argument', metavar='arg', nargs='*',
                        help="Argument for each command")
    parser.add_argument('-v', '--version', action='version', version=VERSION_STR)
    # Parse argument
    args = parser.parse_args()
    # Print the output of parsing arugment
    print(args.command)
    print(args.argument)

if __name__ == '__main__':
    main()
