import random

rand_num = random.randint(1, 8)

if rand_num == 1 or rand_num == 2:
    print("Your language is C")
elif rand_num == 3 or rand_num == 4 or rand_num == 5:
    print("Your language is C++")
elif rand_num == 6 or rand_num == 7:
    print("Your language is Java")
else:
    print("Your language is Python")
