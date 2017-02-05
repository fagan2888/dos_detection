import csv
import sys

with open(sys.argv[1], 'rb') as inp, open(sys.argv[2], 'wb') as out:
    writer = csv.writer(out)
    for row in csv.reader(inp):
        if (row[41] == "normal." or row[41] == "land." or row[41] == "back." or row[41] == "neptune." or
		row[41] == "pod." or row[41] == "smurf." or row[41] == "teardrop."):
            writer.writerow(row)
