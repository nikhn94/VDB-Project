clear all;
close all;
clc;

%% import data
data = cell(1,6);

files = {'CSV/W_Controller_1mu_Straight_2.CSV', ...
    'CSV/W_Controller_Straight_2.CSV', ...
    'CSV/W_Controller_mu_split_2.CSV', ...
    'CSV/W_Controller_1mu_Straight_noise_2.CSV', ...
    'CSV/W_Controller_Straight_noise_2.CSV', ...
    'CSV/W_Controller_mu_split_noise_2.CSV'
};

for i = 1:size(files,2)
    data{i} = importdata(files{i});
end
%% plot wheel and vehicle speed
for i = 1:size(files,2)
    FL = data{i}.data(:,7);
    FR = data{i}.data(:,8);
    RL = data{i}.data(:,9);
    RR = data{i}.data(:,10);
    t  = data{i}.data(:,6);

    if i >= 4
        FL = data{i}.data(:,1);
        FR = data{i}.data(:,2);
        RL = data{i}.data(:,3);
        RR = data{i}.data(:,4);
        t  = data{i}.data(:,10);
    end

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
    axis([0 25 -2000 8000]);
    
    name = split(files{i}, '.');
    name = split(name(1), '_');
    name = join(name(1:size(name,1)-1), '\_');
    new_name = split(name, '/');
    title(sprintf('%s', new_name{2}));
end