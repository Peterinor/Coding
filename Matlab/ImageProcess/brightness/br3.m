%
%	我们知道，数字图像是由一些列的点，也就是像素所组成的，
%	所以，所以，所谓的数字图像处理，实际上就是对图像中的
%	单独像素的处理，所以，我们可以得出如下的变换关系式：
%	g(x,y) = T[f(x,y)]   (*)
%	其中f为原图像，g为处理之后的图像，(x,y)为变换点位置
%
%
%--------------------S曲线变换------------------
%

clc;

imname = '../images/beauty.jpg';
%imname = '../images/gzlz_matlab_DIP/images/dipum_images_ch03/Fig0303(a)(breast).tif';
%imname = '../images/gzlz_matlab_DIP/images/dipum_images_ch03/Fig0306(a)(bone-scan-GE).tif';

image = imread(imname);
figure(101);
imshow(image);


%{
g = 1/(1 + (m/f)^a)
%}
%生成变换曲线
level = 255;
a = input('Input the 幂次: a = ');		%观察不同的a对应的输出
m = input('Input the 阈值: m = ');
if( m > 0 && m < level )
	m = m;
else 
	m = mean2(double(image));	%观察不同时候断a对应的输出
end
x2 = [1 : level];
figure(100);
plot(x2,level * 1./(1 + (m./x2).^a),'-b');
hold on;
text(m,level/2,'m = ');
text(m+15,level/2,num2str(m));
text(m,level/2-10,'a = ');
text(m+15,level/2-10,num2str(a));

%处理图像
r2 = 1./(1 + (m./double(image) + eps).^a); 
r2 = im2uint8(r2);
figure(102);
imshow(r2);

%{
-------------这里人工实现了和上面一样的算法-------------
从这里可以看出，double类型的图像，他的每一个像素值都在0~1之间的浮点数，必须将其转化为uint8才可以识别为图像
r2 = level * 1./(1 + (m./double(image) + eps).^a); 
figure(102);
imshow(uint8(r2));
%}
%{
可以发现，当a比较大时，基本上实现了把图像转换为二值图像，功能同im2bw函数
%}

disp('Any key to Exit:');
pause;

close figure 100;
close figure 101;
close figure 102;

 clc;

