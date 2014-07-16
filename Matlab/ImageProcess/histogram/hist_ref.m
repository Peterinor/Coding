%  数字图像处理程序作业
%  本程序能将JPG格式的彩色图像文件灰度化并进行直方图均衡
%
%  输入文件：PicSample.jpg     待处理图像
%  输出文件：PicSampleGray.bmp 灰度化后图像
%           PicEqual.bmp      均衡化后图像
%
%  输出图形窗口说明
%  figure NO 1                待处理彩色图像
%  figure NO 2                灰度化后图像
%  figure NO 3                直方图
%  figure NO 4                均衡化后直方图
%  figure NO 5                灰度变化曲线
%  figure NO 6                均衡化后图像
%  1， 处理的图片名字要为 PicSample.jpg
%  2， 程序每次运行时会先清空workspace
%  作者;archiless lorder

clear all
%一，图像的预处理，读入彩色图像将其灰度化
PS=imread('PicSample.jpg');                %读入JPG彩色图像文件
imshow(PS)                                 %显示出来 figure NO 1
title('输入的彩色JPG图像')
imwrite(rgb2gray(PS),'PicSampleGray.bmp'); %将彩色图片灰度化并保存
PS=rgb2gray(PS);                           %灰度化后的数据存入数组
figure,imshow(PS)                          %显示灰度化后的图像，也是均衡化前的样品 figure NO 2
title('灰度化后的图像')

%二，绘制直方图
[m,n]=size(PS);                            %测量图像尺寸参数
GP=zeros(1,256);                           %预创建存放灰度出现概率的向量
for k=0:255     
	GP(k+1)=length(find(PS==k))/(m*n);     %计算每级灰度出现的概率，将其存入GP中相应位置
end
figure,bar(0:255,GP,'g')                   %绘制直方图 figure NO 3
title('原图像直方图')
xlabel('灰度值')
ylabel('出现概率')

%三，直方图均衡化
S1=zeros(1,256);
for i=1:256     
	for j=1:i         
		S1(i)=GP(j)+S1(i);                %计算Sk     
	end
end  
S2=round(S1*256);                         %将Sk归到相近级的灰度
for i=1:256     
	GPeq(i)=sum(GP(find(S2==i)));          %计算现有每个灰度级出现的概率
end
figure,bar(0:255,GPeq,'b')                 %显示均衡化后的直方图 figure NO 4
title('均衡化后的直方图')
xlabel('灰度值')
ylabel('出现概率')
figure,plot(0:255,S2,'r')                  %显示灰度变化曲线 figure NO 5
legend('灰度变化曲线')
xlabel('原图像灰度级')
ylabel('均衡化后灰度级')

%四，图像均衡化
PA=PS;
for i=0:255     PA(find(PS==i))=S2(i+1);               %将各个像素归一化后的灰度值赋给这个像素
end
figure,imshow(PA)                          %显示均衡化后的图像 figure NO 6
title('均衡化后图像')
imwrite(PA,'PicEqual.bmp');
