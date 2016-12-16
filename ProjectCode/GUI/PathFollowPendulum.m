function [qd_1,qdot_d_1,qdotdot_d_1,qd_2,qdot_d_2,qdotdot_d_2, t] = PathFollowPendulum(x_given,y_given,theta_given,theta_1,theta_2,tf,hz)
% Kinematics With Selected Release Point
    % Kinematic Formulas:
    % dx = v0_x*t
    % dy = v0_y*t + 1/2*g*t^2

    % Units: ALL UNITS IN DEGREES, METERS, SECONDS.   
    x_given = x_given .* 0.3048;
    y_given = y_given .* 0.3048;
    % Fixed Inputs
    g = -9.81; h_frame = .7; D_basket = 0.2032;
    l_1 = 0.33; l_2 = 0.33;
    theta_1_back = 0; theta_2_back = 0;
    
    % Variables:
    h_robot = l_1.*cosd(theta_1) + l_2.*cosd(theta_1 + theta_2);
    x0_robot = l_1.*sind(theta_1) + l_2.*sind(theta_1 + theta_2);
    y0_bot = -h_robot;
    y0_hoop = -h_frame - (-(y_given + 1/2.*D_basket.*sind(theta_given)));
    dy = y0_bot - y0_hoop;
    x0_hoop = x_given - 1/2.*D_basket.*cosd(theta_given);
    dx = x0_hoop - x0_robot;

    % Solve Kinematic Formulas:
    vf = 1./cosd(theta_1 + theta_2) .* sqrt(1/2.*g.*dx.^2 .* (1./(dy-dx./tand(theta_1 + theta_2))));
    
    % Initial conditions.
    q0_tot = theta_1_back + theta_2_back;
    v0_tot = 0;
    ac0_tot = 0;
    q1_tot = theta_1 + theta_2;
    v1_tot = vf;
    ac1_tot = 1;
    
    q0_1 = theta_1_back;
    v0_1 = 0;
    ac0_1 = 0;
    q1_1 = theta_1;
    v1_1 = vf/3;
    ac1_1 = 0.25;
    
    t0 = 0;
    
    t = [t0:1/hz:tf];
    c = ones(size(t));
    M = [1 t0 t0^2 t0^3 t0^4 t0^5;...
        0 1 2*t0 3*t0^2 4*t0^3 5*t0^4;...
        0 0 2 6*t0 12*t0^2 20*t0^3;...
        1 tf tf^2 tf^3 tf^4 tf^5;...
        0 1 2*tf 3*tf^2 4*tf^3 5*tf^4;...
        0 0 2 6*tf 12*tf^2 20*tf^3];
    b_tot = [q0_tot; v0_tot; ac0_tot; q1_tot; v1_tot; ac1_tot];
    b_1 = [q0_1; v0_1; ac0_1; q1_1; v1_1; ac1_1];
    a_tot = inv(M)*b_tot;
    a_1 = inv(M)*b_1;
    
    
    qd_tot = a_tot(1).*c + a_tot(2).*t + a_tot(3).*t.^2 + a_tot(4).*t.^3 + a_tot(5).*t.^4 + a_tot(6).*t.^5;
    qdot_d_tot = a_tot(2).*c + 2*a_tot(3).*t + 3*a_tot(4).*t.^2 + 4*a_tot(5).*t.^3 + 5*a_tot(6).*t.^4;
    qdotdot_d_tot = 2*a_tot(3).*c + 6*a_tot(4).*t + 12*a_tot(5).*t.^2 + 20*a_tot(6).*t.^3;
    
    qd_1 = a_1(1).*c + a_1(2).*t + a_1(3).*t.^2 + a_1(4).*t.^3 + a_1(5).*t.^4 + a_1(6).*t.^5;
    qdot_d_1 = a_1(2).*c + 2*a_1(3).*t + 3*a_1(4).*t.^2 + 4*a_1(5).*t.^3 + 5*a_1(6).*t.^4;
    qdotdot_d_1 = 2*a_1(3).*c + 6*a_1(4).*t + 12*a_1(5).*t.^2 + 20*a_1(6).*t.^3;
    
    qd_2 = qd_tot - qd_1;
    qdot_d_2 = qdot_d_tot - qdot_d_1;
    qdotdot_d_2 = qdotdot_d_tot - qdotdot_d_1;