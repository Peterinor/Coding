%{
图像分析的一些常用函数
%}

clc;

imname = '../images/edge.tif';
%imname = '../images/gzlz_matlab_DIP/images/dipum_images_ch03/Fig0303(a)(breast).tif';

image = imread(imname);
figure(100);
imshow(image);

%{
%some problems here
imcont = imcontour(image);
figure(101);
imshow(imcont);
%}

ed1 = edge(image,'sobel');
ed2 = edge(image,'canny');
figure(102),imshow(ed1);
figure(103),imshow(ed2);

histq = histeq(image);
figure(104),imshow(histq);
figure(105),imhist(image);
figure(106),imhist(histq);

disp('Any key to Exit:');
pause;


close figure 100;
close figure 102;
close figure 103;
close figure 104;
close figure 105;
close figure 106;

 clc;

