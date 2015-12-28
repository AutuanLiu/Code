% 计算数值解的运行程序 apps.m
clear all;
% 数据的初始化
a  = input('Enter the left bound: ');
b  = input('Enter the right bound: ');
y0 = input('Enter the initial value: ');
h  = input('Enter the increment: ');
M  = (b-a)/h;
fprintf('\nThe approximate result is as bellow:\n');
% 求 tn  yn
H  = heun(@fun,a,b,y0,M);
% 真实值
t  = a:h:b;
y  = (4/3)*exp(3*t)-t-1/3;
% 给 H 增加一列，用于存储真实值
H(:,3) = y';
% 求全局误差
for k=1:(M+1)
    e(k) = abs(y(k)-H(k,2));
end
% 给 H 增加一列，用于存储全局误差
    H(:,4) = e';
% 输出 tn yn 真实值 全局误差
fprintf('\t\ttn\t\tyn\t\ty(tn)\t\terror\n');
% 输出 H
H