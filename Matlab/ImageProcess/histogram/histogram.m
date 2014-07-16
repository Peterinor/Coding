%
%	To draw the histogram of a image named imname
%	绘制图片imname的直方图
%

function image = histogram( imname, ~ )
	image = imread(imname);
	if size(image,3) > 1	%RGB
		image = rgb2gray(image);
	end

	[height, width] = size(image);

	hist = zeros(1,256);
	for i = 0 : 255
		hist(i+1) = length( find( image == i ) );
	end
	figure,plot(hist);
	figure,bar(hist);

end

