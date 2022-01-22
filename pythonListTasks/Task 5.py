list1 = ["a", "b", ["c", ["d", "e", ["f", "g"], "k"], "l"], "m", "n"]
sub_list = ["h", "i", "j"]


def repeat(list2, list3):
    for i in list2:
        if isinstance(i, list):
            repeat(i, list3)
        elif i == "g":
            list2.extend(list3)

    return list2


print(repeat(list1, sub_list))
