%
%	我们知道，数字图像是由一些列的点，也就是像素所组成的，
%	所以，所以，所谓的数字图像处理，实际上就是对图像中的
%	单独像素的处理，所以，我们可以得出如下的变换关系式：
%	g(x,y) = T[f(x,y)]   (*)
%	其中f为原图像，g为处理之后的图像，(x,y)为变换点位置
%
%
%	----------------幂次变换-----------------
%

clc;

imname = '../images/ch03/Fig3.09(a).jpg';
%im
name = '../images/gzlz_matlab_DIP/images/dipum_images_ch03/Fig0306(a)(bone-scan-GE).tif';

imname = input('Input the name of the image , in path ../images :');

imname = ['../images/' imname];

image = imread(imname);
figure(101);
imshow(image);

%{
g = c * x ^ r;
%}
%生成曲线
x = [0 : 255];
r = input('Input the r: r=');
c = 255/(255^r);
figure(100);
plot(x,c*x.^r,'-r');
hold on
%处理图像,
r1 = c * (double(image)).^r;
r1 = im2uint8(mat2gray(r1));
figure(102);
imshow(r1);


disp('Any key to Exit:');
pause;


%close figure 100;
close figure 101;
close figure 102;


 clc;

