function scan(imname, path)
    if nargin == 1
        path = '../images/gzlz_matlab_DIP/images/dipum_images_ch02/';
    end
    impath = [path imname];
    image = imread(impath);

    figure;
    imshow(image);

    disp('Press any Key to continue:');
    pause;

    figure;
    line = 1;
    inc = 20;
    [r c] = size(image);
    while line < r - inc
        line = line + inc;
        ln = image(line,:);

        plot( ln );

        disp('Any key for next pic:');
        pause;
    end

    close figure 1;
    close figure 2;
end