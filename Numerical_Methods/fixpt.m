%fixed points iteration
function [k,p,err,P]=fixpt(g,p0,tol,max1)
%Input      -g is the interation function input as astring 'g'
%              -p0 is the initial guess of the fixed point
%              -tol is the tolerance
%              -max1 is the maximum number of interations
%Output   -k is the number of interations that were carried out
%              -p is the approximation to the fixed point
%              --err is the error int approximation
%             --P contions the sequences{Pn}
P(1)=p0;
for k=2:max1
    P(k)=feval(g,P(k-1));
    err=abs(P(k)-P(k-1));
    relerr=err/(abs(P(k))+eps);
    p=P(k);
    if (err<tol) | (relerr<tol), break;end
end
if  k==max1
    disp('maximum number of interations exceeded');
end
P=P';
% it is nessary to input the M_file g.m as a string 'g'
    