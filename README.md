#  SCE
####   outout      file    Name        input
####   double      a11     mass        ([heights], [radii], [densities]) 
####   double      a12     resistance  ([heights], [radii], [densities], [resistances])
####   [double]    a21     Gauß        (#of_variables, [row1;row2])
   exp.:
			6x+12y=30
			3x+ 3y= 9
		[a1,a2]=a21(2,[6,12,30;3,3,9])
			a1 = 1
			a2 = 2
   
####   [double]    a22     Cramer      (#of_variables, [row1;row2])
   exp.:
			6x+12y=30
			3x+ 3y= 9
		[a1,a2]=a21(2,[6,12,30;3,3,9])
			a1 = 1
			a2 = 2
   
####   double      a31     fixed-point ("func_name", start, limit)
   exp.:
		function y=fixed(x)
		y=(x+10)^(1/4);
		end
		a31("fixed",2,100)
		ans=1.8556 
   
####   double      a32     bisection   ("func_name", start, end, limit)
   exp.:
		function y=func(x)
		y=(x^4-x-10);
		end
		a32("func",0,3,100)
		ans=1.8556   
   
####   double      a33     newton      ("func_name","func_derv_name", start, limit)
   exp.:
		function y=func(x)
		y=(x^4-x-10);
		end
		function y=func_der(x)
		y=4*x^3-1;
		end
		a33("func","func_der",2,100)
		ans=1.8556  
   
####   [[double],   a411    poly-intper (#of_variables, increments, [x] , [y])
   [double]]
   exp.:
		[a1,a2]=a411(5,0.1,[1,2,3,4,5],[34,22,45,56,66])
       a1 = 1.0000   1.1000   1.2000   1.3000   1.4000   1.5000   1.6000   1.7000   1.8000   1.9000   2.0000   2.1000   2.2000   2.3000   2.4000   2.5000   2.6000   2.7000   2.8000   2.9000   3.0000   3.1000   3.2000   3.3000   3.4000   3.5000   3.6000   3.7000   3.8000   3.9000   4.0000
       a2 = 45.000   38.312   32.856   28.544   25.288   23.000   21.592   20.976   21.064   21.768   23.000   24.672   26.696   28.984   31.448   34.000   36.552   39.016   41.304   43.328   45.000   46.232   46.936   47.024   46.408   45.000   42.712   39.456   35.144   29.688   23.000
   
####   [[double],   a412    lin-intper  (#of_variables, increments, [x] , [y])
   [double]] 
                function seems unstable
   
####   double      a542     optim.      ("func_name", x, y, inc)
   exp.:
		function z=func(x,y)
		z=-(x*x + y*y);
		end
		a542("func",-2,-2, 0.1)  
		ans=6.3838e-016
 
####   [double]    a611     diff       (#num_of_points, [a], [b])
   
 ####  [double]    a612     central-diff (#num_of_points, [a], [b])  
   exp.:
	    a=[0, 5, 10, 15, 20 ]
	    b=[1, 0.8811, 0.7366, 0.5430, 0.1698]
	    a612(5,a,b)
       ans= -0.023780  -0.026340  -0.033810  -0.019360  -0.074640 
   
 ####  double      a621    trap-integ.  ("function", interval_start, interval_end, precision)
   exp.:	
       a621("sin",0,pi/2,0.000001)
		ans = 1.0000 
   
 ####  double      a622    quad-integ.  ("function", interval_start, interval_end, precision)
   exp.:	
       a622("sin",0,pi/2,0.000001)
		ans = 1.0000 
  
  #### [[double],   a752    sim         (t0, t_end, x0)
   [double]]  
   exp.:	[a1,a2]=a752(0,10,100)
		a1 = 0    1    2    3    4    5    6    7    8    9   10
       a2 = 100.000    60.000    40.000    30.000    25.000    22.500    21.250    20.625    20.312    20.156    20.078  
   
