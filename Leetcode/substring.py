def strStr(haystack, needle):

    start = -1
    length = 0
    if len(haystack) < len(needle):
        return -1
    for i in range(len(haystack)):
        if(len(haystack[i:]) < len(needle)):
            break
        
        if haystack[i] == needle[0]:
            start = i
        
        
        
            for j in range(len(needle)):
            
                if(haystack[start + j] != needle[j]):
                    break

                length += 1

        if length == len(needle):
            return start
        else:
            length = 0
                
    return -1

def strStr2(haystack, needle):
    for i in range(len(haystack) - len(needle) + 1):
        if haystack[i: i + len(needle)] == needle:
            return i
        
    return -1
    
print(strStr2("abc","c"))