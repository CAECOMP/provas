clear all; close all; clc;
grid_x = 0:2:6;
grid_y = 0:1:6;
grid_z = 0:3:6';

[x, y, z]=meshgrid(grid_x, grid_y, grid_z);

# Variáveis globais
global pyramid_v;
global cube_v;
global paralelepipedo_v;
global tronco_piramide_v;
global steps = [1:1:4];

# Definindo sólidos
# Piramide
function define_pyramid(centroX,centroY,centroZ,largura_base_quadrada,altura)
  global pyramid_v;
  global pyramid_f;

  xFace1 = [centroX - largura_base_quadrada; centroX + largura_base_quadrada; centroX];
  yFace1 = [centroY - largura_base_quadrada; centroY - largura_base_quadrada; centroY];
  zFace1 = [centroZ; centroZ; centroZ + altura];

  xFace2 = cos(pi/2) * (xFace1 - centroX) - sin(pi/2) * (yFace1 - centroY) + centroX;
  yFace2 = sin(pi/2) * (xFace1 - centroX) + cos(pi/2) * (yFace1 - centroY) + centroY;
  zFace2 = zFace1;

  xFace3 = cos(pi) * (xFace1 - centroX) - sin(pi) * (yFace1 - centroY) + centroX;
  yFace3 = sin(pi) * (xFace1 - centroX) + cos(pi) * (yFace1 - centroY) + centroY;
  zFace3 = zFace1;

  xFace4 = cos(pi + pi/2) * (xFace1 - centroX) - sin(pi + pi/2) * (yFace1 - centroY) + centroX;
  yFace4 = sin(pi + pi/2) * (xFace1 - centroX) + cos(pi + pi/2) * (yFace1 - centroY) + centroY;
  zFace4 = zFace1;

  pyramid_v = [xFace1 yFace1 zFace1; xFace2 yFace2 zFace2; xFace3 yFace3 zFace3; xFace4 yFace4 zFace4];
endfunction

#Cubo
function define_cube(side)
  l = side/2
  global cube_v;

  cube_v = [
  -l -l -l;
  l -l -l;
  l l -l;
  -l l -l;
  -l -l l;
  l -l l;
  l l l;
  -l l l
  ]
  evalin('base','cube_v=cube_v;');
endfunction

#Paralelepipedo
function define_paralelepipedo(lado_x, lado_y, lado_z)
  global paralelepipedo_v;
   paralelepipedo_v = [
   0 0 0;
   lado_x 0 0;
   lado_x lado_y 0;
   0 lado_y 0;
   0 0 lado_z;
   lado_x 0 lado_z;
   lado_x lado_y lado_z;
   0 lado_y lado_z
  ];
  evalin('base','paralelepipedo_v=paralelepipedo_v;');
endfunction

# Tronco Piramide
function [] = define_tronco_piramide(base_maior, base_menor, altura)
  global tronco_piramide_v;
  bm_posicao_0 = base_menor/2
  bm_posicao_1 = base_menor + bm_posicao_0

 tronco_piramide_v = [
   0 0 0;
   base_maior 0 0;
   base_maior base_maior 0;
   0 base_maior 0;
   bm_posicao_0 bm_posicao_0 altura;
   bm_posicao_1 bm_posicao_0 altura;
   bm_posicao_1 bm_posicao_1 altura;
   bm_posicao_0 bm_posicao_1 altura
  ];
  evalin('base','tronco_piramide_v=tronco_piramide_v;');
endfunction

# Escalando sólidos

function scale_pyramid(scale)
  global pyramid_v;

  aux_pyramid = scale*pyramid_v'
  pyramid_v = aux_pyramid'
  evalin('base','pyramid_v=pyramid_v;');
endfunction

function scale_cube(scale)
  global cube_v;

  aux_cube = scale*cube_v'
  cube_v = aux_cube'
  evalin('base','cube_v=cube_v;');
endfunction

function scale_paralelepipedo(scale)
  global paralelepipedo_v;

  aux_paralelepipedo = scale*paralelepipedo_v'
  paralelepipedo_v = aux_paralelepipedo'
  evalin('base','paralelepipedo_v=paralelepipedo_v;');
