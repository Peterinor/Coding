%----------------分段线性变换-----------------
%----------------分段不连续的情况--------------
%	+
%  / \
%	|                    .
%	|                  .  恒等线
%	|                .
%	|              .
%	|            .
%	|          .
%	|        . |
%	|      .   |
%	|    .-----|
%	|  .
%	|------------------------->
%        x11   x22
%	这样的话，可以随意的改变某个亮度范围内的像素点的表现形式，
%	比如，我现在想完全抑制亮度值位于0～50之间的像素点，也就是让他变成0
%	则，我们这样设置X，Y， X = [ 0 50 ]; Y = [ 0 0 ];
%	同样的，完全增强200～250之间的值，则X = [ 200 250 ]; Y = [ 255 255 ];
%
%	此函数的功能不止如此，还有其他很多作用，比如实现 （P69作业--冈萨雷斯--数字图像处理（第二版））
%	很方便，只需令 X = [ 0 127 ; 129 255 ]; Y = [ 0 0 ; 255 255 ];
%	同样的方法抽取其他位平面一样方便
%
%
function subsection_fun_s( imname, X, Y )

	clc;

	image = imread(imname);
	figure(101);
	imshow(image);

	%获取点数 = 分段数 + 1
	%num = size(X,1);
	%计算斜率
	K = cal_slopt(X,Y);
	%生成曲线
	generate_line(X, Y);
	
	%处理图像,
	imtmp = double(image);
	n = size(K,2);
	i = 1;
	while i < n + 1
		%这里开闭其实没什么影响，只是在提取第0位平面是需要闭合，建议闭合
		index = find( ( imtmp >= X(i,1) ).*( imtmp <= X(i,2) ));
		imtmp(index) = K(i)*imtmp(index) - K(i)*X(i,1) + Y(i,1);
		i = i + 1;
	end;

	figure(102);
	imshow(uint8(imtmp));

	disp('Any key to Exit:');
	pause;

	close figure 100;
	close figure 101;
	close figure 102;

	clc;
end

%生成曲线
function generate_line( X , Y )
	%生成曲线
	ml_t = '-';	%主线线型
	sl_t = 'r-';	%辅线线型
	i = 1;
	num = size(X,1);
	figure(100);
	%plot( [1:255],[1:255], sl_t );
	hold on;
	plot( [0 X(i,i)], [0 X(i,i)], ml_t );
	while i < num+1
		plot( X(i,:), Y(i,:), ml_t );		%主线
		%辅助线
		plot( [X(i,1) X(i,1)], [Y(i,1) X(i,1)], sl_t );
		plot( [X(i,2) X(i,2)], [Y(i,2) X(i,2)], sl_t );
		%恒等线
		if i < num
			plot( [X(i,2) X(i+1,1)], [X(i,2) X(i+1,1)], ml_t );
		end;
		i = i + 1;
	end;
	plot( [255 X(i-1,i-1)], [255 X(i-1,i-1)], ml_t );
	axis([0, 256, 0, 256]);
	box on;
	grid on;

end



function K = cal_slopt( X , Y )
	num = size(X,1);
	K = zeros(1,num-1);
	i = 1;
	while i < num + 1
		if X(i,2) ~= X(i,1)
			K(i) = ( Y(i,2)-Y(i,1) ) / ( X(i,2) - X(i,1) );
		else 	%切记考虑这种情形
			K(i) = 0;
		end;
		i = i + 1;
	end;
end





