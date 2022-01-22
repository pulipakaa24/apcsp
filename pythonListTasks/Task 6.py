list1 = [10, 20, 30, 40]
list2 = [100, 200, 300, 400]

for i in range(len(list1)):
    print(list1[i], end=" ")
    print(list2[-(i + 1)])
