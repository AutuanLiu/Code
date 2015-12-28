% 绘制 精确解 的图像的程序 image2.m
% 经 常数变易法 计算得到精确解为
%       y(t) = (4/3)exp(3*t)-t-1/3
%
t = 0:.00001:2;
y = (4/3)*exp(3*t)-t-1/3;
plot(t,y,'g-');
% 标签设置
% LaTeX 转义，显示粗体
title('\bf精确解的图像');
xlabel('t');
ylabel('y');
% 使用 LaTeX 转义
legend('y(t) =(4/3)e^{3t} - t - 1/3')
grid on;