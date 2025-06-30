clc; clear all; close all;
import functions.*

% Grid and start/goal setup
N = 4;
start = [1,1];
goal = [2,1];

% Initialize maze: flood-fill distances from goal
maze = inf(N);
maze(goal(1), goal(2)) = 0;

% Wall definition: walls(y, x, direction)
walls = false(N, N, 4);  % 4 directions: N E S W
walls(1,:,1) = true;     % North wall
walls(:,N,2) = true;     % East wall
walls(N,:,3) = true;     % South wall
walls(:,1,4) = true;     % West wall

% test1
% Custom internal walls (example)
% walls(1,1:2,3) = true;
% walls(1,N,3) = true;
% walls(2,N,4) = true;
% walls(2,3,2) = true;
% walls(3,1:2,2:3) = true;
% walls(N,N,4) = true;

% test2
walls(1,1:2,3) = true;
walls(1,N,3) = true;
walls(2,1,2) = true;
walls(2,N,3) = true;
walls(3,1,3) = true;
walls(3,2,2:3) = true;
walls(N,N,4) = true;

% symmetry check
for y = 1:N
    for x = 1:N
        if walls(y,x,1) && y > 1
            walls(y-1,x,3) = true;
        end
        if walls(y,x,2) && x < N
            walls(y,x+1,4) = true;
        end
        if walls(y,x,3) && y < N
            walls(y+1,x,1) = true;
        end
        if walls(y,x,4) && x > 1
            walls(y,x-1,2) = true;
        end
    end
end

% Flood fill from goal
maze = floodFill(maze, walls, goal);
disp(maze)
% Check if start is reachable
if isinf(maze(start(1), start(2)))
    error('Start point [%d, %d] is unreachable from goal!', start(1), start(2));
end

% Pathfinding
pos = start;
path = pos;
visited = false(N, N);
move = [-1 0; 0 1; 1 0; 0 -1];  % N E S W

maxSteps = N * N;  % reasonable upper limit
step = 0;

while ~isequal(pos, goal)
    if visited(pos(1), pos(2))
        error("Loop detected at [%d, %d].", pos(1), pos(2));
    end
    visited(pos(1), pos(2)) = true;

    d = getNextDirection(maze, walls, pos);
    if d == 0
        error('No valid direction from position [%d, %d]. Maze may be malformed.', pos(1), pos(2));
    end

    next = pos + move(d,:);
    path(end+1,:) = next;
    pos = next;

    step = step + 1;
    if step > maxSteps
        error('Pathfinding exceeded max steps. Infinite loop suspected.');
    end
end


% Display
figure;
imagesc(maze); axis equal tight; colorbar; hold on
plot(path(:,2), path(:,1), 'w.-', 'LineWidth', 2)
drawMazeWalls(walls);
title('Maze with Flood-Fill Values and Path');
