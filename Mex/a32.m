%function accepts 1 string, 2 doubles and the number of iterations 
%		a32("func_name", start, end, limit)
% function must be in appropriate form for bisection
%
%exp.:
%		function y=func(x)
%		y=(x^4-x-10);
%		end
%
%		a32("func",0,3,100)
%		ans=1.8556