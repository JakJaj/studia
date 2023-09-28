with open('aip\\binarka.txt', 'wb') as plikbin:
    txt = bytes("napis, ale binarnie")
    plikbin.write(b"{txt}")

with open('aip\\binarka.txt', 'br') as pythonfile:
    pf = pythonfile.read()
print(pf)