function drawMazeWalls(walls)
[N, ~, ~] = size(walls);
hold on;
for i = 1:N
    for j = 1:N
        x = j - 1; y = i - 1;
        if walls(i,j,1)  % North
            plot([x, x+1], [y+1, y+1], 'k', 'LineWidth', 2)
        end
        if walls(i,j,2)  % East
            plot([x+1, x+1], [y, y+1], 'k', 'LineWidth', 2)
        end
        if walls(i,j,3)  % South
            plot([x, x+1], [y, y], 'k', 'LineWidth', 2)
        end
        if walls(i,j,4)  % West
            plot([x, x], [y, y+1], 'k', 'LineWidth', 2)
        end
    end
end
hold off;
end
