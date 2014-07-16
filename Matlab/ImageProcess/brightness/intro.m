%{
我们知道，数字图像是由一些列的点，也就是像素所组成的，
所以，所以，所谓的数字图像处理，实际上就是对图像中的
单独像素的处理，所以，我们可以得出如下的变换关系式：
g(x,y) = T[f(x,y)]   (*)
其中f为原图像，g为处理之后的图像，(x,y)为变换点位置
%}


%{
-----------------------------图像调整----------------------
%}
clc;

imname = '../images/bw.jpg';
%imname = '../images/gzlz_matlab_DIP/images/dipum_images_ch03/Fig0303(a)(breast).tif';

image = imread(imname);
figure(101);
imshow(image);
disp('Any key to continue:');
pause;


%相当与imcomplement()
r1 = imadjust(image,[0 1],[1,0]);
figure(102);
imshow(r1);
disp('Any key to continue:');
pause;


% imcomplement()的一种实现
r2 = 255 - image;
figure(103);
imshow(r2);
disp('Any key to continue:');
pause;

r3 = imcomplement(image);
figure(104);
imshow(r3);
disp('Any key to Exit:');
pause;

close figure 101;
close figure 102;
close figure 103;
close figure 104;

 clc;

