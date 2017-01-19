def rbinsearch(array, key, first, last):
    if first <= last:
        mid = (first+last)/2
        if array[mid] > key:
            return rbinsearch(array, key, first, mid-1)
        elif array[mid] < key:
            return rbinsearch(array, key, mid+1, last)
        else:
            return mid
