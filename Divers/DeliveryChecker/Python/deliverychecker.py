#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
import os
import ast
import json


def main(argv):
    # Parsing input to list
    addrs = ast.literal_eval(argv[0])
    path = ast.literal_eval(argv[1])

    # Initialize variables
    error = False
    returnValue = {}
    # Build steps dictionary with address correspond with path
    steps = [{'address': path[index], 'action':None}
             for index in range(len(path))]
    # Iterate through each addr in addrs
    for pickAddr, dropAddr in addrs:
        # Get index of pickup and dropoff point in path
        try:
            indexPick = path.index(pickAddr)
            indexDrop = path.index(dropAddr)
        except ValueError:
            error = True
            returnValue = buildErrorJSON_addrNotFound()
            break
        if (indexPick >= indexDrop):
            error = True
            returnValue = buildErrorJSON_dropBeforePick(
                pickAddr, dropAddr, returnValue.get('error_message'))
        else:
            if (error == False):
                steps[indexPick]["action"] = "pickup"
                steps[indexDrop]["action"] = "dropoff"

    if (error == False):
        returnValue = buildSuccessJSON(steps)
    returnJson = json.dumps(returnValue)
    print(returnJson)


def buildErrorJSON_addrNotFound():
    returnJSON = {}
    returnJSON['status'] = 'error'
    returnJSON['error_code'] = 'delivery_address_not_in_path'
    returnJSON['error_message'] = '...'
    return returnJSON


def buildErrorJSON_dropBeforePick(pickAddr, dropAddr, errorMsg):
    if (errorMsg == None):
        errorMsg = ''
    returnJSON = {}
    returnJSON['status'] = 'error'
    returnJSON['error_code'] = 'delivery_dropoff_before_pickup'
    returnJSON['error_message'] = errorMsg + \
        'Passing to address dropoff ' + str(dropAddr) + \
        ' before pickup in '+str(pickAddr) + '\n'
    return returnJSON


def buildSuccessJSON(steps):
    returnJSON = {}
    returnJSON['status'] = 'success'
    returnJSON['steps'] = steps
    return returnJSON


if __name__ == '__main__':
    main(sys.argv[1:])
