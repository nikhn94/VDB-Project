% B.Shyrokau
% b.shyrokau@tudelft.nl
% Intelligent Vehicles & Cognitive Robotics
% Department of Cognitive Robotics
% Faculty of Mechanical, Maritime and Materials Engineering
% Delft University of Technology, The Netherlands

%% Cleaning
clc;clear;close all;
%%%

% Vehicle parameters
par.mass = 450;          % quarter car mass, kg
par.Iw = 1.2;            % inertia of the wheel, kg*m2
par.Reff = 0.305;        % wheel effective radius, m
par.g = 9.81;           
par.Pres2Moment = 11.25; % convertion from brake pressure to brake torque
par.max_pressure = 160;  % max. brake pressure, bar

% Maneuver settings
par.V0 = 120/3.6;        % Initial speed, m/s
par.Vmin = 10 / 3.6;      % Minimal speed to stop simulation, m/s
par.friction = 0.6;      % Friction coefficient [-]

Kref = 0.1;
%%
load('sim.mat');
%Simout = sim('LQR_test.slx', 'StartTime','0','StopTime','10');
%%
figure(1);
plot(Simout.wheel_torque.Time, Simout.wheel_torque.Data);
grid on;
xlabel('Time [s]');
ylabel('Torque [Nm]');
set(gca,'LineWidth',2,'FontSize',15, 'YColor', 'k','XMinorTick','on');
set(findall(gca, 'Type', 'Line'),'LineWidth',2);
title('Wheel torque');

%%
% wheel speeg & chasis speed
figure(2);
plot(Simout.whspd.Time, Simout.whspd.Data);
hold on;
plot(Simout.whspd.Time, Simout.vel.Data);
hold off;
xlabel('time [s]');
ylabel('Velocity [m/s]');
legend('Wheel speed','Chassis velocity');
set(gca,'LineWidth',2,'FontSize',15, 'YColor', 'k','XMinorTick','on');
set(findall(gca, 'Type', 'Line'),'LineWidth',2);
grid on;
title('Wheel and Chassis velocity');

