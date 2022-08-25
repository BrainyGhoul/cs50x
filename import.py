from sys import argv
import csv
from cs50 import SQL

if len(argv) != 2:
    print("DO NOT, play around with me buddy")
    exit(1)

csv_name = argv[1]

db = SQL("sqlite:///students.db")

with open(csv_name, "r") as file:
    reader = csv.reader(file)

    next(reader)
    for row in reader:
        name = row[0].split()

        if len(name) != 3:
            name = [name[0], None, name[1]]

        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", (*name, row[1], row[2]))