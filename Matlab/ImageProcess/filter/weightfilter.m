%{
一种权重滤波，pixel[i][j]=( (1-w)/2*pixel[i][j-1] + w*pixel[i][j] + (1-w)/2*pixel[i][j+1] )

+ o +

%}

clc;
%clear;

image = imread('../iamges/bw.jpg');

%滤波前
figure;
imshow(image);

pause(1);

w = 0.5;
lrw = (1-w) / 2;

%滤波
result = lrw * circshift(image,[0,-1]) + w * image + lrw * circshift(image,[0,1]);

%滤波后
figure;
imshow(result);

pause(10);

close figure 1;
close figure 2;
