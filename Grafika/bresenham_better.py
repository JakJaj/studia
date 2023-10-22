import numpy as np
import matplotlib.pyplot as plt

def bresenham(xp,yp,xk,yk,data):
    assert xp < data.shape[0] and xp > 0, "Niewlasciwa wartosci x poczatkowego"
    assert xk < data.shape[0] and xk > 0, "Niewlasciwa wartosci x koncowego"
    assert yp < data.shape[1] and yp > 0, "Niewlasciwa wartosci y poczatkowego"
    assert yk < data.shape[1] and yk > 0, "Niewlasciwa wartosci y koncowego"
    
    if xp == xk and yp == yk:
        data[xp,yp] = 0
        
    if abs(yk - yp) < abs(xk - xp):
        if xp > xk:
            data = rysujWasko(xk, yk, xp, yp, data)
        else:
            data = rysujWasko(xp, yp, xk, yk, data)
    else:
        if yp > yk:
            data = rysujSzeroko(xk, yk, xp, yp, data)
        else:
            data = rysujSzeroko(xp, yp, xk, yk, data)

    plt.imshow(data, interpolation='none')
    plt.show()

def rysujWasko(xp,yp,xk,yk,data):
    dx = xk - xp
    dy = yk - yp
    yi = 1
    if dy < 0:
        yi = -1
        dy = -dy
    
    D = (2 * dy) - dx
    y = yp
    
    for x in range(xp,xk + 1):
        data[x,y] = 0
        if D > 0:
            y = y + yi
            D = D + (2 * (dy - dx))
        else:
            D = D + 2 * dy
    return data

def rysujSzeroko(xp,yp,xk,yk,data):
    dx = xk - xp
    dy = yk - yp
    xi = 1
    if dx < 0:
        xi = -1
        dx = -dx
    D = (2 * dx) - dy
    x = xp

    for y in range(yp, yk +1):
        data[x,y] = 0
        if D > 0:
            x = x + xi
            D = D + (2 * (dx - dy))
        else:
            D = D + 2*dx
    return data

data = np.zeros((100,100, 3), dtype=np.uint8)
data.fill(255)
plt.imshow(data, interpolation='none')
plt.show()

bresenham(20, 30, 70, 90,data)

bresenham(80,60, 10,20,data)

bresenham(10,60, 30,20,data) 

bresenham(40,30, 20,50,data) 

bresenham(10, 10, 10, 10, data) 