#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import getpass
import hashlib
import subprocess

def main(argv):
    test = True
    testString = "False"
    test = (testString == "True")
    print("test: ", test)
    print("Duc")

if __name__ == '__main__':
    main(sys.argv[1:])
