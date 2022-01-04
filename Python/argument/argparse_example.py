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

# usage: argparse_example.py [-h] [-v] [-o OUTPUT] cmd ...
# 
# Argument Test Example
# 
# positional arguments:
#   cmd                   Functions
#     list                List all items
#     project             Related to project
# 
# optional arguments:
#   -h, --help            show this help message and exit
#   -v, --version         show program's version number and exit
#   -o OUTPUT, --output OUTPUT
#                         Output result
def _subcmd_parser(): 
    main_parser = argparse.ArgumentParser(description="Argument Test Example")
    main_parser.add_argument('-v', '--version', action='version', version=VERSION_STR)
    main_parser.add_argument('-o', '--output', type=str, help="Output result")
    cmd_parser = main_parser.add_subparsers(dest='cmd', metavar='cmd', required=True, help="Functions")

    # list
    list_parser = cmd_parser.add_parser('list', help="List all items")
    list_parser.add_argument('path', metavar='PATH', help="Where the path")
    list_parser.add_argument('-n', type=int, help='MAX item number')

    # project
    project_parser = cmd_parser.add_parser('project', help="Related to project")
    project_subparser = project_parser.add_subparsers(dest='subcmd', metavar='subcmd', required=True, help="Functions")
    prj_create_parser = project_subparser.add_parser('create', help="create project")
    prj_create_parser.add_argument('project', metavar='PROJ', help="Your project name")
    prj_delete_parser = project_subparser.add_parser('delete', help="delete project")
    prj_delete_parser.add_argument('project', metavar='PROJ', help="Your project name")

    args = main_parser.parse_args()
    if args.output != None:
        print("Output content will be in %s" % args.output)
    if args.cmd == "list":
        print("list: "+args.path)
        if args.n:
            print("      n=%d" % args.n)
    elif args.cmd == "project":
        print("project subcmd: "+args.subcmd)
        print("project name: "+args.project)
    return args

def main():
    # Parse argument
    #args = _simple_parser()
    args = _subcmd_parser()
    # Do what you want to do


if __name__ == '__main__':
    main()
