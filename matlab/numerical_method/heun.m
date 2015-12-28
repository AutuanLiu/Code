% Heun 算法的程序
function H = heun(f,a,b,ya,M)
% 调用方法：
%         H = heun(f,a,b,ya,M)
%
% 输入: 
%     -f 是 y'(即 y 的导数) ，其形式为 字符串
%     -a 和 b 是左右边界
%     -ya 是初始值
%     -M 是需要迭代的次数
% 输出:
%     -H = [T' Y']，T 和 Y 分别为 tn 和 yn 构成的迭代序列
%
% 定义迭代间隔
h = (b-a)/M;
% 构造 1*(M+1) 的全 0 矩阵
% 相当于开辟空间，用于存放 tn 和 yn
T = zeros(1,M+1);
Y = zeros(1,M+1);
% 使用 h 计算 tn
T = a:h:b;
% 赋初值
Y(1) = ya;
% 使用循环结构，计算 yn
for j = 1:M
    k1 = feval(f,T(j),Y(j));
    k2 = feval(f,T(j+1),Y(j)+h*k1);
    Y(j+1) = Y(j)+(h/2)*(k1+k2);
end
% 获得最终结果，并组合为新的 (M+1)*2 矩阵
H = [T' Y'];
end
