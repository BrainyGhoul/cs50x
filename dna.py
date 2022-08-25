import csv
from sys import argv
import re
import cs50

if (len(argv) != 3):
    print("na... that ain't gonna work out between you and me")
    exit(1)
csv_name = argv[1]
sequence_name = argv[2]
str_samples = []
str_occurences = []


csv_file = open(csv_name, "r")

reader = csv.reader(csv_file)
for i in next(reader):
    if i != "name":
        str_samples.append(i)


with open(sequence_name, "r") as file:
    text = file.read()
    for num in range(len(str_samples)):
        string = str_samples[num]
        longest = 0

        for i in range(len(text)):
            temp = 0
            if text[i:i + len(string)] == string:
                temp_num = i

                while True:
                    if text[temp_num: temp_num + len(string)] == string:
                        temp += 1
                        temp_num += len(string)
                    else:
                        break

            if temp > longest:
                longest = temp
        str_occurences.append(str(longest))


for i in reader:
    person = i.pop(0)
    match = True
    for j, v in enumerate(i):
        if v != str_occurences[j]:
            match = False

    if match == True:
        print(person)
        exit(0)


print("No match")