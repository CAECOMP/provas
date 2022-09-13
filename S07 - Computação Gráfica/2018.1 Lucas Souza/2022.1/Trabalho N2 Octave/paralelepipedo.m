clear

grid_x = 0:2:6;
grid_y = 0:1:6;
grid_z = 0:3:6;

[x, y, z]=meshgrid(grid_x, grid_y, grid_z);

global paralelepipedo_v;

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

function scale_paralelepipedo(scale)
  global paralelepipedo_v;

  aux_paralelepipedo = scale*paralelepipedo_v'
  paralelepipedo_v = aux_paralelepipedo'
  evalin('base','paralelepipedo_v=paralelepipedo_v;');
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

define_paralelepipedo(2, 3, 4)

#scale = [2 0 0; 0 2 0; 0 0 2]
#scale_paralelepipedo(scale);
#translate_paralelepipedo(2, 2, 0)

plot_cube(paralelepipedo_v)

xlabel('x'), ylabel('y'), zlabel('z')
view(3)
axis vis3d

