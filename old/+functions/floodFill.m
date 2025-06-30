function maze = floodFill(maze, walls, goal)
    N = size(maze,1);
    queue = goal;  % start from goal
    while ~isempty(queue)
        current = queue(1,:);
        queue(1,:) = [];  % pop front
        
        y = current(1);
        x = current(2);
        currentDist = maze(y,x);
        
        % Directions: N, E, S, W
        directions = [-1 0; 0 1; 1 0; 0 -1];
        for d = 1:4
            ny = y + directions(d,1);
            nx = x + directions(d,2);
            
            % Check boundaries
            if ny >=1 && ny <= N && nx >= 1 && nx <= N
                % Check for wall between (y,x) and (ny,nx)
                % Wall from current cell side d
                if ~walls(y,x,d)
                    % Wall from neighbor cell opposite side
                    opposite = mod(d+1,4)+1;  % converts 1->3, 2->4, 3->1, 4->2
                    % Let's define mapping manually:
                    % N(1) <-> S(3), E(2) <-> W(4)
                    if d == 1, opp = 3; elseif d == 2, opp = 4; elseif d == 3, opp = 1; else opp = 2; end
                    if ~walls(ny,nx,opp)
                        % Check if we can update distance
                        if maze(ny,nx) > currentDist + 1
                            maze(ny,nx) = currentDist + 1;
                            queue(end+1,:) = [ny nx];
                        end
                    end
                end
            end
        end
    end
end
