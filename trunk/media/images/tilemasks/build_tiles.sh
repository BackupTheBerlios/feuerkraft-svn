#!/bin/sh

mkdir -p tiles

for i in masks/*.png; do
    echo $i
    NAME=$(basename $i)
    NAME=${NAME%%.png}
    ./apply_alpha.py grass.png    "$i" "tiles/$(echo "$NAME" | tr [bw] [g_]).png"
    ./apply_alpha.py mud.png      "$i" "tiles/$(echo "$NAME" | tr [bw] [m_]).png"
    ./apply_alpha.py darksand.png "$i" "tiles/$(echo "$NAME" | tr [bw] [d_]).png"
done

# EOF #