#!/usr/bin/env python

from PIL import Image
import sys

def main(args):
    if len(args) != 3:
        print "Usage: apply_alpah.py IN MASK OUT"
    else:
        img  = Image.open(args[0])
        mask = Image.open(args[1])
        img.putalpha(mask)
        img.save(args[2])

if __name__ == "__main__":
    main(sys.argv[1:])

# EOF #
