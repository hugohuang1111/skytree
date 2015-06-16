#!/usr/bin/env python
#coding=utf-8

import sys
import traceback
from argparse import ArgumentParser

def main():
    parser = ArgumentParser(description="Skytree console handler.")
    parser.add_argument('--new-class', dest='new_class', help='create class file')

    (args, unknown) = parser.parse_known_args()

    if len(unknown) > 0:
        print("unknown arguments: %s" % unknown)
        return

    if args.new_class:
        from mod.NewClass import NewClass
        new_class = NewClass(args.new_class)
        new_class.gen()


# -------------- main --------------
if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        traceback.print_exc()
        sys.exit(1)

