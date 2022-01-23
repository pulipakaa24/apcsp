L = []
for i in range(int(input("Number of terms in list:"))):
    L.append(int(input("Term " + str(i) + ":")))


# my rendition of merge sort in python
def mergeSort(list1):
    outList = []
    length = len(list1)
    mid_index = length // 2
    left_half = list1[:mid_index]
    right_half = list1[mid_index:]
    if len(left_half) > 1:
        left_half = mergeSort(left_half)

    if len(right_half) > 1:
        right_half = mergeSort(right_half)

    for i in range(len(list1)):
        if len(left_half) != 0 and len(right_half) != 0:
            if left_half[0] < right_half[0]:
                outList.append(left_half[0])
                left_half.pop(0)
            else:
                outList.append(right_half[0])
                right_half.pop(0)

        else:
            outList.extend(left_half)
            outList.extend(right_half)
            break

    return outList


print("Sorted: " + str(mergeSort(L)))


def binarySearch(sortedlist, target):
    midIndex = len(sortedlist) // 2
    if len(sortedlist) > 1:
        if sortedlist[0] <= target <= sortedlist[midIndex - 1]:
            return binarySearch(sortedlist[:midIndex], target)

        else:
            var = binarySearch(sortedlist[midIndex:], target)
            if var == -1:
                return var

            return var + midIndex

    if target == sortedlist[0]:
        return 0

    return -1


print(binarySearch(mergeSort(L), int(input("Number to search position: "))))
