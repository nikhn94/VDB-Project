clear all;
close all;
clc;

%% import data
data = cell(1,6);

files = {'WO_Controller_1mu_Straight.CSV', ...
    'WO_Controller_Straight.CSV', ...
    'WO_Controller_mu_split.CSV', ...
    'W_Controller_1mu_Straight.CSV', ...
    'W_Controller_Straight.CSV', ...
    'W_Controller_mu_split.CSV'};

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
    axis([10 16 -5 40]);

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
    axis([10 16 -5 40]);
    ax = gca;
    ax.XTick = 10:2:16;
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

    subplot(2,3,i);
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
    axis([10 16 -5 40]);

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
    axis([10 16 -5 40]);
    ax = gca;
    ax.XTick = 10:2:16;
    
end