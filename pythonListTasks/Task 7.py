list1 = ["M", "na", "i", "Ke"]
list2 = ["y", "me", "s", "lly"]

iternum = min(len(list1), len(list2))
list3 = []

for i in range(iternum):
    list3.append(list1[0] + list2[0])
    list1.pop(0)
    list2.pop(0)

for i in list1:
    list3.append(i)

for i in list2:
    list3.append(i)

print(list3)
