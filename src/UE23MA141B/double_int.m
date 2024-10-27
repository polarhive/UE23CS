pkg load symbolic

fun = @(x,y) 1./(sqrt(x+y)(1+x+y).^2);
ymax = @(x) 1 -x;
q = integral2(fun,0,1,0,ymax)

fun = @(x,y) y.*sin(x)+x.*cos(y);
q = integral2(fun,-pi,2*pi,0,pi)

fun = @(x,y) x.*(x.^2+y.^2); % don't forget the (.) dot
ymax = @(x) x.^2;
q = integral2(fun,0,5,0,ymax)

fun = @(x,y) x.*y;
ymax = @(x) sqrt(x);
q=integral2(fun,0,1,0,ymax)

%polarfun = @(r,theta) r./(sqrt(r.*cos(theta)+r.*sin(theta)).*((1+r.*cos(theta)+r.*sin(theta)).^2))
%rmax = @(theta) 1./sin(theta)+cos(theta))
%q = integral2(polarfun,0,pi/2,0,rmax)

fun = @(x,y,z) x+y+z
q = integral3(fun,0,3,0,2,0,1)

fun = @(x,y,z) x.*cos(y) + x.^2.*cos(z)
xmin = -1;
xmax = 1;
ymin = @(x)-sqrt(1 - x.^2);
ymax = @(x) sqrt(1 - x.^2);
zmin = @(x,y)-sqrt(1 - x.^2 - y.^2);
zmax = @(x,y) sqrt(1 - x.^2 - y.^2);
q = integral3(fun,xmin,xmax,ymin,ymax,zmin,zmax)

