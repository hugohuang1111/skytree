#!/usr/bin/env python
#coding=utf-8

import os

class NewClass(object):
    """docstring for NewClass"""
    def __init__(self, arg):
        self.class_name = arg
        self.cur_dir = os.path.realpath(os.path.dirname(__file__))

    def gen(self):
        self.replace("temp.hpp")
        self.replace("temp.cpp")

    def replace(self, name):
        class_name = self.class_name
        cur_dir = self.cur_dir
        file_name = os.path.join(cur_dir, "template", name)
        f = open(file_name)
        file_content = f.read()
        f.close()
        file_content = file_content.replace("TEMP", class_name.upper())
        file_content = file_content.replace("Temp", class_name)
        file_content = file_content.replace("temp", class_name)

        new_file_name = os.path.join(cur_dir, os.path.pardir, os.path.pardir, "src", class_name + os.path.splitext(name)[1])
        f = open(new_file_name, "w")
        f.write(file_content)
        f.close()

