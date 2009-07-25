#!/bin/sh

BUILDDIR="masks"

# flop == "horizontal flip"

for i in bbwb*.png; do
    cp "$i" "${BUILDDIR}/$i"
    convert -flop "$i" "${BUILDDIR}/bbbw${i##bbwb}"
    convert -flip "$i" "${BUILDDIR}/bwbb${i##bbwb}"
    convert -flip -flop "$i" "${BUILDDIR}/wbbb${i##bbwb}"
done

for i in bwbw*.png; do
    cp "$i" "${BUILDDIR}/$i"
    convert -flip "$i" "${BUILDDIR}/wbwb${i##bwbw}"
done

for i in bbww*.png; do
    cp "$i" "${BUILDDIR}/$i"
    convert -flip "$i" "${BUILDDIR}/wwbb${i##bbww}"
    convert -transpose  "$i" "${BUILDDIR}/bwwb${i##bbww}"
    convert -transverse "$i" "${BUILDDIR}/wbbw${i##bbww}"
done


for i in bwww*.png; do
    cp "$i" "${BUILDDIR}/$i"
    convert -flip "$i" "${BUILDDIR}/wwwb${i##bwww}"
    convert -flop "$i" "${BUILDDIR}/wbww${i##bwww}"
    convert -transverse "$i" "${BUILDDIR}/wwbw${i##bwww}"
done

# EOF #

