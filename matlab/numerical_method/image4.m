% 绘制不同 h 下的数值解和精确解的复合图像的程序 image4.m
% 使用两次计算出的 tn 和 yn 作图
% 精确的图像
image2;
hold on;
clear all;
% h=0.1 的序列
H=heun(@fun,0,2,1,20);
T1=H(:,1)';
Y1=H(:,2)';
% h=0.1 的图像
plot(T1,Y1,'b*');
hold on;
clear all;
% h=0.05 的序列
H=heun(@fun,0,2,1,40);
T2=H(:,1)';
Y2=H(:,2)';
% h=0.05 的图像
plot(T2,Y2,'r+');
% 重新定义标题文字
title('\bf不同h的近似解与精确解的对比图');
hold off;
fprintf('蓝色 * 表示 h=0.1\n红色 + 表示 h=0.05\n');