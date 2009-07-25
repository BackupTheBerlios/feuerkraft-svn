#!/bin/sh

BUILDDIR="masks"

mkdir -p "${BUILDDIR}"

# flop == "horizontal flip"

# upper/left
for i in 1000-*.png; do
    echo $i
    EXT="${i##1000-}"

    # single spot
    convert -negate "$i" "${BUILDDIR}/1000-${EXT}"
    convert -flop "$i" "${BUILDDIR}/0100-${EXT}"
    convert -flip "$i" "${BUILDDIR}/0001-${EXT}"
    convert -flip -flop "$i" "${BUILDDIR}/0010-${EXT}"

    # three spot
    convert -negate "$i" "${BUILDDIR}/0111-${EXT}"
    convert -negate -flop "$i" "${BUILDDIR}/1011-${EXT}"
    convert -negate -flip "$i" "${BUILDDIR}/1110-${EXT}"
    convert -negate -flip -flop "$i" "${BUILDDIR}/1101-${EXT}"
done

# diagonal
for i in 1010-*.png; do
    echo $i
    EXT="${i##1010-}"
    convert         "$i" "${BUILDDIR}/1010-${EXT}"
    convert -negate "$i" "${BUILDDIR}/0101-${EXT}"
done

# one side
for i in 1100-*.png; do
    echo $i
    EXT="${i##1100-}"
    convert             "$i" "${BUILDDIR}/1010-${EXT}"
    convert -flip       "$i" "${BUILDDIR}/0011-${EXT}"
    convert -transpose  "$i" "${BUILDDIR}/1010-${EXT}"
    convert -transverse "$i" "${BUILDDIR}/0101-${EXT}"
done

# EOF #

