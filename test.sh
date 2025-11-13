#!/bin/sh

maps=$(find ./cub_maps/invalid -type f -name '*.cub')
validmaps=$(find ./cub_maps/valid -type f -name '*.cub')

for map in $maps; do
echo "Testing: <$map>"
./cub3d $map
echo
done
