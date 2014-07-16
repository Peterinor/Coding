%
%	我们知道，数字图像是由一些列的点，也就是像素所组成的，
%	所以，所以，所谓的数字图像处理，实际上就是对图像中的
%	单独像素的处理，所以，我们可以得出如下的变换关系式：
%	g(x,y) = T[f(x,y)]   (*)
%	其中f为原图像，g为处理之后的图像，(x,y)为变换点位置
%
%
%-------------------brightness-----------------
%
%you must have excute the intro.m before this
%先执行intro.m

figure(101);
imshow(image);
disp('Any key to continue...');
pause;

r4 = imadjust(image,[0 1],[1 0.5]);
figure(102);
imshow(r4);
disp('Any key to continue...');
pause;

r5 = imadjust(image,[0 1],[0.5 1]);
figure(103);
imshow(r5);
disp('Any key to continue...');
pause;

r6 = imadjust(image,[0 1],[0.5 0.75]);
figure(104);
imshow(r6);
disp('Any key to continue...');
pause;


%等价于imshow(image,[low,high])
%截断显示
r7 = imadjust(image,[0.5 0.75],[0 1]);
figure(105);
imshow(r7);
disp('Any key to continue...');
pause;
figure(106);
imshow(image, [0.5 0.75]*255 );
disp('Any key to continue...');
pause;

r8 = imadjust(image,[],[],1);
figure(107);
imshow(r8);
disp('Any key to continue...');
pause;

%lighter
r9 = imadjust(image,[],[],0.5);
figure(108);
imshow(r9);
disp('Any key to continue...');
pause;

%darker
r10 = imadjust(image,[],[],2);
figure(109);
imshow(r10);
disp('Any key to continue...');
pause;

disp('Any key to Exit...');
pause;

%OR close all if safe
close figure 101;
close figure 102;
close figure 103;
close figure 104;
close figure 105;
close figure 106;
close figure 107;

close all;
