clear all;
close all;
clc;

%% import data
data = cell(1,6);

files = {'WO_Controller_1mu_Straight_2.CSV', ...
    'WO_Controller_Straight_2.CSV', ...
    'WO_Controller_mu_split_2.CSV', ...
    'W_Controller_1mu_Straight_2.CSV', ...
    'W_Controller_Straight_2.CSV', ...
    'W_Controller_mu_split_2.CSV', ... 
};

for i = 1:size(files,2)
    data{i} = importdata(files{i});
end
%% subplot
figure(80);
for i = 1:size(files,2)
    FL = data{i}.data(:,7)*0.32;
    FR = data{i}.data(:,8)*0.32;
    RL = data{i}.data(:,9)*0.32;
    RR = data{i}.data(:,10)*0.32;
    t  = data{i}.data(:,6);

    subplot(2,3,i);
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
    set(findall(gca, 'Type', 'Line'),'LineWidth',2);
    
    name = split(files{i}, '.');
    name = split(name(1), '_');
    new_name = join(name, '\_');
    title(sprintf('%s', new_name{1}));
end