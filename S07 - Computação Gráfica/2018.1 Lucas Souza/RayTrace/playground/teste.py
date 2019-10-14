import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from copy import deepcopy as dp
from src import raytrace_
from src import Sphere
# origem = [5,5,5]
# l = -10
# r = 10
# t = 10
# b = -10
# nx = 120
# ny = 120
# distance = 0.1
#
# raytrace_.sphere_detection_in_oblique_case(name="0.2")
# raytrace_.sphere_detection_in_oblique_case(distance=distance,name="0.1")



retaA = [[0, 0, 0.2], [0, 0.2,  0]]
retaB = [[0, 0, 0.2], [0, 0.2,0.1]]


fig = plt.figure()
ax = fig.gca(projection='3d')


ax.quiver(retaA[0][0], retaA[0][1], retaA[0][2], retaA[1][0], retaA[1][1], retaA[1][2])
ax.quiver(retaB[0][0], retaB[0][1], retaB[0][2], retaB[1][0], retaB[1][1], retaB[1][2])
# ax.quiver(reta[2][0], reta[2][1], reta[2][2], reta[0][0], reta[0][1], reta[0][2])
# ax.quiver(poligon[3][0],poligon[3][1],poligon[3][2],poligon[0][0],poligon[0][1],poligon[0][2])
plt.show()


















