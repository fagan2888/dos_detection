#!/bin/bash
cut -d, -f2-4,7,11,20,21 --complement $1 > $2

sed -i 's/normal./1/g' $2
sed -i 's/land./0/g' $2
sed -i 's/back./0/g' $2
sed -i 's/neptune./0/g' $2
sed -i 's/pod./0/g' $2
sed -i 's/smurf./0/g' $2
sed -i 's/teardrop./0/g' $2

