clear

grid_x = 0:2:6;
grid_y = 0:1:6;
grid_z = 0:3:6';

[x, y, z]=meshgrid(grid_x, grid_y, grid_z);

global cube_v;

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

function scale_cube(scale)
  global cube_v;

  aux_cube = scale*cube_v'
  cube_v = aux_cube'
  evalin('base','cube_v=cube_v;');
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

cube_faces = [
  1 2 6 5;
  2 3 7 6;
  3 4 8 7;
  4 1 5 8;
  1 2 3 4;
  5 6 7 8
];

define_cube(2.5)

#scale = [2 0 0; 0 2 0; 0 0 2]
#scale_cube(scale)
#translate_cube(4, 4, 4);

plot_cube(cube_v)
xlabel('x'), ylabel('y'), zlabel('z')
view(3)
axis vis3d
