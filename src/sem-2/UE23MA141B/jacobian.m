pkg load symbolic

% 1. If u = xyz; v=y^2; w=x+z then eval Jacobian J
syms x y z;
J = jacobian([x*y*z, y^2, x+z], [x,y,z])
d = det(J)

% If u = x^2−2y, v = x+y+z, w = x−2y+3z, then evaluate the Jacobian J
syms x y z;
J = jacobian([x^2-2*y, x+y+z, x-2*y+3*z], [x, y, z])
d = det(J)

% If u = x^2 − 2y^2, v = 2x^2 − y^2; where x = rcos(𝜃), y = rsin(𝜃), then evaluate the Jacobian J.
syms x y r theta;
x = r*cos(theta);
y = r*sin(theta);
J = jacobian([x^2-2*y^2, 2*x^2-y^2 ], [r, theta])
d = det(J)
simplify(d)

% If 𝑢 = 𝑥 2 − 𝑦 2 , 𝑣 = 2𝑥𝑦, where 𝑥 = 𝑟𝑐𝑜𝑠𝜃, 𝑦 = 𝑟𝑠𝑖𝑛𝜃, then evaluate the Jacobian J.
syms x y r theta;
x = r*cos(theta);
y = r*sin(theta);
J = jacobian([x^2 - y^2, 2*x*y], [r, theta])
d = det(J)
simplify(d)


% If x = u(1 − v), y = uv; prove that JJ′ = 1
% 1. Compute the Jacobian matrix JJ and its inverse.
% 2. Multiply JJ by its inverse, which should yield the identity matrix.
% 3. Calculate the determinant of the product J⋅J′J⋅J′, which should be 1.

syms u v;
J = jacobian([u*(1 - v), u*v], [u, v])
inv(J)
J*inv(J)
det(J*inv(J))
