%这是一个块注释
%{
命名规则：
matlab变量名区分大小写
最多63个字符
必须一字母开头，后边可接数组字母或者下划线
不许出现标点符号
不能是matlab保留字
    for , end , while , function , if , else , elseif , switch , case , otherwise , return ,
    continue , break , try , catch , global , persistent , spmd , classdef , parfor ...
  使用iskeyword 可显示上述列表
  使用isvarname('name')验证name是否为合法matlab变量名


, ; :连接符
item = 5 , p = 9 ; x = 10
...: 续行符
a = item + p + 10 + 9 + 8 ...
    + x;

基本数学运算参看数学运算函数，其函数名与我们常用语言中的函数名相同
三角函数以弧度为单位，但是，对应的也有角度单位，cos(弧度)，cosd(角度)


Matlab 的显示模式
format  short       5位
        long        16位
        short e     5位+指数
        long e      16...
        short g     短紧缩格式
        long g      长紧缩格式
        hex         16进制浮点
        bank        2位小数
        +           正负或0
        rat         有理数近似
        debug       紧缩格式的内部存储信息

一些命令：
computer
version
ver
licenseclc


脚本文件中常会用到的命令
beep        峰鸣
disp(var)   显示结果，不显示变量名
echo on/off 控制脚本文件内容是否显示
input       提示用户输入
keyboard    中止M-file，将控制权交给键盘，按回车控制权回交给M-file
pause/pause(n) 暂停知道用户按键，或者暂停n秒
waitforbuttonpress 暂停，直到用户按下鼠标键或者键盘

%}

%Array
%{
数组的创建
//行向量
(1)
--x = [x1 x2 x3 x4...]
--x = [x1, x2, x3 ,x4...]

(2)
x = x1:xn
x = (x1:xn)
x = [x1:xn]

(3)
x = x1:dx:xn
x = (x1:dx:xn)
x = [x1:dx:xn]

(4)
x = linspace(x1, xn , num)
从x1--xn，总共num个数

(5) 
x = logspace(x1, xn, num)
从10^x1 -- 10^xn，总共num个数

//列向量
(1)行向量中的空格和逗号变成分号即可
(2)使用行向量的转置生成列向量

也就是说，元素与元素用','或者' '分隔，而行与行则用';' 或者回车分隔
multi = [ 1:5; 7:3]

//规则数组
ones
zeros
eye
rand
randn
diag
false
true
magic

//数组访问
A(r,c),这里断r，c都可以是数字或者数组
A(:,c)  A(r,:)
A(k) 这里按优先列访问，把数组排成一维


//数组处理函数
sort
find(abs(x)>1)

flipup(A)   上下翻转
fliplr(A)   左右翻转

rot90   旋转90度的整数倍

circshift(A,[r,c])

//数组大小
size(A)
size(A,i)   第i维大小
length(A)   返回行列中较大的那个
numel(A)
ndim(A)     维度



















%}