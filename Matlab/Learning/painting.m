plot(X,Y,...)
1).当X，Y为一维向量时，分别连接（x1，y1），（x2，y2）....
2).当X，Y为二维向量时，以(X1,Y1)为起点，（X2，Y2）为终点，然后分别连接
	（x11，y11）--（x21，y21），（x12，y12）--（x22，y22）....
3).若不显式指出是向量，则画点，
	plot(3,4,'*');
	th = linspace(0,2*pi,100);
	R = 3;
	x = R*cos(th);
	y = R*sin(th);
	plot(x,y);	--画园
f).
颜色
r 、 g 、 b 、 c（青）、m（深红）、y 、k（黑）、w
线型
- 、 -- 、 -. 、 ：
点型
+ 、 o 、 * 、 . 、 x（十字） 、 s（方框） 、 d（菱形） 、 ^(正三角)、倒三角 、> 、 < 、 p（五角星） h（六角星）

axis
1)	v = axis
	v(2) = 5
	axis(v)
2)  axis([xmin,xmax,ymin,ymax])
3)	axis equal
	axis on

box on/off
grid on/off

图形注释：
xlabel
ylabel
title
text(x,y,s)
legend(s1,s2,s3....,'Location',SouthWest')
legend('boxon')
legend('boxoff')
