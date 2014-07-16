R = 1;
G = 2;
B = 3;

imname = './images/beauty.jpg';

image = imread(imname);

figure(100);
imshow(image);

depth = 8 * size(image,3);

dem = depth / 8;

i = 1;
while i < dem + 1
	figure(100 + i);
	imhist(image(:,:,i));
	i = i + 1;
end; 
