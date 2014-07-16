%	由确定的点生成可共line函数使用的点坐标X，Y
%	
%	输入参数中，X为各段直线的起点，
%	K为对应段斜率
%
function [X Y K] = polyline( X , K , level )
	if nargin < 2
		disp('Argments Erro');
		return;
	end;
	if nargin == 2
		level = 255;
	end;
	n = min(size(X,2),size(K,2));
	X = [0 X level];
	Y = 1:(n+2);
	if K(1) > 0 
		Y(1) = 0;
		Y(n+2) = level;
	else 
		Y(1) = 255;
		Y(n+2) = 0;
	end;
	i = 2;
	while i < n+2
		Y(i) = K(i-1) * ( X(i) - X(i-1) ) + Y(i-1);
		i = i + 1;
	end;
	kl = ( Y(n+2) - Y(n+1) ) / ( X(n+2) - X(n+1) );
	K = [K kl];

	%line(X,Y);

end
