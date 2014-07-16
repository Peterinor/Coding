%filter functions

function weightfilter( imname, type, weight )

    image = imread(imname);
    
    %滤波前
    figure;
    imshow(image);

    %pause(1);
    
    %滤波
    w = weight;
    result = imread(imname);
    switch( type )
        case 1;
            lrw = (1-w) / 2;
            result = lrw * circshift(image,[0,-1]) + w * image + lrw * circshift(image,[0,1]);
        case 2; 
            lrw = (1-w) / 4;
            result =   lrw * circshift(image,[0,-1]) ...
                     + lrw * circshift(image,[-1,0]) + w * image + lrw * circshift(image,[0,1]) ...
                     + lrw * circshift(image,[1,0]);
        case 3;
            lrw = (1-w) / 12;   %
            cnw = 2 * lrw;      % the corner weight
            result =   cnw * circshift(image,[-1,-1]) + lrw * circshift(image,[-1,0]) + cnw * circshift(image,[-1,1]) ...
                     + lrw * circshift(image,[0,-1]) + w * image + lrw * circshift(image,[0,1]) ...
                     + cnw * circshift(image,[1,-1]) + lrw * circshift(image,[1,0]) + cnw * circshift(image,[1,1]);
    end
    
    %滤波后
    figure;
    imshow(result);

    pause;

    close figure 1;
    close figure 2;
    
end