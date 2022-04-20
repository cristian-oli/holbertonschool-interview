#!/usr/bin/python3
"""Module for function canUnlockAll"""


from distutils.log import FATAL


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    keys = {}
    for i in range(len(boxes)):
        if (i == 0):
            keys[i] = True
            continue
        keys[i] = False

    for box_index in range(len(boxes)):
        for key_index in range(len(boxes[box_index])):
            if boxes[box_index][key_index] == box_index:
                continue
            if boxes[box_index][key_index] in keys:
                keys[boxes[box_index][key_index]] = True

    for i in keys.values():
        if i is False:
            return False
    return True
