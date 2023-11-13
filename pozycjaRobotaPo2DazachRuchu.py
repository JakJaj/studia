import math

PI = math.pi
cos = math.cos
sin = math.sin
R = 0.2
L = 0.3
np1 = 4 #prawe kolo 1szy impuls
np2 = 7 #prawe kolo 2gi impuls
nl1 = 7 #lewe kolo 1szy impuls
nl2 = 8 #lewe kolo 2gi impuls
fistart= 0
xst = 0
yst = 0

Dr1 = 2 * PI * R * (np1 / 40)
Dl1 = 2 * PI * R * (nl1 / 40)
Dc1 = (Dr1 + Dl1) / 2

xpr = xst + Dc1 * cos(fistart)
ypr = yst + Dc1 * sin(fistart)

fipr1 = fistart + ((Dr1 - Dl1) / L)

print("   x po pierwszym =",xpr,"    y po pierwszym = ",ypr,"    Fi po pierwszym = ",fipr1)


Dr2 = 2 * PI * R * (np2 / 40)
Dl2 = 2 * PI * R * (nl2 / 40)

Dc2 = (Dr2 + Dl2) / 2

fipr2 = fipr1 + ((Dr2 - Dl2) / L)

xkon = xpr + Dc2 * cos(fipr1)
ykon = ypr + Dc2 * sin(fipr1)
    
print("   x po drugim =",xkon,"    y po drugim = ",ykon,"    Fi po drugim = ",fipr2)
print(" X Zaokrąglenia do mm = ",round(xkon,3),"    y Zaokrąglenia do mm = ",round(ykon,3),"    Fi Zaokrąglenia do mrad = = ",round(fipr2,3))