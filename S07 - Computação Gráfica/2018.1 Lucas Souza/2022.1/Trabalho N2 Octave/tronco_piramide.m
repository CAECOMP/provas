clear all; close all; clc;

grid_x = 0:2:6;
grid_y = 0:1:6;
grid_z = 0:3:6';

[x, y, z]=meshgrid(grid_x, grid_y, grid_z);

global tronco_piramide_v;

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

function scale_tronco_piramide(scale)
  global tronco_piramide_v;

  aux_tronco_piramide = scale*tronco_piramide_v'
  tronco_piramide_v = aux_tronco_piramide'
  evalin('base','tronco_piramide_v=tronco_piramide_v;');
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


#main
define_tronco_piramide(4, 2, 3)

#scale = [2 0 0; 0 2 0; 0 0 2]
#scale_tronco_piramide(scale);
#translate_tronco_piramide(2, 2, 2)

plot_cube(tronco_piramide_v)


xlabel('x'), ylabel('y'), zlabel('z')
view(3)
axis vis3d
