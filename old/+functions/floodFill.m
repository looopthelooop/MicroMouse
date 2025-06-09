function maze = floodFill(maze, walls, goal)
% maze = floodFill(maze, walls, goal)
% goal = [row, col]

N = size(maze, 1);
queue = goal;  % start from goal cell

while ~isempty(queue)
    row = queue(1,1);
    col = queue(1,2);
    queue(1,:) = [];

    value = maze(row, col);

    % directions: [row_change, col_change]
    moves = [-1 0; 0 1; 1 0; 0 -1];  % N E S W

    for d = 1:4
        r = row + moves(d,1);
        c = col + moves(d,2);

        if r < 1 || c < 1 || r > N || c > N
            continue;  % out of bounds
        end
        if walls(row, col, d)
            continue;  % wall blocks path
        end
        if maze(r, c) > value + 1
            maze(r, c) = value + 1;
            queue(end+1, :) = [r, c];
        end
    end
end
end
