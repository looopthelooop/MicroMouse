clc; clear all; close all;
import functions.*

N = 8;
start = [1,1];
goal = [3,5];

maze = inf(N);
maze(goal(1), goal(2)) = 0;

walls = false(N, N, 4);
walls(1, :, 1)   = true;
walls(:, N, 2)   = true;
walls(N, :, 3)   = true;
walls(:, 1, 4)   = true;

maze = floodFill(maze, walls, goal);

% Pathfinding
pos = start;
path = pos;

while ~isequal(pos, goal)
    d = getNextDirection(maze, walls, pos);
    move = [-1 0; 0 1; 1 0; 0 -1];  % N E S W
    pos = pos + move(d,:);
    path(end+1,:) = pos;
end

disp(path)
imagesc(maze); axis equal tight; colorbar; hold on
plot(path(:,2), path(:,1), 'w.-', 'LineWidth', 2)
