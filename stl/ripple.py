import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-1, 1, 50)
y = np.linspace(-1, 1, 50)
x, y = np.meshgrid(x, y)
z = np.sin(np.sqrt(x**2 + y**2) * 12) / 12

def vec(i, j):
    print x[i, j], y[i, j], z[i, j]

for i in range(49):
    for j in range(49):
        #upper left triangle
        vec(i, j)
        vec(i+1, j)
        vec(i, j+1)
        
        #lower right triangle
        vec(i+1, j)
        vec(i+1, j+1)
        vec(i, j+1)
