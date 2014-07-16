%
%	我们知道，数字图像是由一些列的点，也就是像素所组成的，
%	所以，所以，所谓的数字图像处理，实际上就是对图像中的
%	单独像素的处理，所以，我们可以得出如下的变换关系式：
%	g(x,y) = T[f(x,y)]   (*)
%	其中f为原图像，g为处理之后的图像，(x,y)为变换点位置
%
%
%----------------对数变换------------------------
%

clc;

imname = '../images/bw.jpg';
%imname = '../images/gzlz_matlab_DIP/images/dipum_images_ch03/Fig0303(a)(breast).tif';

image = imread(imname);
figure(101);
imshow(image);

%{
g = c * log( 1 + f );
%}
%生成曲线
c = 255/log(256);
x1 = [0 : 255];
figure(100);
plot(x1,c*log(1+x1),'-r');
%处理图像,
r1 = c * log(1+double(image));
r1 = uint8(r1);	%--the same with the statement bellow
%r1 = im2uint8(mat2gray(r1));
figure(102);
imshow(r1);


disp('Any key to Exit:');
pause;

close figure 100;
close figure 101;
close figure 102;

 clc;

