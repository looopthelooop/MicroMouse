function dir = getNextDirection(maze, walls, pos)
i = pos(1); j = pos(2);
N = size(maze, 1);
minVal = inf;
dir = 0;

moves = [-1 0; 0 1; 1 0; 0 -1];  % N E S W
for d = 1:4
    ni = i + moves(d,1);
    nj = j + moves(d,2);
    if ni < 1 || nj < 1 || ni > N || nj > N, continue; end
    if walls(i,j,d), continue; end
    if maze(ni,nj) < minVal
        minVal = maze(ni,nj);
        dir = d;
    end
end

if dir == 0
    warning("No valid direction from position [%d, %d]", i, j);
end
end
