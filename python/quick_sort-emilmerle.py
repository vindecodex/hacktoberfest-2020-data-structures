def quicksort_rand_pivot(lst):
    from random import randint
    if len(lst) <= 1:
        return lst
    else:
        p = randint(0, len(lst)-1)
        left = []
        right = []
        for e in lst:
            if e <= lst[p]:
                left.append(e)
            else:
                right.append(e)
        return quicksort_rand_pivot(left) + quicksort_rand_pivot(right)