endfunction

function scale_tronco_piramide(scale)
  global tronco_piramide_v;

  aux_tronco_piramide = scale*tronco_piramide_v'
  tronco_piramide_v = aux_tronco_piramide'
  evalin('base','tronco_piramide_v=tronco_piramide_v;');
endfunction

# Transladando sólidos

function translate_pyramid(x, y, z)
  global pyramid_v;
  matriz = [pyramid_v'; ones(1,12)]
  m_translate = [1 0 0 x; 0 1 0 y;0 0 1 z; 0 0 0 1 ]
  aux_pyramid = m_translate*matriz
  aux_pyramid = aux_pyramid'
  aux_pyramid(:,4) = []

  pyramid_v = aux_pyramid
  evalin('base','pyramid_v=pyramid_v;');
endfunction

function translate_cube(x, y, z)
  global cube_v;
  matriz = [cube_v'; ones(1,8)]
  m_translate = [1 0 0 x; 0 1 0 y;0 0 1 z; 0 0 0 1 ]
  aux_cube = m_translate*matriz
  aux_cube = aux_cube'
  aux_cube(:,4) = []

  cube_v = aux_cube
  evalin('base','cube_v=cube_v;');
endfunction

function translate_paralelepipedo(x, y, z)
  global paralelepipedo_v;
  matriz = [paralelepipedo_v'; ones(1,8)]
  m_translate = [1 0 0 x; 0 1 0 y;0 0 1 z; 0 0 0 1 ]
  aux_paralelepipedo = m_translate*matriz
  aux_paralelepipedo = aux_paralelepipedo'
  aux_paralelepipedo(:,4) = []

  paralelepipedo_v = aux_paralelepipedo
  evalin('base','paralelepipedo_v=paralelepipedo_v;');
endfunction

function translate_tronco_piramide(x, y, z)
  global tronco_piramide_v;
  matriz = [tronco_piramide_v'; ones(1,8)]
  m_translate = [1 0 0 x; 0 1 0 y;0 0 1 z; 0 0 0 1 ]
  aux_tronco_piramide = m_translate*matriz
  aux_tronco_piramide = aux_tronco_piramide'
  aux_tronco_piramide(:,4) = []

  tronco_piramide_v = aux_tronco_piramide
  evalin('base','tronco_piramide_v=tronco_piramide_v;');
endfunction

# Plotando sólidos

function [] = plotPyramid(pyramidVertices)
  pyramid_f = [1 2 3;4 5 6; 7 8 9;10 11 12];
  patch('Vertices',pyramidVertices,'Faces',pyramid_f,'FaceColor','g');
endfunction

function plot_cube(cube)
  cube_faces = [
  1 2 6 5;
  2 3 7 6;
  3 4 8 7;
  4 1 5 8;
  1 2 3 4;
  5 6 7 8
  ];

  patch('Vertices',cube,'Faces',cube_faces,...
      'FaceVertexCData',hsv(6),'FaceColor','flat')
endfunction


# main
figure(1), clf, hold on
xlabel('x'), ylabel('y'), zlabel('z');
axis square

# definindo sólidos
define_pyramid(0,0,0,3,4);
define_cube(2.5);
define_paralelepipedo(2, 3, 4)
define_tronco_piramide(4, 2, 3)

# Escalando sólidos
scale = [0.5 0 0; 0 0.5 0; 0 0 0.5]

scale_pyramid(scale)
scale_cube(scale)
scale_paralelepipedo(scale)
scale_tronco_piramide(scale);

#Transladando sólidos
translate_pyramid(3, 4, 0)
translate_cube(3, 1, 0.5);
translate_paralelepipedo(-3, 0, 0)
translate_tronco_piramide(-6, 0, 0)

# Plotando sólidos
plotPyramid(pyramid_v);
plot_cube(cube_v);
plot_cube(paralelepipedo_v);
plot_cube(tronco_piramide_v)

rotate3d on






