%false position or regula false method
function [c,err,yc]=regula(f,a,b,delta,epsilon,max1)
%Input         -- f is the function input as astring 'f'
%                 --a and b are the endpoints of the left and right
%                --delta is the tolerance for the zero
%               --epsilon is the torlerance for the value of f at the zero
%               --max1 is the maximum number of iterations
%Output     --c is the zero
%                --yc=f(c)
%               --err is the error estimate for c
ya=feval(f,a);
yb=feval(f,b);
if ya*yb>0,
disp('there has a problem errored:f(a)*f(b)>0 ');
end
for k=1:max1
    dx=yb*(b-a)/(yb-ya);
    c=b-dx;
    ac=c-a;
    yc=feval(f,c);
    if yc==0
       break;
    elseif yb*yc>0
        b=c;
        yb=yc;
    else
        a=c;
        ya=yc;
    end
    dx=min(abs(dx),ac);
    if abs(dx)<delta,break,end
    if abs(yc)<epsilon,break,end
end
c;
err=abs(b-a)/2;
yc=feval(f,c);
