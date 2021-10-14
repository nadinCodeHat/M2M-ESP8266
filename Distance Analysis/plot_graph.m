data = csvread('rssi_data.csv',4); % Read the data

distance = data(:,1);
rssi = data(:,4);

yl = ylim;
plot(rssi, distance,'-x');
xlabel('RSSI (dBm)');
ylabel('Distance (m)');
title('Distance vs RSSI');