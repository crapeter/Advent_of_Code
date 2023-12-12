import sys

Data = open(sys.argv[1]).read().strip()
L = Data.split("\n")

Lines = [list(line) for line in L if line]
Coords = {}
EmptyRow = []
EmptyCol = []
result = 0

for r in range(len(Lines)):
    if all(char == '.' for char in Lines[r]):
        EmptyRow.append(r)
        continue
    for c in range(len(Lines[r])):
        if Lines[r][c] == '#':
            Coords[(r, c)] = True

for c in range(len(Lines)):
    empty_c = all(row[c] == '.' for row in Lines)
    if empty_c:
        EmptyCol.append(c)

# part 1
for (k, v), value in Coords.items():
    for r in range(k, len(Lines)):
        for c in range(v if r == k else 0, len(Lines[r])):
            if Lines[r][c] == '#':
                count = 0
                for t in range(min(c, v), max(c, v)):
                    count += 1 if t in EmptyCol else 0
                for t in range(min(r, k), max(r, k)):
                    count += 1 if t in EmptyRow else 0
                result += abs(r - k) + abs(c - v) + count

print(f"Part 1: {result}")

# part 2
result = 0
for (k, v), value in Coords.items():
    for r in range(k, len(Lines)):
        for c in range(v if r == k else 0, len(Lines[r])):
            if Lines[r][c] == '#':
                count = 0
                for t in range(min(c, v), max(c, v)):
                    count += 1e6 - 1 if t in EmptyCol else 0
                for t in range(min(r, k), max(r, k)):
                    count += 1e6 - 1 if t in EmptyRow else 0
                result += abs(r - k) + abs(c - v) + count

print(f"Part 2: {result}")