%filter functions

function result = weightfilter_1( imname, type, weight )
%校验参数
    argc = nargin;
    if( argc == 0 )         
        imname = input('Input the name of the Image ot filter:');
        type = input('Input the type of filter:');
        weight = input('Input the weight of self pixel:');
    elseif( argc == 1 )
        type = input('Input the type of filter:');
        weight = input('Input the weight of self pixel:');
    elseif( argc == 2 )
        weight = input('Input the weight of self pixel:');
    end
 
    image = imread(imname);
    
    %滤波前
    figure(100);
    imshow(image);

    disp('Press Any Key to Continue...');
    pause;
    
    %滤波
    w = weight;
    result = imread(imname);
    switch( type )
        case {1,'-'};
            lrw = (1-w) / 2;
            result = lrw * circshift(image,[0,-1]) + w * image + lrw * circshift(image,[0,1]);
        case {2,'+'}; 
            lrw = (1-w) / 4;
            result =   lrw * circshift(image,[0,-1]) ...
                     + lrw * circshift(image,[-1,0]) + w * image + lrw * circshift(image,[0,1]) ...
                     + lrw * circshift(image,[1,0]);
        case {3,'*'};
            lrw = (1-w) / 12;   %
            cnw = 2 * lrw;      % the corner weight
            result =   cnw * circshift(image,[-1,-1]) + lrw * circshift(image,[-1,0]) + cnw * circshift(image,[-1,1]) ...
                     + lrw * circshift(image,[0,-1]) + w * image + lrw * circshift(image,[0,1]) ...
                     + cnw * circshift(image,[1,-1]) + lrw * circshift(image,[1,0]) + cnw * circshift(image,[1,1]);
    end
    
    %滤波后
    figure(101);
    imshow(result);
    
    disp('Press Any Key to Exit:');
    pause;

    close figure 100;
    close figure 101;
    
end