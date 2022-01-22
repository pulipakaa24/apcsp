list1 = [10, 20, [300, 400, [5000, 6000], 500], 30, 40]


def repeat(list2):
    for i in list2:
        if isinstance(i, list):
            repeat(i)
        elif i == 6000:
            list2.append(7000)

    return list2


print(repeat(list1))
