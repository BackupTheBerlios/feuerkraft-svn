#!/bin/bash

mkdir -p tiles

# a=asphalt
# d=darkwater
# w=darksand/wetsand
# g=grass
# m=mud
# f=water
# s=sand
# i=snow

for i in masks/*.png; do
    echo $i
    NAME=$(basename $i)
    NUM="${NAME:5:1}"
    NAME="${NAME:0:4}"
    ./apply_alpha.py grass.png      "$i" "tiles/$(echo "$NAME" | tr [10] [g_])-${NUM}.png"
    ./apply_alpha.py mud.png        "$i" "tiles/$(echo "$NAME" | tr [10] [m_])-${NUM}.png"
    ./apply_alpha.py darksand.png   "$i" "tiles/$(echo "$NAME" | tr [10] [w_])-${NUM}.png"
    ./apply_alpha.py water.png      "$i" "tiles/$(echo "$NAME" | tr [10] [f_])-${NUM}.png"
    ./apply_alpha.py darkwater.png  "$i" "tiles/$(echo "$NAME" | tr [10] [d_])-${NUM}.png"
    ./apply_alpha.py asphalt.png    "$i" "tiles/$(echo "$NAME" | tr [10] [a_])-${NUM}.png"
done

# EOF #
