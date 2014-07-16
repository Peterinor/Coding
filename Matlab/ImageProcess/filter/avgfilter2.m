%{
一种平均值滤波，pixel[i][j]=( pixel[i-1][j-1] + pixel[i-1][j] + pixel[i-1][j+1] 
                         + pixel[i][j-1] + pixel[i][j] + pixel[i][j+1]
                         + pixel[i+1][j-1] + pixel[i+1][j] + pixel[i+1][j+1] ) / 9
+ + +
+ o +
+ + +

%}

clc;
%clear;

image = imread('../iamges/bw.jpg');

%滤波前
figure;
imshow(image);

%pause(1);

avr = 9;
%滤波
result = ( circshift(image,[-1,-1]) / avr + circshift(image,[-1,0]) / avr + circshift(image,[-1,1]) / avr ...
         + circshift(image,[0,-1]) / avr + image / avr + circshift(image,[0,1]) / avr ...
         + circshift(image,[1,-1]) / avr + circshift(image,[1,0]) / avr + circshift(image,[1,1]) / avr );

%滤波后
figure;
imshow(result);

pause(10);

close figure 1;
close figure 2;
