%{
我们知道，数字图像是由一些列的点，也就是像素所组成的，
所以，所以，所谓的数字图像处理，实际上就是对图像中的
单独像素的处理，所以，我们可以得出如下的变换关系式：
g(x,y) = T[f(x,y)]   (*)
其中f为原图像，g为处理之后的图像，(x,y)为变换点位置
%}
%{
----------------分段线性变换-----------------
----------------分段连续的情况
%}

clc;

imname = '../images/bw.jpg';
%imname = '../images/gzlz_matlab_DIP/images/dipum_images_ch03/Fig0306(a)(bone-scan-GE).tif';

image = imread(imname);
figure(101);
imshow(image);

%{
g = c * x ^ r;
%}

level = 255;
x = [0 : level];
X = input('Input the section point X(向量n-1): X =');
K = input('Input the section slop  K(向量n-1): K =');
%生成曲线
[X Y K] = polyline(X,K);
figure(100);
line(X,Y);

%处理图像,
imtmp = double(image);
n = size(K,2);
i = 1;
while i < n
	index = find( ( imtmp>X(i) ).*( imtmp<X(i+1) ));
	imtmp(index) = K(i)*imtmp(index) - K(i)*X(i) + Y(i);
	i = i + 1;
end

figure(102);
imshow(uint8(imtmp));


disp('Any key to Exit:');
pause;


close figure 100;
close figure 101;
close figure 102;


 clc;

