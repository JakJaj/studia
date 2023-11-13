import numpy

A = numpy.array([[0,1],[0,0]])
B = numpy.array([[0],[1]])
print(f"A = {A}\n")
print(f"B = {B}")

C_do_wstawienia = [numpy.array([1, -1]), numpy.array([1, 1]), numpy.array([-1, 0]), numpy.array([1, 0]), numpy.array([0, 1])]

odp = []

for i in range(len(C_do_wstawienia)):
    gora = C_do_wstawienia[i]
    dol = C_do_wstawienia[i].dot(A)
    razem = numpy.array([gora,dol])
    
    odp.append(numpy.linalg.det(razem) != 0)

odp = numpy.array(odp)
x = numpy.where(odp == False)[0] #jesli trzeba bedzie sprawdzac Obserwowalnosc zamiast NIEobserwowalnosci to z FALSE zmienic na TRUE
print(f"Uklad nieobserwowalny w odpowiedzi : {x + 1}")