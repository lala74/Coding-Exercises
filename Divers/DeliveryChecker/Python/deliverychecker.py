#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import ast
import json


def position_of_addr_in_path(addr, path):
    # return index of the address in path
    try:
        index = path.index(addr)
        return index
    except ValueError:
        return -1


def check_dropoff_before_pickup(posAddrs, addrs):
    errorMsg = ''

    for index, val in enumerate(posAddrs):
        posSrc = val[0]
        posDst = val[1]

        if(posSrc >= posDst):
            src = addrs[index][0]
            dst = addrs[index][1]
            errorMsg += 'Passing to address dropoff ' + \
                str(dst) + ' before pickup in '+str(src) + '\n'

    return errorMsg


def build_action(posAddrs, pathLen):
    # build actionList from posAddrs
    actionList = [None] * pathLen
    for src, dst in posAddrs:
        actionList[src] = 'pickup'
        actionList[dst] = 'dropoff'

    return actionList


def build_steps(path, actionList):
    steps = []
    for index in range(len(path)):
        address = path[index]
        action = actionList[index]
        step = {"address": address, "action": action}
        steps.append(step)
    return steps


def main(argv):
    # Parsing input to list
    addrs = ast.literal_eval(argv[0])
    path = ast.literal_eval(argv[1])

    # Initialize variables
    error = False
    errorCode = ''
    errorMsg = ''
    returnValue = {}
    returnJson = None

    posAddrs = []   # index of src and dst of each address [[indexSrc, indexDst],...]
    actionList = []
    steps = []

    for src, dst in addrs:
        # Get index of src and dst in path
        posSrc = position_of_addr_in_path(src, path)
        posDst = position_of_addr_in_path(dst, path)

        if (posSrc == -1 or posDst == -1):  # src or dst are not in path
            error = True
            errorCode = "delivery_address_not_in_path"
            break
        # Build a list of all [indexSrc,indexDst]
        posAddrs.append([posSrc, posDst])

    # Check dropoff before pickup
    errorMsg = check_dropoff_before_pickup(posAddrs, addrs)
    if (errorMsg != ''):
        error = True
        errorCode = "delivery_dropoff_before_pickup"

    # If there is no error, build return json, if there is error, build error msg
    if (error == False):
        returnValue['status'] = 'success'
        actionList = build_action(posAddrs, len(path))
        steps = build_steps(path, actionList)
        returnValue['steps'] = steps
    else:
        returnValue['status'] = 'error'
        returnValue['error_code'] = errorCode
        returnValue['error_message'] = errorMsg

    returnJson = json.dumps(returnValue)
    print(returnJson)


if __name__ == '__main__':
    main(sys.argv[1:])
