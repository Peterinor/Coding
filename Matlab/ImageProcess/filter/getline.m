function ln = getline(imname, line, path)
    if nargin == 2
        path = '../images/gzlz_matlab_DIP/images/dipum_images_ch02/';
    end
    impath = [path imname];
    image = imread(impath);
    
    ln = image(line,:);

end