%{
一种平均值滤波，pixel[i][j]=( pixel[i][j-1] + pixel[i-1][j] + pixel[i][j] + pixel[i][j+1] + pixel[i+1][j] ) / 5
  +
+ o +
  +
%}

clc;
%clear;

image = imread('../images/me.jpg');

%滤波前
figure;
imshow(image);

pause(1);

%滤波
result = ( circshift(image,[0,-1]) / 5 ...
         + circshift(image,[-1,0]) / 5 + image / 5 + circshift(image,[0,1]) / 5 ...
         + circshift(image,[1,0]) / 5 );

%滤波后
figure;
imshow(result);

pause(10);

close figure 1;
close figure 2;
