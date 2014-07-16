%{
一种平均值滤波，pixel[i][j]=( pixel[i][j-1] + pixel[i][j] + pixel[i][j+1] ) / 3

+ o +

%}

clc;
%clear;

image = imread('../images/bw.jpg');

%滤波前
figure;
imshow(image);

pause(1);

%滤波
result = ( circshift(image,[0,-1]) / 3 + image / 3 + circshift(image,[0,1]) / 3);

%滤波后
figure;
imshow(result);

pause(10);

close figure 1;
close figure 2;
