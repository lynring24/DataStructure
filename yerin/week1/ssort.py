def selectionsort(list):
    for i in range(len(list)-1,0,-1):
        maxi = 0
        for index in range(1,i+1):
            if list[index] > list[maxi]:
                maxi = index
        temp = list[i]
        list[i] = list[maxi]
        list[maxi] = temp
    return list
