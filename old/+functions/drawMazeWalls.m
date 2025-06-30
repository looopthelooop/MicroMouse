function drawMazeWalls(walls)
% Draws maze walls aligned with imagesc grid

[N, ~, ~] = size(walls);
hold on;

for i = 1:N
    for j = 1:N
        x = j;
        y = i;
        if walls(i,j,1) % North
            plot([x-0.5 x+0.5], [y-0.5 y-0.5], 'k', 'LineWidth', 2);
        end
        if walls(i,j,2) % East
            plot([x+0.5 x+0.5], [y-0.5 y+0.5], 'k', 'LineWidth', 2);
        end
        if walls(i,j,3) % South
            plot([x-0.5 x+0.5], [y+0.5 y+0.5], 'k', 'LineWidth', 2);
        end
        if walls(i,j,4) % West
            plot([x-0.5 x-0.5], [y-0.5 y+0.5], 'k', 'LineWidth', 2);
        end
    end
end
hold off;
end
