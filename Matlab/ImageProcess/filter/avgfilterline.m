
clc;

image = imread('../images/bw.jpg');
figure;
imshow(image);

%滤波前
figure;
line = 100;
ln = image(line:line, 1:end);
plot(ln);

pause(1);

%滤波
pos = 2;
lln = ( circshift(ln,[0,-1])/3+ln/3+circshift(ln,[0,1])/3 );
%while pos < 440-1
 %   lln(pos) = ( ln(pos-1) + ln(pos) + ln(pos+1) )/3
  %  pos = pos + 1
%end

%滤波后
figure;
plot(lln);

pause(10);

close figure 1;
close figure 2;
close figure 3;
