#!/bin/bash

mkdir -p tiles

for i in masks/*.png; do
    echo $i
    NAME=$(basename $i)
    NUM="${NAME:5:1}"
    NAME="${NAME:0:4}"
    ./apply_alpha.py grass.png    "$i" "tiles/$(echo "$NAME" | tr [10] [g_])-${NUM}.png"
    ./apply_alpha.py mud.png      "$i" "tiles/$(echo "$NAME" | tr [10] [m_])-${NUM}.png"
    ./apply_alpha.py darksand.png "$i" "tiles/$(echo "$NAME" | tr [10] [d_])-${NUM}.png"
done

# EOF #
