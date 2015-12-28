% 绘制 数值解 的图像的程序 image1.m
% 图形绘制依赖于之前计算过的数据，在使用此程序前请勿 clear all 
% 或者 clear H
plot(H(:,1),H(:,2),'r+');
% 标签设置
% LaTeX 转义，显示粗体
title('\bf近似解的图像');
xlabel('t');
ylabel('y');
% 使用 LaTeX 转义，使得出现下标
legend('y_{n}')
grid on;