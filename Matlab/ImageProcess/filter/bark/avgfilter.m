%{
一种平均值滤波，pixel[i][j]=( pixel[i][j-1] + pixel[i][j] + pixel[i][j+1] )/3
%}

clc;
%clear;

image = imread('./bw.jpg');

%滤波前
figure;
imshow(image);

pause(1);


%{
col = 1;

width = numel( image(1:1,1:end) );
hight = numel( image(1:end,1:1) );

result = zeros(hight,width);
%result = zeros(width,hight);
while col < width + 1
   index = (col-1)*hight+1:col*hight;
   ln = image(1:end,col:col);
   result(index) = ( circshift(ln,[-1,0]) / 3 + ln / 3 + circshift(ln,[1,0]) / 3 ) ;
   %result(1:end,col:col)
   col = col + 1;
end
result(1:end,5:5)
%}

%滤波
result = ( circshift(image,[0,-1]) / 3 + image / 3 + circshift(image,[0,1]) / 3);

%滤波后
figure;
imshow(result);

pause(10);

close figure 1;
close figure 2;
