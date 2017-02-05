#!/bin/bash
cut -d, -f1,5-6,8-10,12-19,22-41 --complement $1 > $2

