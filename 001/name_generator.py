# input: nothing
# output: a single name
import random

names = ['alex', 'george', 'alvin', 'rick']

#n = random.randint(a=1, b=len(names))
n = random.randint(a=0, b=len(names)-1)

print(names[n])