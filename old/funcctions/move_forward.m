function [refL, refR] = move_forward(posL, posR)
% Move forward one cell

cell_distance = 180; % mm or encoder units
refL = posL + cell_distance;
refR = posR + cell_distance;
end
