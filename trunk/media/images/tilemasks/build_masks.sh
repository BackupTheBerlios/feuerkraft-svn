#!/bin/sh

BUILDDIR="masks"

mkdir -p "${BUILDDIR}"

IMAGICKFLAGS="-type Grayscale"

# flop == "horizontal flip"

# upper/left
for i in 1000-*.png; do
    echo $i
    EXT="${i##1000-}"

    # single spot
    convert $IMAGICKFLAGS             "$i" "${BUILDDIR}/1000-${EXT}"
    convert $IMAGICKFLAGS -flop       "$i" "${BUILDDIR}/0100-${EXT}"
    convert $IMAGICKFLAGS -flip       "$i" "${BUILDDIR}/0001-${EXT}"
    convert $IMAGICKFLAGS -flip -flop "$i" "${BUILDDIR}/0010-${EXT}"

    # three spot
    convert $IMAGICKFLAGS -negate             "$i" "${BUILDDIR}/0111-${EXT}"
    convert $IMAGICKFLAGS -negate -flop       "$i" "${BUILDDIR}/1011-${EXT}"
    convert $IMAGICKFLAGS -negate -flip       "$i" "${BUILDDIR}/1110-${EXT}"
    convert $IMAGICKFLAGS -negate -flip -flop "$i" "${BUILDDIR}/1101-${EXT}"
done

# diagonal
for i in 1010-*.png; do
    echo $i
    EXT="${i##1010-}"
    convert $IMAGICKFLAGS         "$i" "${BUILDDIR}/1010-${EXT}"
    convert $IMAGICKFLAGS -negate "$i" "${BUILDDIR}/0101-${EXT}"
done

# one side
for i in 1100-*.png; do
    echo $i
    EXT="${i##1100-}"
    convert $IMAGICKFLAGS             "$i" "${BUILDDIR}/1100-${EXT}"
    convert $IMAGICKFLAGS -flip       "$i" "${BUILDDIR}/0011-${EXT}"
    convert $IMAGICKFLAGS -transpose  "$i" "${BUILDDIR}/1001-${EXT}"
    convert $IMAGICKFLAGS -transverse "$i" "${BUILDDIR}/0110-${EXT}"
done

# EOF #

