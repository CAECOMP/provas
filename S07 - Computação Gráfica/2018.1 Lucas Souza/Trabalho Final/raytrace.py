import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from copy import deepcopy as dp
import cv2
from random import randint

#IMPORTANTS
#1 - Refactorings
#1A - OOP implements will need for a reading and reduce code complexity
#1A - Objects :
        # Sphere{center,radius}
        # Poligon{points}
        # Triangle{points}

def compute_vector_w(origin):
    vector_w = []
    norm_origin = np.linalg.norm(origin);
    for i in origin:
        vector_w.append(i/norm_origin);
    return vector_w

def compute_vector_u(vector_w):
    vector_u = []
    vector_t = compute_vector_t(vector_w)
    cross_w_and_t = np.cross(vector_w,vector_t)
    norm_cross_w_and_t = np.linalg.norm(cross_w_and_t)
    for i in cross_w_and_t:
        vector_u.append (i / norm_cross_w_and_t );
    return vector_u

def compute_vector_v(vector_w,vector_u):
    vector_v = []
    cross_w_and_u = np.cross (vector_w, vector_u)
    for i in cross_w_and_u:
        vector_v.append (i);
    return vector_v

def compute_vector_t(vector_w):
    index_min_value = vector_w.index(min(np.abs(vector_w)))
    vector_temp = dp(vector_w)
    if(vector_temp[index_min_value] == 1 ):
        vector_temp[index_min_value] = 0
    else:
        vector_temp[index_min_value] = 1
    return vector_temp

def compute_vectors_wuv(origin):
    vector_w = compute_vector_w (origin)
    vector_u = compute_vector_u (vector_w)
    vector_v = compute_vector_v (vector_w, vector_u)
    return vector_w,vector_u,vector_v

def compute_escalar_ul(indexX,left,right,nx):
    ul = left + (right - left)*(indexX + 0.5)/nx
    return ul

def compute_escalar_vl(indexY,top,bottom,ny):
    vl = bottom + (top - bottom)*(indexY + 0.5)/ny
    return vl

def compute_directions(origin,distance,left,right,top,bottom,nx,ny):
    directions = []
    # vector_w, vector_u, vector_v = compute_vectors_wuv (origin)
    for i in range(nx):
        for j in range(ny):
            direction = compute_direction(i,j,origin,distance,left,right,top,bottom,nx,ny)
            directions.append(direction)
    return directions

def compute_direction(x,y,origin,distance,left,right,top,bottom,nx,ny):
    vector_w, vector_u, vector_v = compute_vectors_wuv (origin)
    ul = compute_escalar_ul(x, left, right, nx)
    vl = compute_escalar_vl(y, top, bottom, ny)
    return (np.dot(distance,vector_w) + np.dot(ul,vector_u) + np.dot(vl,vector_v))


def solve_quadratic_equation(A,B,C):
    delta = B**2 - 4 * A * C
    t1 = t2 = ""
    if delta >= 0:
        t1 = (-B - delta**0.5)/A
        t2 = (-B + delta**0.5)/A
    return delta,t1,t2


def compute_circle(origin,direction,center_circle,radius):
    eminusc = np.subtract(origin,center_circle)
    dot_dir_dir = np.dot(direction,direction)
    dot_dir_eminusc = np.dot(direction,eminusc)
    dot_eminusc_eminusc = np.dot(eminusc,eminusc) - pow(radius,2)
    return solve_quadratic_equation(dot_dir_dir,dot_dir_eminusc,dot_eminusc_eminusc)

def sphere_detection_in_oblique_case(origem=[5,5,5],distance=0.2,sphere_center=[0,0,0],radius=8,left=-10,right=10,bottom=-10,top=10,nx=200,ny=200):
    imagem = np.zeros ((nx, ny, 3), dtype=int)
    # cv2.imwrite ("sphere_detection.jpg", imagem)
    for x in range (0, imagem.shape[0]):
        for y in range (0, imagem.shape[1]):
            direction = (compute_direction (x, y, origem, -1 / distance, left, right, top, bottom, nx, ny))
            # <modify for a variable sphere quantity>
            # vetorize spheres objects -> iterate sphere array ->compute delta value
            delta, t1, t2 = compute_circle(origem, direction,sphere_center , radius)
            # <end of modify/>
            print ("passando =[{x}][{y}]".format (x=x, y=y), end="")
            print (" - delta = " + str (delta))
            if delta >= 0:
                imagem[x][y] = [0, 255, 255]
    text = 'Sphere Detection'
    font = cv2.FONT_HERSHEY_SIMPLEX
    cv2.putText (imagem, text, (5, ny - 5), font, 0.2, (255, 255, 255), 1, cv2.LINE_AA)
    cv2.imwrite ("sphere_detection.jpg", imagem)

def multiple_sphere_detection_in_oblique_case():
    print("not implemented function...")


def poligon_detection():
    print("not implemented function...")


def triangle_detection():
    print("not implemented function...")





















