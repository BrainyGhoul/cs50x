import re


string = "abcd;4asdfasdf"

tav = re.findall(r"(\w)\1", string)
print(tav)

for i in tav:
    print(i)