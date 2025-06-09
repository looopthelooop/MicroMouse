function walls = updateWalls(walls, pos, sensor)
% pos = [i, j], sensor = [N E S W] logical
i = pos(1); j = pos(2);
dirVec = [-1 0; 0 1; 1 0; 0 -1];

for d = 1:4
    if sensor(d)
        walls(i,j,d) = true;
        ni = i + dirVec(d,1);
        nj = j + dirVec(d,2);
        if ni >= 1 && nj >= 1 && ni <= size(walls,1) && nj <= size(walls,2)
            opp = mod(d+1,4)+1; % opposite wall index
            walls(ni,nj,opp) = true;
        end
    end
end
end
