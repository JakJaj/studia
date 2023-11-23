def search(nums, target):
    left = 0
    right = len(nums)
    if target > nums[right - 1] or target < nums[left]:
        return -1

    while left <= right:
        mid = left + (right - left) // 2
        
        if nums[mid] == target:
            return mid
        elif target > nums[mid]:
            left = mid + 1
        elif target < nums[mid]:
            right = mid - 1
        
    return -1
            
lista = [-1,0,3,5,9,12]

print(search(lista,9))
print(search(lista,5))
print(search(lista,8))
print(search(lista,13))
print(search(lista,-3))