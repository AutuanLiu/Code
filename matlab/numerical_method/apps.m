% ������ֵ������г��� apps.m
clear all;
% ���ݵĳ�ʼ��
a  = input('Enter the left bound: ');
b  = input('Enter the right bound: ');
y0 = input('Enter the initial value: ');
h  = input('Enter the increment: ');
M  = (b-a)/h;
fprintf('\nThe approximate result is as bellow:\n');
% �� tn  yn
H  = heun(@fun,a,b,y0,M);
% ��ʵֵ
t  = a:h:b;
y  = (4/3)*exp(3*t)-t-1/3;
% �� H ����һ�У����ڴ洢��ʵֵ
H(:,3) = y';
% ��ȫ�����
for k=1:(M+1)
    e(k) = abs(y(k)-H(k,2));
end
% �� H ����һ�У����ڴ洢ȫ�����
    H(:,4) = e';
% ��� tn yn ��ʵֵ ȫ�����
fprintf('\t\ttn\t\tyn\t\ty(tn)\t\terror\n');
% ��� H
H