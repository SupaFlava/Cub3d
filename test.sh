#!/bin/sh

maps=$(find ./map/invalid -type f -name '*.cub')
validmaps=$(find ./map/valid -type f -name '*.cub')

for map in $maps; do
echo "Testing: <$map>"
./cub3D $map
echo
done
