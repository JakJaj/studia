def addBinary(a,b):
    sum = int(a,2) + int(b,2)
    sum = bin(sum)[2:]
    return sum

print(addBinary("00","10"))

