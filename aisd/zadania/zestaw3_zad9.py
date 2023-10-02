
def minumum_dziel_rzadz(n, index, dlu):
    min = 0
    #dzielenie na podlisty
    if dlu == 1 :
        return n[index]
    if index >= dlu - 2:
        if n[index] < n[index + 1]:
            return n[index]
        else:
            return n[index + 1]
  
    
    min = minumum_dziel_rzadz(n, index + 1, dlu)
    #znajdowanie minimum z podlist
    if n[index] < min:
        return n[index]
    else:
        return min

arr = [12,43,62,12,32,61,3,21]

print(minumum_dziel_rzadz(arr,0,len(arr)))