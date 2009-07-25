#!/bin/sh

mkdir -p tiles

for i in masks/*.png; do
    echo $i
    NAME=$(basename $i)
    ./apply_alpha.py grass.png "$i" "tiles/grass_${NAME}"
    ./apply_alpha.py mud.png   "$i" "tiles/mud_${NAME}"
    ./apply_alpha.py darksand.png "$i" "tiles/darksand_${NAME}"
    # ./apply_alpha.py sand.png  "$i" "tiles/sand_${NAME}"
done

# EOF #