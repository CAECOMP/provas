global pyramid_v;

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

function [] = plotPyramid(pyramidVertices)
  pyramid_f = [1 2 3;4 5 6; 7 8 9;10 11 12];
  patch('Vertices',pyramidVertices,'Faces',pyramid_f,'FaceColor','g');
endfunction

function scale_pyramid(scale)
  global pyramid_v;

  aux_pyramid = scale*pyramid_v'
  pyramid_v = aux_pyramid'
  evalin('base','pyramid_v=pyramid_v;');
endfunction


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


figure()
hold on
xlabel('x'), ylabel('y'), zlabel('z')

define_pyramid(0,0,0,3,4);
#scale = [2 0 0; 0 2 0;0 0 2]
#scale_pyramid(scale)
#translate_pyramid(-3, -3, 0)
plotPyramid(pyramid_v);

view(3);

