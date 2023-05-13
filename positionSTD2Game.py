#!/usr/bin/env python3

import sys

if len(sys.argv) != 2:
    print("Error: debes proporcionar un argumento.")
    sys.exit(1)

param = sys.argv[1]

def std2game():
    returnValue = "("
    if(param[0].islower()):
        returnValue += str(ord(param[0]) - 96 - 1)
        
    else:
        returnValue += str(ord(param[0]) - 64 - 1)
    returnValue += ","
    returnValue += str(abs(int(param[1]) - 8))
    returnValue += ")"
    return returnValue

def game2std():
    returnValue = "("
    returnValue += chr(97 + int(param[0]))
    returnValue += ","
    returnValue += str(8 - int(param[1]))
    returnValue += ")"
    return returnValue


if(param[0].isalpha()):
    print(std2game())
else:
    print(game2std())





#def game2std():

