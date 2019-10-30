import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from copy import deepcopy as dp
from src import raytrace_


origem = [1,1,1]
l = 10
r = 5
t = 10
b = 5
nx = 5
ny = 5
distance = 1

fig = plt.figure()
ax = fig.gca(projection='3d')

directions = raytrace_.compute_directions(origem, distance, l, r, t, b, nx, ny)
# ax.quiver(0, 0, 0, 1, 1, 1, normalize=True)
origem = np.dot(raytrace_.compute_vector_w(origem),-1)

for i in directions:
    ax.quiver(origem[0],origem[1],origem[2],i[2],i[1],i[0])
plt.show()
