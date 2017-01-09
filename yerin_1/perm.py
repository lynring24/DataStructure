def Permutation(s):
    if len(s) == 1:
        list = [s]
    else:
        list = []
        for i in range(len(s)):
            part = s[:i] + s[i+1:]
            for perm in Permutation(part):
                list.append(s[i:i+1] + perm)
        return list
