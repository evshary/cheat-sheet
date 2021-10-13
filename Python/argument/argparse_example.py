#!/usr/bin/python3

import argparse

VERSION_STR="0.9.0"

# usage: argparse_example.py [-h] [-v] cmd [arg [arg ...]]
# 
# Argument Test Example
# 
# positional arguments:
#   cmd            My command
#   arg            Argument for each command
# 
# optional arguments:
#   -h, --help     show this help message and exit
#   -v, --version  show program's version number and exit
def _simple_parser():
    parser = argparse.ArgumentParser(description="Argument Test Example")
    parser.add_argument('command', metavar='cmd', nargs=1,
                        help="My command")
    parser.add_argument('argument', metavar='arg', nargs='*',
                        help="Argument for each command")
    parser.add_argument('-v', '--version', action='version', version=VERSION_STR)

    args = parser.parse_args()
    # Print the output of parsing arugment
    print(args.command)
    print(args.argument)
    return args

# usage: argparse_example.py [-h] [-v] cmd ...
# 
# Argument Test Example
# 
# positional arguments:
#   cmd            The command you want
#     list         List all items
#     create       Create Parser
# 
# optional arguments:
#   -h, --help     show this help message and exit
#   -v, --version  show program's version number and exit
def _subcmd_parser(): 
    parser = argparse.ArgumentParser(description="Argument Test Example")
    parser.add_argument('-v', '--version', action='version', version=VERSION_STR)
    subcmd = parser.add_subparsers(dest='subcmd', metavar='cmd', required=True, help="The command you want")

    # list
    list_parser = subcmd.add_parser('list', help="List all items")
    list_parser.add_argument('path', metavar='PATH', help="Where the path")

    # create
    create_parser = subcmd.add_parser('create', help="Create Parser")
    create_parser.add_argument('project', metavar='PROJ', help="Your project name")
    create_parser.add_argument('-n', type=int, help='project number')

    args = parser.parse_args()
    if args.subcmd == "list":
        print("list: "+args.path)
    elif args.subcmd == "create":
        print("create: "+args.project)
        print("        n=%d" % args.n)
    return args

def main():
    # Parse argument
    #args = _simple_parser()
    args = _subcmd_parser()
    # Do what you want to do


if __name__ == '__main__':
    main()
