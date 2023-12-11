import sys

Data = open(sys.argv[1]).read().strip()
Lines = Data.split("\n")

def p1(nums):
    if all(x == 0 for x in nums):
        return 0
    new_nums = []
    for i in range(len(nums) - 1):
        new_nums.append(nums[i + 1] - nums[i])
    return nums[-1] + p1(new_nums)

def p2(nums):
    if all(x == 0 for x in nums):
        return 0
    new_nums = []
    for i in range(len(nums) - 1):
        new_nums.append(nums[i + 1] - nums[i])
    return nums[0] - p2(new_nums)

num_list = []
part_1 = part_2 = 0
for line in Lines:
    num_list = [int(x) for x in line.split()]
    part_1 += p1(num_list)
    part_2 += p2(num_list)

print(part_1)
print(part_2)
