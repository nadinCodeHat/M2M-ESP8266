function [fitresult, gof] = createFit(RSSI, Distance)
%CREATEFIT(RSSI,DISTANCE)
%  Create a fit.
%
%  Data for 'Curve fit' fit:
%      X Input : RSSI
%      Y Output: Distance
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  See also FIT, CFIT, SFIT.

%  Auto-generated by MATLAB on 18-Oct-2021 14:23:00


%% Fit: 'Curve fit'.
[xData, yData] = prepareCurveData( RSSI, Distance );

% Set up fittype and options.
ft = fittype( 'exp1' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display = 'Off';
opts.StartPoint = [0.0336520798880578 -0.0600756600776581];

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'Curve fit' );
h = plot( fitresult, xData, yData );
legend( h, 'Distance vs. RSSI', 'Curve fit', 'Location', 'NorthEast' );
% Label axes
xlabel RSSI
ylabel Distance
grid on


