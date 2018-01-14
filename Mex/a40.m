% function accepts 1 double and 1 double matrix (#of_variables, [row1;row2])
% each row1 contains #of_variables+1 elements
% returns solution vector
% outputs the function
% bsp.:
%			6x+12y=30
%			3x+ 3y= 9
%		a21(2,[6,12,30;3,3,9]);
%			2*x^1+1				<-function
%
%				OR
%
%			6x+12y=30
%			3x+ 3y= 9
%		[a1,a2]=a21(2,[6,12,30;3,3,9])
%			2*x^1+1				<-function
%			a1 = 1				<-factors of x^...
%			a2 = 2