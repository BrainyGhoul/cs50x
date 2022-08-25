from sys import argv
from cs50 import SQL

if len(argv) != 2:
    print("program is not gonna run without house name")
    exit(1)

house_name = argv[1]

db = SQL("sqlite:///students.db")

lst = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", (house_name))

for i in lst:
    name = filter(None, [i["first"], i["middle"], i["last"]])
    name_str = " ".join(name)

    print(f"{name_str}, born {i['birth']}")