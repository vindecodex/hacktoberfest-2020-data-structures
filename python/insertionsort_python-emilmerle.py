def insertion_sort(lst):
    j = 0
    while j != len(lst):
        key = lst[j]
        k = j-1
        while k >= 0 and lst[k] > key:
            lst[k+1] = lst[k]
            k = k-1
        lst[k+1] = key
        j = j+1
    return lst