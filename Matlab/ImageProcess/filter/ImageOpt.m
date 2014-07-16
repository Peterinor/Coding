
clc;

file_name = '../images/test.jpg';

image = imread(file_name);

image_info = imfinfo(file_name);

disp('Image width:'),disp(image_info.Width);
disp('Image Height:'),disp(image_info.Height);
disp('BitDepth:'), disp(image_info.BitDepth);

%also work 
[height, width] = size(image);

bytes = image_info.Width*image_info.Height*image_info.BitDepth / 8;
disp('Bytes in the image is:'), disp(bytes);

compression_ratio = bytes / image_info.FileSize;
disp('Compression_ration:'), disp(compression_ratio);