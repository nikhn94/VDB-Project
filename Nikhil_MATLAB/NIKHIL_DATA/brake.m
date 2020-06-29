clear all;
close all;
clc;

%% import data
data = cell(1,3);

files = {'W_Controller_1mu_Straight_2.CSV', ...
    'W_Controller_Straight_2.CSV', ...
    'W_Controller_mu_split_2.CSV', ...
};

for i = 1:size(files,2)
    data{i} = importdata(files{i});
end
%% plot wheel and vehicle speed
for i = 1:size(files,2)
    FL = data{i}.data(:,7)*0.32;
    FR = data{i}.data(:,8)*0.32;
    RL = data{i}.data(:,9)*0.32;
    RR = data{i}.data(:,10)*0.32;
    t  = data{i}.data(:,6);

    figure(i);
    plot(t, FL);
    hold on;
    plot(t, FR);
    plot(t, RL);
    plot(t, RR);
    xlabel('Time [s]');
    ylabel('Torque [Nm]');
    legend('FL','FR','RL','RR');
    hold off;
    grid on;
    set(gca, 'YColor', 'k');

    set(gca,'LineWidth',2,'FontSize',15, 'YColor', 'k','XMinorTick','on');
    set(findall(gca, 'Type', 'Line'),'LineWidth',1.5);
    axis([0 25 -1000 2500]);
    
    name = split(files{i}, '.');
    name = split(name(1), '_');
    new_name = join(name(1:size(name,1)-1), '\_');
    title(sprintf('%s', new_name{1}));
end
