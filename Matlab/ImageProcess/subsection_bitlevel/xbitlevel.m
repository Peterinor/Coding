%
%	bit 7
%	0xxx xxxx   128    1xxx xxxx
%	X = [0 127; 129 255];   Y = [0 0; 255 255]
%	
%	bit 6
%	00xx xxxx   64   01xx xxxx   128   10xx xxxx   192  11xx xxxx
%	X = [0 63; 65 127; 129 191; 193 255]
%	Y = [0 0; 255 255; 0 0; 255 255]
%
%	令为，第0位平面很特殊，提取的时候只需辨认像素值的奇偶即可
%
%	其实所谓第i位平面，就是看8为中，这一个位的变化产生的图像变化
%	也就是说，只需要分别这一为产生的数据即可，为0则该像素在第i位
%	平面上没有映射，则提取时只需将这个像素清零既可（对于二值提取，
%	当然，其实位平面提取结果也只有二值图像是最贴切的描述），同理，
%	当像素值中这一位为1时，说明这个像素在位平面上有映射，置1即可。
%
%	简单的使用已经实现的函数subsection_fun_r()可以实现
%
%
%	算法思路：
%		循环调用subsection_fun_r(),不断的对返回值处理，知道处理完所有分段
%		第i位平面共有 n = 2^8/2^i = 2^(8-i)个分段，每段大小为256 / n
%
%
function resultimage = xbitlevel( imname, level, all )
	
	image = imread(imname);

	dn = 2^(8-level);
	dsize = 256 / dn;
	for i = 1 : dn
		image = subsection_fun_r(image, [i-1 i]*dsize - [0 1], [ (1 + (-1)^i)/2 (1 + (-1)^i)/2 ]*255);
	end;

	resultimage = image;

end

%{
提取全部位平面
for i = 7 : -1 : 0
	figure,imshow(xbitlevel('../images/bw.jpg',i));
end
%}


