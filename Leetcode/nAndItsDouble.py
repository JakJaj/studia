def checkIfExist(arr):
    visited = set()
    for i in arr:
        if i * 2 in visited or i / 2 in visited:
            return True
        visited.add(i)
    return False