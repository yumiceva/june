
import csv

nlines = 0
with open('datasets.csv') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=',')
    if nlines == 0: next(csvfile)

    #print spamreader
    for row in spamreader:
        print(', '.join(row))

    nlines = nlines+1
