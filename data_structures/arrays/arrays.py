# Lists in Python are mutable objects that may contain
# any number of items of different types
my_list = [1, "Hello", True, 3.4]

# Python allows negative indexing
my_list = [1, 2, 3, 4, 5, 6]
print(my_list[-1])

# We can access a range of items within the list using slicing
# my_list[start:stop:step]
my_list = ["H", "e", "l", "l", "o", "W", "o", "r", "l", "d"]
print(my_list[2:5])
print(my_list[5:])
print(my_list[:-2])
print(my_list[::-1])

my_list = [1, 2, 3, 4, 5]
my_list.append(6)
my_list.insert(2, 7)
print(my_list)
print(my_list.pop())
print(my_list.pop(0))
print(my_list.count(3))
