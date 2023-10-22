import numpy as np
import matplotlib.pyplot as plt

def bresenham(xp,yp,xk,yk,data):
    assert xp < data.shape[0] and xp > 0, "Niewlasciwa wartosci x poczatkowego"
    assert xk < data.shape[0] and xk > 0, "Niewlasciwa wartosci x koncowego"
    assert yp < data.shape[0] and yp > 0, "Niewlasciwa wartosci y poczatkowego"
    assert yk < data.shape[0] and yk > 0, "Niewlasciwa wartosci y koncowego"
    
    dx = abs(xk - xp)
    
    if(xp < xk):
        przyrost_x = 1
    else:
        przyrost_x = -1
    
    dy = -1 * abs(yk - yp)
    if yp < yk:
        przyrost_y = 1
    else:
        przyrost_y = -1
        
    odchylenie_od_osi = dx + dy
    
    while True:
        data[xp,yp] = 0
        if xp == xk and yp == yk:
            break
        odchylenie_od_osi2 = 2 * odchylenie_od_osi
        
        if odchylenie_od_osi2 >= dy:
            if xp == xk:
                break
            odchylenie_od_osi = odchylenie_od_osi + dy
            xp = xp + przyrost_x
        
        if odchylenie_od_osi2 <= dx:
            if yp == yk:
                break
            odchylenie_od_osi = odchylenie_od_osi + dx
            yp = yp + przyrost_y
    
    plt.imshow(data, interpolation='none')
    plt.show()
    
data = np.zeros((100,100, 3), dtype=np.uint8)
data.fill(255)
print(data.shape)
plt.imshow(data, interpolation='none')
plt.show()


bresenham(20, 30, 70, 90,data)

bresenham(80,60, 10,20,data)

bresenham(10,60, 30,20,data)

bresenham(40,30, 20,50,data)

bresenham(90, 90, 90, 90, data)

    
