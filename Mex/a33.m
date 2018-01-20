% function accepts 2 strings, 1 double and the number of iterations 
%		a31("func_name","func_derv_name", start, limit)
% functions must be in appropriate form for newton
%
%exp.:
%		function y=func(x)
%		y=(x^4-x-10);
%		end
%
%		function y=func_der(x)
%		y=4*x^3-1;
%		end
%
%		a33("func","func_der",2,100)
%		ans=1.8556