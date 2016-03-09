% Heun �㷨�ĳ���
function H = heun(f,a,b,ya,M)
% ���÷�����
%         H = heun(f,a,b,ya,M)
%
% ����: 
%     -f �� y'(�� y �ĵ���) ������ʽΪ �ַ���
%     -a �� b �����ұ߽�
%     -ya �ǳ�ʼֵ
%     -M ����Ҫ�����Ĵ���
% ���:
%     -H = [T' Y']��T �� Y �ֱ�Ϊ tn �� yn ���ɵĵ�������
%
% ����������
h = (b-a)/M;
% ���� 1*(M+1) ��ȫ 0 ����
% �൱�ڿ��ٿռ䣬���ڴ�� tn �� yn
T = zeros(1,M+1);
Y = zeros(1,M+1);
% ʹ�� h ���� tn
T = a:h:b;
% ����ֵ
Y(1) = ya;
% ʹ��ѭ���ṹ������ yn
for j = 1:M
    k1 = feval(f,T(j),Y(j));
    k2 = feval(f,T(j+1),Y(j)+h*k1);
    Y(j+1) = Y(j)+(h/2)*(k1+k2);
end
% ������ս���������Ϊ�µ� (M+1)*2 ����
H = [T' Y'];
end