clear all;
close all;
clc;

%% import data
data = cell(1,6);

files = {'WO_Controller_1mu_Straight.CSV', ...
    'WO_Controller_Straight.CSV', ...
    'WO_Controller_mu_split.CSV', ...
    'PID_1mu.CSV', ...
    'W_Controller_1mu_Straight_noise.CSV', ...
    'W_Controller_Straight_noise.CSV', ...
    'W_Controller_mu_split_noise.CSV', ... 
    'PID_mu_split.CSV'};

for i = 1:size(files,2)
    data{i} = importdata(files{i});
end
%% plot
for i = 1:size(files,2)
    FL = data{i}.data(:,1)*0.32;
    FR = data{i}.data(:,2)*0.32;
    RL = data{i}.data(:,3)*0.32;
    RR = data{i}.data(:,4)*0.32;
    vel = data{i}.data(:,5);
    t  = data{i}.data(:,6);

    figure(i);
    yyaxis left;
    plot(t, FL);
    hold on;
    plot(t, FR);
    plot(t, RL);
    plot(t, RR);
    xlabel('Time [s]');
    ylabel('Wheel speed [m/s]');
    legend('FL','FR','RL','RR');
    hold off;
    grid on;
    set(gca, 'YColor', 'k');
    axis([10 18 -5 40]);

    yyaxis right;
    plot(t, vel);
    ylabel('Vehicle speed [m/s]');
    legend('FL','FR','RL','RR','Vehicle');
    set(gca,'LineWidth',2,'FontSize',15, 'YColor', 'k','XMinorTick','on');
    set(findall(gca, 'Type', 'Line'),'LineWidth',2);
    
    name = split(files{i}, '.');
    name = split(name(1), '_');
    new_name = join(name, '\_');
    title(sprintf('%s', new_name{1}));
    axis([10 18 -5 40]);
    ax = gca;
    ax.XTick = 10:2:18;
end

%% subplot
figure(80);
for i = 1:size(files,2)
    FL = data{i}.data(:,1)*0.32;
    FR = data{i}.data(:,2)*0.32;
    RL = data{i}.data(:,3)*0.32;
    RR = data{i}.data(:,4)*0.32;
    vel = data{i}.data(:,5);
    t  = data{i}.data(:,6);

    subplot(2,4,i);
    yyaxis left;
    plot(t, FL);
    hold on;
    plot(t, FR);
    plot(t, RL);
    plot(t, RR);
    xlabel('Time [s]');
    ylabel('Wheel speed [m/s]');
    legend('FL','FR','RL','RR');
    hold off;
    grid on;
    set(gca, 'YColor', 'k');
    axis([10 18 -5 40]);

    yyaxis right;
    plot(t, vel);
    ylabel('Vehicle speed [m/s]');
    legend('FL','FR','RL','RR','Vehicle');
    set(gca,'LineWidth',2,'FontSize',15, 'YColor', 'k','XMinorTick','on');
    set(findall(gca, 'Type', 'Line'),'LineWidth',2);
    
    name = split(files{i}, '.');
    name = split(name(1), '_');
    new_name = join(name, '\_');
    title(sprintf('%s', new_name{1}));
    axis([10 18 -5 40]);
    ax = gca;
    ax.XTick = 10:2:18;   
end

%% mu-comparison
% PID_1mu
FL_PID = data{4}.data(:,1)*0.32;
FR_PID = data{4}.data(:,2)*0.32;
RL_PID = data{4}.data(:,3)*0.32;
RR_PID = data{4}.data(:,4)*0.32;
% W_Controller_1mu_Straight
FL_W = data{5}.data(:,1)*0.32;
FR_W = data{5}.data(:,2)*0.32;
RL_W = data{5}.data(:,3)*0.32;
RR_W = data{5}.data(:,4)*0.32;

figure(37);

t  = data{4}.data(:,6);
plot(t, FL_PID, '-','Color', [.1 .4 .9]);
hold on;
plot(t, FR_PID, '--','Color', [.1 .4 .9]);
plot(t, RL_PID, '-.','Color', [.1 .4 .9]);
plot(t, RR_PID, ':','Color', [.1 .4 .9]);
t  = data{5}.data(:,6);
plot(t, FL_W, '-','Color', [.9 .3 .2]);
plot(t, FR_W, '--','Color', [.9 .3 .2]);
plot(t, RL_W, '-.','Color', [.9 .3 .2]);
plot(t, RR_W, ':','Color', [.9 .3 .2]);
xlabel('Time [s]');
ylabel('Wheel speed [m/s]');
legend('FL (PID)','FR (PID)','RL (PID)','RR (PID)', 'FL (LQR)','FR (LQR)','RL (LQR)','RR (LQR)');
hold off;
grid on;
axis([10 18 -5 40]);
set(gca,'LineWidth',2,'FontSize',15, 'YColor', 'k','XMinorTick','on');
set(findall(gca, 'Type', 'Line'),'LineWidth',2);
title({'LQR, PID Controller Wheel Speed ';'comparison on high friction road'});
axis([10 18 -5 40]);
ax = gca;
ax.XTick = 10:2:18;