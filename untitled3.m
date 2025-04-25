% Extract Channel A
chA = squeeze(rightEncoder.signals.values(1,1,:));  % Channel A only

% Optional: Smooth (if you think it bounces)
chA = movmean(double(chA), 3) > 0.5;

% Sampling setup
fs = 1000;                           % Sampling frequency (Hz)
t = (0:length(chA)-1)' / fs;          % Time vector

% Find rising edges (0 -> 1 transitions)
risingEdges = (chA(2:end) == 1) & (chA(1:end-1) == 0);

% Create incremental position
position = [0; cumsum(risingEdges)];  % Cumulative sum of rises

% Plot
figure;
plot(t, position, 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Incremental Count (ticks)');
title('Incremental Count from Channel A Only');
grid on;
